#include <iostream>
using namespace std;

double show_balance(double balance);
double deposit();
double withdraw();

int main()
{
    double balance;
    int choice;

    cout << "***** Welcome to our bank *****" << endl;

    do
    {
        cout << "1. Show Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            double show_balance(double balance);
            break;
        case 2:
            balance += deposit();
            break;
        case 3:
            balance -= withdraw();
            break;
        case 4:
            cout << "Thank you for banking with us.";
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

double show_balance(double balance) {
    cout << "Your balance is: " << balance << endl;
}
double deposit() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    return amount;
}
double withdraw() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    return amount;
}
