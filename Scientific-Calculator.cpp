#define _USE_MATH_DEFINES
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Calculator {
public:
    double add(double, double);
    double sub(double, double);
    double mul(double, double);
    double div(double, double);
    double average(double*, int);
    unsigned long long factorial(int);
    double* ini(int& size);
    void choice();
    double percentage(double, double);
    double power(double, double);
    double squareRoot(double);
    double naturalLog(double);
    double log_base10(double);
    double trignomatry(double);
    double trignomatry(double, double);
    double inverseTrig(double);
    double radToDeg(double);
    double degToRad(double);
    double getValidatedInput();
    ~Calculator() {}
};

double Calculator::getValidatedInput() {
    double input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return input;
        }
    }
}

double Calculator::add(double a, double b) { return a + b; }
double Calculator::sub(double a, double b) { return a - b; }
double Calculator::mul(double a, double b) { return a * b; }

double Calculator::div(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

double Calculator::percentage(double part, double total) {
    if (total == 0) {
        cout << "Error: Division by zero in percentage!" << endl;
        return 0;
    }
    return (part / total) * 100;
}

unsigned long long Calculator::factorial(int a) {
    if (a < 0) {
        cout << "Error: Factorial of negative number is undefined!" << endl;
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= a; i++) {
        result *= i;
    }
    return result;
}

double Calculator::power(double a, double b) {
    return pow(a, b);
}

double Calculator::squareRoot(double a) {
    return sqrt(a);
}

double Calculator::naturalLog(double a) {
    return log(a);
}

double Calculator::log_base10(double a) {
    return log10(a);
}

double Calculator::radToDeg(double rad) {
    return rad * (180.0 / M_PI);
}

double Calculator::degToRad(double deg) {
    return deg * (M_PI / 180.0);
}

double Calculator::trignomatry(double a) {
    cout << "Select the operation (input in radians):\n";
    cout << "1: sin\n2: cos\n3: tan\n4: cosec\n5: sec\n6: cot\n";
    int cho;
    cho = static_cast<int>(getValidatedInput());

    switch (cho) {
    case 1: return sin(a);
    case 2: return cos(a);
    case 3: return tan(a);
    case 4: return 1.0 / sin(a);
    case 5: return 1.0 / cos(a);
    case 6: return 1.0 / tan(a);
    default:
        cout << "Error! Invalid choice." << endl;
        return 0;
    }
}

double Calculator::trignomatry(double a, double b) {
    cout << "Select the operation (a / b in radians):\n";
    cout << "1: sin\n2: cos\n3: tan\n4: cosec\n5: sec\n6: cot\n";
    int cho;
    cho = static_cast<int>(getValidatedInput());

    if (b == 0) {
        cout << "Error! Division by zero is undefined." << endl;
        return 0;
    }

    double angle = a / b;

    switch (cho) {
    case 1: return sin(angle);
    case 2: return cos(angle);
    case 3: return tan(angle);
    case 4: return 1.0 / sin(angle);
    case 5: return 1.0 / cos(angle);
    case 6: return 1.0 / tan(angle);
    default:
        cout << "Error! Invalid choice." << endl;
        return 0;
    }
}

double Calculator::inverseTrig(double value) {
    cout << "Select inverse trig operation (result in degrees):\n";
    cout << "1: arcsin\n2: arccos\n3: arctan\n";
    int choice;
    choice = static_cast<int>(getValidatedInput());

    double result = 0;
    switch (choice) {
    case 1:
        if (value < -1 || value > 1) {
            cout << "Error: arcsin is undefined for this input.\n";
            return numeric_limits<double>::quiet_NaN();
        }
        result = asin(value);
        break;
    case 2:
        if (value < -1 || value > 1) {
            cout << "Error: arccos is undefined for this input.\n";
            return numeric_limits<double>::quiet_NaN();
        }
        result = acos(value);
        break;
    case 3:
        result = atan(value);
        break;
    default:
        cout << "Invalid choice!\n";
        return numeric_limits<double>::quiet_NaN();
    }

    return radToDeg(result);
}

double* Calculator::ini(int& size) {
    cout << "Enter size of array: ";
    size = static_cast<int>(getValidatedInput());
    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return nullptr;
    }

    double* ptr = new double[size];
    cout << "Enter values in array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        ptr[i] = getValidatedInput();
    }
    return ptr;
}

