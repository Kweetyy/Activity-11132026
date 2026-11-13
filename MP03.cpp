/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

long long fibonacci(int n);
void printSequence(int n);
int countEven(int n);
long long sumSequence(int n);
int getInteger(const string& prompt, int minimum, int maximum);

int main() {
    int option;

    do {
        cout << "\n=== Fibonacci Sequence Analyzer ===\n"
             << "1 - Display first n Fibonacci terms\n"
             << "2 - Find Fibonacci term at index n\n"
             << "3 - Count even terms among first n\n"
             << "4 - Sum first n Fibonacci terms\n"
             << "0 - Exit\n";

        option = getInteger("Choose an option: ", 0, 4);

        switch (option) {
            case 1: {
                int n = getInteger("Enter n (1-20): ", 1, 20);
                cout << "Sequence = ";
                printSequence(n);
                cout << '\n';
                break;
            }
            case 2: {
                int n = getInteger("Enter index n (0-20): ", 0, 20);
                cout << "F(" << n << ") = " << fibonacci(n) << '\n';
                break;
            }
            case 3: {
                int n = getInteger("Enter n (1-20): ", 1, 20);
                cout << "Even count = " << countEven(n) << '\n';
                break;
            }
            case 4: {
                int n = getInteger("Enter n (1-20): ", 1, 20);
                cout << "Sum = " << sumSequence(n) << '\n';
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
        }
    } while (option != 0);

    return 0;
}

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printSequence(int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << "   ";
        cout << fibonacci(i);
    }
}

int countEven(int n) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (fibonacci(i) % 2 == 0) {
            ++count;
        }
    }

    return count;
}

long long sumSequence(int n) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += fibonacci(i);
    }

    return sum;
}

int getInteger(const string& prompt, int minimum, int maximum) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            if (value >= minimum && value <= maximum) {
                return value;
            }

            cout << "Invalid number; enter a value from "
                 << minimum << " to " << maximum << ".\n";
        } else {
            if (cin.eof()) {
                exit(0);
            }

            cout << "Invalid input; please enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}