#include <iostream>
using namespace std;

int digitSum(int n);
int digitCount(int n);
int reverseDigits(int n, int accumulator);
bool isPalindrome(int n);

int main() {
    int choice;
    int number;

    do {
        cout << "\n===== NUMBER ANALYSIS SYSTEM =====\n";
        cout << "1 - Sum of digits\n";
        cout << "2 - Count digits\n";
        cout << "3 - Reverse digits\n";
        cout << "4 - Check palindrome\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid menu choice; retry.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        }

        if (choice < 1 || choice > 4) {
            cout << "Invalid menu choice; retry.\n";
            continue;
        }

        
        cout << "Enter a number (0-999999): ";
        cin >> number;

      
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid number; retry.\n";
            continue;
        }

        if (number < 0 || number > 999999) {
            cout << "Invalid number; retry.\n";
            continue;
        }

       
        switch (choice) {
            case 1:
                cout << "Sum = " << digitSum(number) << endl;
                break;

            case 2:
                cout << "Digits = " << digitCount(number) << endl;
                break;

            case 3:
                cout << "Reverse = " << reverseDigits(number, 0) << endl;
                break;

            case 4:
                if (isPalindrome(number)) {
                    cout << "Palindrome = Yes" << endl;
                } else {
                    cout << "Palindrome = No" << endl;
                }
                break;
        }

    } while (true);

    return 0;
}


int digitSum(int n) {
   
    if (n == 0) {
        return 0;
    }

    return (n % 10) + digitSum(n / 10);
}


int digitCount(int n) {
   
    if (n == 0) {
        return 1;
    }

    if (n < 10) {
        return 1;
    }

    return 1 + digitCount(n / 10);
}

int reverseDigits(int n, int accumulator) {
    // Base case
    if (n == 0) {
        return accumulator;
    }

    return reverseDigits(n / 10, accumulator * 10 + (n % 10));
}

bool isPalindrome(int n) {
    return n == reverseDigits(n, 0);
}

