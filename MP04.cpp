#include <iostream>
using namespace std;

int gcdRecursive(int Num1, int Num2);
long long lcm(int Num1, int Num2);
bool coprime(int Num1, int Num2);
void readPair(int &Num1, int &Num2);


int main() {
    int choice;
    int num1, num2;

    do {
        cout << "\n========== GCD & LCM CALCULATOR ==========\n";
        cout << "1. Find GCD\n";
        cout << "2. Find LCM\n";
        cout << "3. Check Coprime\n";
        cout << "4. Show GCD and LCM\n";
        cout << "0. Exit\n";

        cout << "Enter your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: 
              readPair(num1, num2);

              cout << "\nGCD: " << gcdRecursive(num1, num2) <<endl;
            break;

            case 2: 
              readPair(num1, num2);

              cout << "\nLCM: " << lcm(num1, num2) <<endl;
            break;

            case 3: 
              readPair(num1, num2);

              coprime(num1, num2);
            break;

            case 4: 
              readPair(num1, num2);

              cout << "\nGCD: " << gcdRecursive(num1, num2) << endl;
              cout << "\nLCM: " << lcm(num1, num2) << endl;
            break; 

            case 0: 
              cout << "Thank you for Using the GCD & LCM Calculator!";
            break;

            default: 
              cout << "Invalid Choice Please Try Again! (Choose from 0 - 4)";
            break;
        } 

    } while (choice != 0);

    return 0;
}

int gcdRecursive(int Num1, int Num2) {
    if (Num2 == 0) {
        return Num1;
    }

    return gcdRecursive(Num2, Num1 % Num2);
}

long long lcm(int Num1, int Num2) {
    int gcd = gcdRecursive(Num1, Num2);
    long long Lcm;

    Lcm = (Num1 / gcd) * Num2;

    return Lcm;
}

bool coprime(int Num1, int Num2) {
    int GCD = gcdRecursive(Num1, Num2);

    if (GCD == 1) {
        cout << "Are the Numbers Coprime: " << boolalpha << true << endl;
        return true;
    } else {
        cout << "Are the Numbers Coprime: " << boolalpha << false << endl;
        return false;
    }
}

void readPair(int &Num1, int &Num2) {

    cout << "\nEnter First Number: ";
    cin >> Num1;

    while (Num1 < 1 || Num1 > 10000) {
        cout << "Enter a Valid Number! (1 - 10000): ";
        cin >> Num1;
    }

    cout << "\nEnter Second Number: ";
    cin >> Num2;

    while (Num2 < 1 || Num2 > 10000) {
        cout << "Enter a Valid Number! (1 - 10000): ";
        cin >> Num2;
    }
}
