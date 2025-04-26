#include "shop.h"
#include <iostream>
#include <iomanip>  // For formatting output (setw, setprecision, fixed, left, right)
#include <limits>   // For numeric_limits
#include <utility>  // For std::move

// --- Product Class Implementation ---

Product::Product(int id, std::string n, double p, int s)
    : id(id), name(std::move(n)), price(p), stock(s) {}

int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }

bool Product::reduceStock(int quantity) {
    if (quantity > 0 && stock >= quantity) {
        stock -= quantity;
        return true; // Sufficient stock, reduction successful
    }
    return false; // Insufficient stock or invalid quantity
}

void Product::increaseStock(int quantity) {
    if (quantity > 0) {
        stock += quantity;
    }
}

void Product::display() const {
    std::cout << "ID: " << std::setw(3) << std::right << id
              << " | Name: " << std::setw(25) << std::left << name // Increased width slightly for English names
              << " | Price: $" << std::fixed << std::setprecision(2) << std::setw(7) << std::right << price
              << " | Stock: " << std::setw(4) << std::right << stock << std::left << std::endl;
}


// --- Shop Class Implementation ---

Shop::Shop() : nextProductID(1) {}

Product* Shop::findProductInternal(int productID) {
    auto it = products.find(productID);
    if (it != products.end()) {
        return &(it->second);
    }
    return nullptr;
}

const Product* Shop::findProductInternal(int productID) const {
     auto it = products.find(productID);
    if (it != products.end()) {
        return &(it->second);
    }
    return nullptr;
}


void Shop::addProduct(const std::string& name, double price, int stock) {
    int currentID = nextProductID++;
    products.emplace(currentID, Product(currentID, name, price, stock));
    std::cout << "--> Product '" << name << "' added with ID: " << currentID << std::endl;
}

void Shop::displayAllProducts() const {
    std::cout << "\n--- Products Available ---" << std::endl;
    if (products.empty()) {
        std::cout << "No products available currently." << std::endl;
        return;
    }
    std::cout << std::string(70, '-') << std::endl; // Adjusted separator width
     std::cout << std::setw(4) << std::right << "ID" << " | "
              << std::setw(25) << std::left << "Name" << " | " // Adjusted width
              << std::setw(8) << std::right << "Price" << " | "
              << std::setw(5) << "Stock" << std::left << std::endl;
     std::cout << std::string(70, '-') << std::endl;
    for (const auto& pair : products) {
        pair.second.display();
    }
    std::cout << std::string(70, '-') << std::endl;
}

const Product* Shop::findProductByID(int productID) const {
    return findProductInternal(productID);
}

bool Shop::addToCart(int productID, int quantity) {
    const Product* product = findProductInternal(productID);

    if (!product) {
        std::cerr << "!! Error: Product with ID " << productID << " not found." << std::endl;
        return false;
    }

    if (quantity <= 0) {
        std::cerr << "!! Error: Purchase quantity must be greater than 0." << std::endl;
        return false;
    }

    int currentInCart = 0;
    auto cartIt = shoppingCart.find(productID);
    if (cartIt != shoppingCart.end()) {
        currentInCart = cartIt->second;
    }

    int neededStock = currentInCart + quantity;

    if (product->getStock() >= neededStock) {
        shoppingCart[productID] = neededStock;
        std::cout << "--> Added " << quantity << " item(s) of '" << product->getName() << "' to the cart." << std::endl;
        std::cout << "    Cart now contains " << shoppingCart[productID] << " item(s)." << std::endl;
        return true;
    } else {
        std::cerr << "!! Error: Product '" << product->getName() << "' is out of stock." << std::endl;
        std::cerr << "    Current stock: " << product->getStock()
                  << ", Already in cart: " << currentInCart
                  << ", You want to add: " << quantity
                  << " (Total needed: " << neededStock << ")" << std::endl;
         if (product->getStock() > currentInCart) {
             std::cerr << "    You can add at most " << product->getStock() - currentInCart << " more item(s)." << std::endl;
         } else {
              std::cerr << "    You cannot add more of this item." << std::endl;
         }
        return false;
    }
}

