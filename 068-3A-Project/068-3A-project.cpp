#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
using namespace std;

class asset
{
public:
    string name;
    double price, quantity;
    asset *next;

    asset(string name, double price, double quantity)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->next = nullptr;
    }
};

class portfolio
{
public:
    asset *head;

    portfolio()
    {
        head = nullptr;
    }

    void add()
    {
        string name;
        double price, usd;

        cout << "Enter Asset Name (or 0 to cancel): ";
        cin >> name;
        if (name == "0")
            return;

        while (true)
        {
            cout << "Enter Price per unit: ";
            cin >> price;
            if (!cin.fail())
                break;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid price input! Try again.\n";
        }

        while (true)
        {
            cout << "Enter USD amount to buy (or 0 to cancel): ";
            cin >> usd;

            if (!cin.fail() && usd >= 0)
                break;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid USD input! Try again.\n";
        }

        if (usd == 0)
            return;

        double quantity = usd / price;
        asset *newAsset = new asset(name, price, quantity);

        if (head == nullptr)
        {
            head = newAsset;
        }
        else
        {
            asset *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newAsset;
        }

        cout << "Asset added! Quantity bought: " << fixed << setprecision(6) << quantity << endl;
    }

    void display()
    {
        asset *temp = head;
        if (!temp)
        {
            cout << "Portfolio is empty!\n";
            return;
        }
        while (temp != nullptr)
        {
            cout << "Name: " << temp->name << endl
                 << "Price: $" << fixed << setprecision(2) << temp->price << endl
                 << "Quantity: " << fixed << setprecision(6) << temp->quantity << endl
                 << "-----------" << endl;
            temp = temp->next;
        }
    }

    void remove(string name)
    {
        if (head == nullptr)
        {
            cout << "Portfolio is empty!\n";
            return;
        }

        if (head->name == name)
        {
            double closePrice;
            cout << "Enter average closing price: ";
            cin >> closePrice;

            double pnl = (closePrice - head->price) * head->quantity;
            cout << "PnL for " << head->name << ": $" << fixed << setprecision(2) << pnl << endl;

            asset *temp = head;
            head = head->next;
            delete temp;
            cout << "Asset removed!\n";
            return;
        }

        asset *current = head;
        while (current->next != nullptr && current->next->name != name)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "Asset not found!\n";
            return;
        }

        double closePrice;
        cout << "Enter average closing price: ";
        cin >> closePrice;

        double pnl = (closePrice - current->next->price) * current->next->quantity;
        cout << "PnL for " << current->next->name << ": $" << fixed << setprecision(2) << pnl << endl;

        asset *temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Asset removed!\n";
    }

    void update(string name)
    {
        asset *current = head;

        while (current != nullptr && current->name != name)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Asset not found!\n";
            return;
        }

        double newPrice, usd;
        cout << "Enter new price per unit: ";
        cin >> newPrice;
        cout << "Enter USD amount to buy more: ";
        cin >> usd;

        double newQuantity = usd / newPrice;
        double newTotalValue = (current->price * current->quantity) + (newPrice * newQuantity);
        current->quantity += newQuantity;
        current->price = newTotalValue / current->quantity;

        cout << "Average buying price updated: $" << fixed << setprecision(2) << current->price << endl;
    }

    void displayTotalValue()
    {
        asset *temp = head;
        double totalValue = 0;

        if (temp == nullptr)
        {
            cout << "Portfolio is empty!\n";
            return;
        }

        cout << "\nPortfolio Value in USD:\n";
        while (temp != nullptr)
        {
            double usdValue = temp->price * temp->quantity;
            totalValue += usdValue;

            cout << "Asset: " << temp->name
                 << " | Price: $" << fixed << setprecision(2) << temp->price
                 << " | Quantity: " << fixed << setprecision(6) << temp->quantity
                 << " | USD Value: $" << fixed << setprecision(2) << usdValue
                 << endl;

            temp = temp->next;
        }

        cout << "---------------------------\n";
        cout << "Total Portfolio Value: $" << fixed << setprecision(2) << totalValue << endl;
    }
};

int main()
{
    portfolio p;
    int choice;
    string name;

    do
    {
        cout << "Portfolio Tracker & Analyzer\n";
        cout << "1. Add Asset\n";
        cout << "2. Display Portfolio\n";
        cout << "3. Update Asset\n";
        cout << "4. Remove Asset\n";
        cout << "5. Display Total Value\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number from the menu.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            p.add();
            break;
        case 2:
            p.display();
            break;
        case 3:
            cout << "Enter the asset name to update: ";
            cin >> name;
            p.update(name);
            break;
        case 4:
            cout << "Enter the asset name to remove: ";
            cin >> name;
            p.remove(name);
            break;
        case 5:
            p.displayTotalValue();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