double Calculator::average(double* arr, int size) {
    if (size == 0 || arr == nullptr) return 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void Calculator::choice() {
    cout << "\n--- Scientific Calculator Menu ---\n";
    cout << "1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n";
    cout << "5: Factorial\n6: Average\n7: Percentage\n8: Power\n9: Square Root\n";
    cout << "10: Natural Log\n11: Log base 10\n";
    cout << "12: Trigonometry (1 operand in radians)\n";
    cout << "13: Trigonometry (a / b in radians)\n";
    cout << "14: Convert Radians to Degrees\n";
    cout << "15: Inverse Trigonometric Functions (result in degrees)\n";
    cout << "0: Exit\n";
}

int main() {
    double a, b, result;
    int n;
    int choice;
    double* arr = nullptr;

    Calculator obj;
    do {
        obj.choice();
        cout << "\nSelect your choice: ";
        choice = static_cast<int>(obj.getValidatedInput());

        switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4: {
            cout << "Enter first number: ";
            a = obj.getValidatedInput();
            result = a;
            char cont;
            do {
                cout << "Enter next number: ";
                b = obj.getValidatedInput();
                if (choice == 1) result = obj.add(result, b);
                else if (choice == 2) result = obj.sub(result, b);
                else if (choice == 3) result = obj.mul(result, b);
                else result = obj.div(result, b);
                cout << "Current Result: " << result << endl;
                cout << "Continue with this result? (y/n): ";
                cin >> cont;
            } while (cont == 'y' || cont == 'Y');
            break;
        }

        case 5:
            cout << "Enter whole number: ";
            n = static_cast<int>(obj.getValidatedInput());
            cout << "Result: " << obj.factorial(n) << endl;
            break;

        case 6:
            arr = obj.ini(n);
            if (arr != nullptr) {
                result = obj.average(arr, n);
                cout << "Average: " << result << endl;
                delete[] arr;
                arr = nullptr;
            }
            break;

        case 7:
            cout << "Enter part value: ";
            a = obj.getValidatedInput();
            cout << "Enter total value: ";
            b = obj.getValidatedInput();
            result = obj.percentage(a, b);
            cout << "Percentage: " << result << "%" << endl;
            break;

        case 8:
            cout << "Enter base: ";
            a = obj.getValidatedInput();
            cout << "Enter exponent: ";
            b = obj.getValidatedInput();
            result = obj.power(a, b);
            cout << "Power: " << result << endl;
            break;

        case 9:
            cout << "Enter number: ";
            a = obj.getValidatedInput();
            if (a < 0) {
                cout << "Square root of negative number is not real." << endl;
                break;
            }
            result = obj.squareRoot(a);
            cout << "Square root: " << result << endl;
            break;

        case 10:
            cout << "Enter number: ";
            a = obj.getValidatedInput();
            if (a <= 0) {
                cout << "Natural log undefined for zero or negative.\n";
                break;
            }
            result = obj.naturalLog(a);
            cout << "Natural log: " << result << endl;
            break;

        case 11:
            cout << "Enter number: ";
            a = obj.getValidatedInput();
            if (a <= 0) {
                cout << "Log base 10 undefined for zero or negative.\n";
                break;
            }
            result = obj.log_base10(a);
            cout << "Log base 10: " << result << endl;
            break;

        case 12:
            cout << "Enter angle in degrees: ";
            a = obj.degToRad(obj.getValidatedInput());
            result = obj.trignomatry(a);
            cout << "Result: " << result << endl;
            break;

        case 13:
            cout << "Enter a (in degrees): ";
            a = obj.degToRad(obj.getValidatedInput());
            cout << "Enter b (in degrees): ";
            b = obj.degToRad(obj.getValidatedInput());
            result = obj.trignomatry(a, b);
            cout << "Result: " << result << endl;
            break;

        case 14:
            cout << "Enter radians: ";
            a = obj.getValidatedInput();
            result = obj.radToDeg(a);
            cout << "Degrees: " << result << "\u00B0" << endl;
            break;

        case 15:
            cout << "Enter value: ";
            a = obj.getValidatedInput();
            result = obj.inverseTrig(a);
            cout << "Inverse trig result: " << result << "\u00B0" << endl;
            break;

        case 0:
            cout << "Exiting calculator.\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}