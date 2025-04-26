#include "shop.h"
#include <iostream>
#include <limits>
#include <ios>
#include <string>
// #include <windows.h> // Not needed if using English only

// Helper function: Safely get integer input
int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cerr << "!! Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Helper function: Safely get double input
double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cerr << "!! Invalid input. Please enter a valid number (e.g., 199.99 or 200)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Helper function: Safely get string input (can contain spaces)
std::string getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}


// Display the main menu
void displayMenu() {
    std::cout << "\n========= Simple Online Shop =========" << std::endl;
    std::cout << "1. (Admin) Add Product to Shop" << std::endl;
    std::cout << "2. Browse All Products" << std::endl;
    std::cout << "3. Find Product by ID" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "4. Add Product to Cart" << std::endl;
    std::cout << "5. View My Shopping Cart" << std::endl;
    std::cout << "6. Clear Shopping Cart" << std::endl;
    std::cout << "7. Proceed to Checkout" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "0. Exit System" << std::endl;
    std::cout << "====================================" << std::endl;
}


int main() {
    // SetConsoleOutputCP(CP_UTF8); // Not needed for English only

    Shop myShop; // Create the shop object

    // Add some initial products for testing
    myShop.addProduct("High-Performance Laptop", 1599.99, 15);
    myShop.addProduct("Wireless Optical Mouse", 29.50, 100);
    myShop.addProduct("Mechanical Keyboard", 120.00, 50);
    myShop.addProduct("4K Webcam", 85.75, 30);
    myShop.addProduct("USB-C Hub", 45.99, 80);

    int choice;
    do {
        displayMenu();
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: { // Add Product
                std::cout << "\n-- Add Product (Admin Function) --" << std::endl;
                std::string name = getStringInput("Enter product name: ");
                double price = getDoubleInput("Enter product price: ");
                int stock = getIntInput("Enter initial stock quantity: ");
                if (price >= 0 && stock >= 0) {
                    myShop.addProduct(name, price, stock);
                } else {
                     std::cerr << "!! Error: Price and stock cannot be negative." << std::endl;
                }
                break;
            }
            case 2: { // Display All Products
                myShop.displayAllProducts();
                break;
            }
            case 3: { // Find Product
                std::cout << "\n-- Find Product --" << std::endl;
                int id = getIntInput("Enter product ID to find: ");
                const Product* found = myShop.findProductByID(id);
                if (found) {
                    std::cout << "Product found:" << std::endl;
                    std::cout << std::string(70, '-') << std::endl; // Use same width as displayAllProducts
                    found->display();
                    std::cout << std::string(70, '-') << std::endl;
                } else {
                    std::cout << "--> Product with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 4: { // Add to Cart
                std::cout << "\n-- Add to Cart --" << std::endl;
                myShop.displayAllProducts(); // Show products first for user reference
                int id = getIntInput("Enter ID of product to add to cart: ");
                int quantity = getIntInput("Enter quantity to purchase: ");
                myShop.addToCart(id, quantity); // Handles errors internally
                break;
            }
            case 5: { // View Cart
                myShop.displayCart();
                break;
            }
             case 6: { // Clear Cart
                myShop.clearCart();
                std::cout << "--> Your shopping cart has been cleared." << std::endl;
                break;
            }
             case 7: { // Checkout
                myShop.displayCart(); // Show cart before asking to checkout
                if (!myShop.checkout()) { // checkout handles its own messages on success/failure
                    std::cout << "Checkout was not completed." << std::endl; // Optional extra message on failure
                }
                break;
            }
            case 0: { // Exit
                std::cout << "\nThank you for using the system. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "!! Invalid choice. Please enter a number between 0 and 7." << std::endl;
                break;
            }
        }

        // Pause after each action (except exit)
        if (choice != 0) {
            std::cout << "\nPress Enter to return to the main menu...";
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Might be needed depending on buffer state
            std::cin.get(); // Wait for Enter
        }

    } while (choice != 0);

    return 0;
}