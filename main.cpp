#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Represents a currency type and amount
class Currency {
public:
    string type;
    double amount;

    Currency(const string& type, double amount) : type(type), amount(amount) {}
};

// Manages currencies in a wallet
class Wallet {
private:
    vector<Currency> currencies;

public:
    // Inserts currency into the wallet
    void insertCurrency(const string& type, double amount) {
        if (amount < 0) {
            cout << "Error: Amount cannot be negative." << endl;
            return;
        }

        for (auto& currency : currencies) {
            if (currency.type == type) {
                currency.amount += amount;
                cout << "Added " << amount << " of " << type << " to wallet.\n";
                return;
            }
        }

        currencies.push_back(Currency(type, amount));
        cout << "Inserted " << amount << " of " << type << " to wallet.\n";
    }

    // Removes currency from the wallet
    bool removeCurrency(const string& type, double amount) {
        if (amount < 0) {
            cout << "Error: Amount cannot be negative." << endl;
            return false;
        }

        for (auto& currency : currencies) {
            if (currency.type == type) {
                if (currency.amount >= amount) {
                    currency.amount -= amount;
                    cout << "Removed " << amount << " of " << type << " from wallet.\n";
                    return true;
                } else {
                    cout << "Insufficient " << type << " in wallet.\n";
                    return false;
                }
            }
        }

        cout << "Currency type not found in wallet.\n";
        return false;
    }

    // Checks if the wallet contains sufficient currency
    bool containsCurrency(const string& type, double amount) const {
        for (const auto& currency : currencies) {
            if (currency.type == type && currency.amount >= amount) {
                return true;
            }
        }
        return false;
    }

    // Displays the contents of the wallet
    void displayWallet() const {
        cout << "\n--- Wallet Contents ---\n";
        for (const auto& currency : currencies) {
            cout << currency.type << ": " << currency.amount << "\n";
        }
        cout << "-----------------------\n";
    }
};

// Represents an order in the exchange
class Order {
private:
    string type;
    string currency;
    double amount;
    double price;

public:
    Order(const string& type, const string& currency, double amount, double price)
        : type(type), currency(currency), amount(amount), price(price) {}

    // Displays the order details
    void displayOrder() const {
        cout << type << " " << amount << " of " << currency << " at $" << price << "\n";
    }

    string getType() const { return type; }
    string getCurrency() const { return currency; }
    double getAmount() const { return amount; }
    double getPrice() const { return price; }
};

// Manages orders in the exchange
class Exchange {
private:
    vector<Order> orderBook;

public:
    // Places an order in the exchange
    void placeOrder(const Order& order) {
        orderBook.push_back(order);
        cout << "Placed " << order.getType() << " order for " << order.getAmount() << " " << order.getCurrency() << " at $" << order.getPrice() << "\n";
    }

    // Displays all orders
    void displayOrders() const {
        cout << "\n--- Order Book ---\n";
        for (const auto& order : orderBook) {
            order.displayOrder();
        }
        cout << "------------------\n";
    }

    // Cancels an order by index
    void cancelOrder(int index) {
        if (index >= 0 && index < orderBook.size()) {
            orderBook.erase(orderBook.begin() + index);
            cout << "Order canceled successfully.\n";
        } else {
            cout << "Invalid order index.\n";
        }
    }

    // Calculates the total portfolio value
    double calculatePortfolioValue(const Wallet& wallet) const {
        double totalValue = 0.0;
        for (const auto& order : orderBook) {
            if (order.getType() == "ask") {
                totalValue += order.getAmount() * order.getPrice();
            }
        }
        return totalValue;
    }
};

// Main management system for the crypto project
class CryptoManagementSystem {
private:
    Wallet wallet;
    Exchange exchange;

public:
    // Main menu for the system
    void mainMenu() {
        int choice;
        while (true) {
            cout << "\n--- Crypto Management System ---\n";
            cout << "1. Insert Currency\n";
            cout << "2. Remove Currency\n";
            cout << "3. Check Currency\n";
            cout << "4. Place Ask Order\n";
            cout << "5. Place Bid Order\n";
            cout << "6. Display Wallet\n";
            cout << "7. Display Orders\n";
            cout << "8. Cancel Order\n";
            cout << "9. Calculate Portfolio Value\n";
            cout << "0. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1: insertCurrency(); break;
                case 2: removeCurrency(); break;
                case 3: checkCurrency(); break;
                case 4: placeAsk(); break;
                case 5: placeBid(); break;
                case 6: wallet.displayWallet(); break;
                case 7: exchange.displayOrders(); break;
                case 8: cancelOrder(); break;
                case 9: calculatePortfolioValue(); break;
                case 0: cout << "Exiting...\n"; return;
                default: cout << "Invalid choice! Try again.\n"; break;
            }
        }
    }

    // Handles inserting currency
    void insertCurrency() {
        string type;
        double amount;
        cout << "Enter currency type: ";
        cin >> type;
        cout << "Enter amount: ";
        cin >> amount;
        wallet.insertCurrency(type, amount);
    }

    // Handles removing currency
    void removeCurrency() {
        string type;
        double amount;
        cout << "Enter currency type: ";
        cin >> type;
        cout << "Enter amount: ";
        cin >> amount;
        wallet.removeCurrency(type, amount);
    }

    // Checks if currency exists in wallet
    void checkCurrency() {
        string type;
        double amount;
        cout << "Enter currency type: ";
        cin >> type;
        cout << "Enter amount: ";
        cin >> amount;
        if (wallet.containsCurrency(type, amount)) {
            cout << "Wallet contains sufficient " << type << ".\n";
        } else {
            cout << "Insufficient " << type << " in wallet.\n";
        }
    }

    // Handles placing an ask order
    void placeAsk() {
        string currency;
        double amount, price;
        cout << "Enter currency for ask: ";
        cin >> currency;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter price: ";
        cin >> price;
        if (wallet.removeCurrency(currency, amount)) {
            Order ask("ask", currency, amount, price);
            exchange.placeOrder(ask);
        }
    }

    // Handles placing a bid order
    void placeBid() {
        string currency;
        double amount, price;
        cout << "Enter currency for bid: ";
        cin >> currency;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter price: ";
        cin >> price;
        wallet.insertCurrency(currency, amount);
        Order bid("bid", currency, amount, price);
        exchange.placeOrder(bid);
    }

    // Handles order cancellation
    void cancelOrder() {
        int index;
        exchange.displayOrders();
        cout << "Enter order index to cancel: ";
        cin >> index;
        exchange.cancelOrder(index - 1);
    }

    // Calculates the total value of the portfolio
    void calculatePortfolioValue() {
        double value = exchange.calculatePortfolioValue(wallet);
        cout << "Total Portfolio Value: $" << value << "\n";
    }
};

int main() {
    CryptoManagementSystem cms;
    cms.mainMenu();
    return 0;
}
