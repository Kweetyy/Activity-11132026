/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

void printAscendingRow(int k);
void printDescendingRow(int k);
void countdown(int n);
void printGridRow(int row, int col, int n);
int getInteger(const string& prompt, int minimum, int maximum);

int main() {
    int option;

    do {
        cout << "\n=== Recursive Number Pattern Generator ===\n"
             << "1 - Ascending triangle\n"
             << "2 - Descending triangle\n"
             << "3 - Recursive countdown\n"
             << "4 - Multiplication grid\n"
             << "0 - Exit\n";

        option = getInteger("Choose an option: ", 0, 4);

        switch (option) {
            case 1: {
                int n = getInteger("Enter size (1-9): ", 1, 9);
                cout << "Ascending triangle:\n";
                for (int row = 1; row <= n; ++row) {
                    printAscendingRow(row);
                    cout << '\n';
                }
                break;
            }
            case 2: {
                int n = getInteger("Enter size (1-9): ", 1, 9);
                cout << "Descending triangle:\n";
                for (int row = n; row >= 1; --row) {
                    printAscendingRow(row);
                    cout << '\n';
                }
                break;
            }
            case 3: {
                int n = getInteger("Enter size (1-9): ", 1, 9);
                cout << "Countdown: ";
                countdown(n);
                cout << "GO!\n";
                break;
            }
            case 4: {
                int n = getInteger("Enter size (1-9): ", 1, 9);
                cout << "Multiplication grid:\n";
                for (int row = 1; row <= n; ++row) {
                    printGridRow(row, 1, n);
                    cout << '\n';
                }
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
        }
    } while (option != 0);

    return 0;
}

void printAscendingRow(int k) {
    if (k <= 0) return;

    printAscendingRow(k - 1);
    if (k > 1) cout << ' ';
    cout << k;
}

void printDescendingRow(int k) {
    if (k <= 0) return;

    cout << k;
    if (k > 1) cout << ' ';
    printDescendingRow(k - 1);
}

void countdown(int n) {
    if (n <= 0) return;

    cout << n << ' ';
    countdown(n - 1);
}

void printGridRow(int row, int col, int n) {
    if (col > n) return;

    cout << setw(4) << row * col;
    printGridRow(row, col + 1, n);
}

int getInteger(const string& prompt, int minimum, int maximum) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            if (value >= minimum && value <= maximum) {
                return value;
            }
            cout << "Invalid entry; enter a number from "
                 << minimum << " to " << maximum << ".\n";
        } else {
            if (cin.eof()) exit(0);

            cout << "Invalid input; please enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}