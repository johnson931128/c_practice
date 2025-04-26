#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>
#include <map>
#include <iostream> // For Product::display() declaration

// --- Product Class ---
class Product {
private:
    int id;
    std::string name;
    double price;
    int stock; // Stock quantity

public:
    // Constructor - with default values
    Product(int id = 0, std::string n = "", double p = 0.0, int s = 0);

    // Getters - marked const as they don't modify object state
    int getID() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;

    // Modifiers
    bool reduceStock(int quantity); // Reduce stock, return success/failure
    void increaseStock(int quantity); // Increase stock

    // Display product info - marked const
    void display() const;
};


// --- Shop Class ---
class Shop {
private:
    std::map<int, Product> products;    // Use map to store products, key is product ID
    std::map<int, int> shoppingCart; // Shopping cart <ProductID, Quantity>
    int nextProductID;               // To generate unique product IDs

    // Private helper function to find Product pointer by ID (for modifying stock)
    Product* findProductInternal(int productID);
    // const version for functions that don't need to modify the object
    const Product* findProductInternal(int productID) const;


public:
    // Constructor
    Shop();

    // --- Product Management ---
    void addProduct(const std::string& name, double price, int stock); // Add product to shop
    void displayAllProducts() const;                                 // Display all products (const)
    const Product* findProductByID(int productID) const;              // Find product by ID (public, returns const pointer)

    // --- Cart and Checkout ---
    bool addToCart(int productID, int quantity); // Add product to cart
    void displayCart() const;                     // Display cart contents and total (const)
    bool checkout();                              // Checkout (perform purchase, update stock)
    void clearCart();                             // Clear the shopping cart
};

#endif // SHOP_H