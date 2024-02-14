#include <iostream>
using namespace std;

class VendingMachine {
private:
    int cashAvailable;

public:
    VendingMachine() {
        cashAvailable = 500;
    }

    VendingMachine(int initialCash) {
        cashAvailable = initialCash;
    }

    int getBalance() const {
        return cashAvailable;
    }

    void acceptAmount(int amountIn) {
        cashAvailable += amountIn;
    }
};

class ProductDispenser {
private:
    int availableItems;
    int price;

public:
    ProductDispenser() {
        availableItems = 50;
        price = 50;
    }

    ProductDispenser(int items, int priceIn) {
        availableItems = items;
        price = priceIn;
    }

    int getAvailableItems() const {
        return availableItems;
    }

    int getPrice() const {
        return price;
    }

    void sellProduct() {
        availableItems--;
    }
};

void displayMenu() {
    cout << "Welcome!\n";
    cout << "1. Water\n";
    cout << "2. Orangejuice\n";
    cout << "3. Snicker\n";
    cout << "4. Cookies\n";
    cout << "Select product, enter number: ";
}

void processSale(ProductDispenser& productDispenser, VendingMachine& cashRegister) {
    int productPrice = productDispenser.getPrice();
    int currentBalance = cashRegister.getBalance();
    int userMoneyInput;

    if (productDispenser.getAvailableItems() > 0) {
        cout << "Product price: " << productPrice << " rubles. Please deposit money: ";
        cin >> userMoneyInput;

        if (userMoneyInput >= productPrice) {
            if (currentBalance >= userMoneyInput - productPrice) {
                productDispenser.sellProduct();
                cashRegister.acceptAmount(productPrice);
                cout << "Your purchase has been issued!\n";
                cout << "Change: " << userMoneyInput - productPrice << " rubles.\n";
                cout << "Thank you, for your preference.\n";
            }
            else {
                cout << "It is not possible to issue change. \n Please enter a different amount.\n";
            }
        }
        else {
            cout << "Insufficient funds. Please deposit a larger amount.\n";
        }
    }
    else {
        cout << "Item out of stock. \n";
    }
}

int main() {
    VendingMachine cashRegister(1500);
    ProductDispenser water(70, 60), Orangejuice(50, 120), Snicker(100, 100), cookies(85, 75);

    int choice;
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
        processSale( water, cashRegister);
        break;
    case 2:
        processSale( Orangejuice, cashRegister);
        break;
    case 3:
        processSale( Snicker, cashRegister);
        break;
    case 4:
        processSale(cookies, cashRegister);
        break;
    default:
        cout << "Wrong choice.\n";
        break;
    }

    return 0;
}