void Shop::displayCart() const {
    std::cout << "\n--- Your Shopping Cart ---" << std::endl;
    if (shoppingCart.empty()) {
        std::cout << "The shopping cart is empty." << std::endl;
        return;
    }

    double totalCost = 0.0;
    std::cout << std::string(75, '-') << std::endl; // Adjusted separator width
    std::cout << std::setw(4) << std::right << "ID" << " | "
              << std::setw(25) << std::left << "Name" << " | " // Adjusted width
              << std::setw(8) << std::right << "Price" << " | "
              << std::setw(5) << "Qty" << " | "
              << std::setw(10) << "Subtotal" << std::left << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    for (const auto& pair : shoppingCart) {
        int productID = pair.first;
        int quantity = pair.second;
        const Product* product = findProductInternal(productID);

        if (product) {
            double subtotal = product->getPrice() * quantity;
            totalCost += subtotal;
            std::cout << std::setw(4) << std::right << product->getID() << " | "
                      << std::setw(25) << std::left << product->getName() << " | $" // Adjusted width
                      << std::fixed << std::setprecision(2) << std::setw(7) << std::right << product->getPrice() << " | "
                      << std::setw(5) << std::right << quantity << " | $"
                      << std::fixed << std::setprecision(2) << std::setw(9) << std::right << subtotal << std::left << std::endl;
        } else {
            std::cerr << "!! Internal Error: Invalid product ID " << productID << " found in cart!" << std::endl;
        }
    }
    std::cout << std::string(75, '-') << std::endl;
    std::cout << std::setw(50) << std::right << "Total Amount: $" // Adjusted alignment
              << std::fixed << std::setprecision(2) << std::setw(10) << std::right << totalCost << std::left << std::endl;
    std::cout << std::string(75, '-') << std::endl;
}

bool Shop::checkout() {
    std::cout << "\n--- Checking Out ---" << std::endl;
    if (shoppingCart.empty()) {
        std::cout << "Shopping cart is empty. Cannot checkout." << std::endl;
        return false;
    }

    bool stockSufficient = true;
    for (const auto& pair : shoppingCart) {
        int productID = pair.first;
        int quantity = pair.second;
        Product* product = findProductInternal(productID);

        if (!product) {
            std::cerr << "!! Checkout Error: Product ID " << productID << " disappeared from stock! Checkout cancelled." << std::endl;
            stockSufficient = false;
            break;
        }
        if (product->getStock() < quantity) {
            std::cerr << "!! Checkout Error: Product '" << product->getName() << "' (ID: " << productID << ") is out of stock." << std::endl;
             std::cerr << "   Required: " << quantity << ", Available: " << product->getStock() << ". Checkout cancelled." << std::endl;
            stockSufficient = false;
            break;
        }
    }

    if (!stockSufficient) {
        std::cout << "Checkout cancelled due to stock issues. Cart contents remain unchanged." << std::endl;
        return false;
    }

    double finalTotal = 0.0;
    std::cout << "Purchase Details:" << std::endl;
    for (const auto& pair : shoppingCart) {
        int productID = pair.first;
        int quantity = pair.second;
        Product* product = findProductInternal(productID);

        if (product) {
            finalTotal += product->getPrice() * quantity;
            product->reduceStock(quantity); // *** Actual stock deduction ***
            std::cout << "  - " << product->getName() << " x " << quantity << std::endl;
        }
    }

    std::cout << "--------------------------" << std::endl;
    std::cout << "Checkout complete! Thank you for your purchase!" << std::endl;
    std::cout << "Final Amount Paid: $" << std::fixed << std::setprecision(2) << finalTotal << std::endl;
    std::cout << "--------------------------" << std::endl;

    clearCart();
    return true;
}

void Shop::clearCart() {
    shoppingCart.clear();
}