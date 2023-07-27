#include <iostream>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Error: Cannot divide by zero!" << std::endl;
        return 0.0;
    }
}

int main() {
    char choice;
    double num1, num2, result;

    do {
        std::cout << "===== Simple Calculator =====" << std::endl;
        std::cout << "Enter the first number: ";
        std::cin >> num1;

        std::cout << "Enter the second number: ";
        std::cin >> num2;

        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Addition (+)" << std::endl;
        std::cout << "2. Subtraction (-)" << std::endl;
        std::cout << "3. Multiplication (*)" << std::endl;
        std::cout << "4. Division (/)" << std::endl;
        std::cout << "Q. Quit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                result = add(num1, num2);
                std::cout << "Result: " << result << std::endl;
                break;
            case '2':
                result = subtract(num1, num2);
                std::cout << "Result: " << result << std::endl;
                break;
            case '3':
                result = multiply(num1, num2);
                std::cout << "Result: " << result << std::endl;
                break;
            case '4':
                result = divide(num1, num2);
                std::cout << "Result: " << result << std::endl;
                break;
            case 'q':
            case 'Q':
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
        std::cout << "=============================" << std::endl;

    } while (choice != 'q' && choice != 'Q');

    return 0;
}
