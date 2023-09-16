#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    cout<<endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            return 1; 
    }

    cout << "Result: " << result << endl<<endl;

    return 0; 
}
