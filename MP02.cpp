#include <iostream>
using namespace std;

int Input();
long long Factorial(int n1);
long long SumNatural(int n1);
long long SumSquares(int n1);
void CompareResult(int n1);

int main()
{
    do {
        cout << "\nMenu Operations: " << endl;
        cout << "1 - Factorial n!" << endl;
        cout << "2 - Sum 1 + 2 + ... + n" << endl;
        cout << "3 - Sum of squares 1^2 + ... + n^2" << endl;
        cout << "4 - Compare factorial and sum" << endl;
        cout << "0 - Exit" << endl << endl;

        int action, number;
        cout << "What do u want to do?: ";
        cin >> action;

        switch (action) {
        case 1:
            number = Input();
            cout << "Factorial = " << Factorial(number) << endl;
            break;

        case 2:
            number = Input();
            cout << "Sum = " << SumNatural(number) << endl;
            break;

        case 3:
            number = Input();
            cout << "Squares sum = " << SumSquares(number) << endl;
            break;

        case 4:
            number = Input();
            CompareResult(number);
            break;
        case 0:
            exit(0);
        }
    } while (1);
    return 0;
}

int Input() {
    int number;
    do {
        cout << "Enter a number from 0 to 12: ";
        cin >> number;

        if (number > 12 || number < 0) {
            cout << "This is an invalid number, retry" << endl;
            continue;
        }
        else {
            break;
        }
    } while (1);
    return number;
}

long long Factorial(int n1) {
    
    long long f = 1;
    for (int i = 1; i <= n1; ++i) {
        f = f * i;
    }
    return f;
}

long long SumNatural(int n1) {

    int s = 0;
    for (int i = 1; i <= n1; i++) {
        s = s + i;
    }
    return s;
}

long long SumSquares(int n1) {

    long long  sq = 0;
    for (int i = 1; i <= n1; i++) {

        sq = sq + (i * i);
    }
    return sq;
}

void CompareResult(int n1) {
    
    long long fact = Factorial(n1);
    long long sum = SumNatural(n1);

    if (sum > fact) {
        cout << "Sum greater " << "(" << sum << " > " << fact << ")" << endl;
    }
    else if (fact > sum) {
        cout << "Factorial greater " << "(" << fact << " > " << sum << ")" << endl;
    }
    else if (fact = sum) {
        cout << "Equal " << "(" << sum << " = " << fact << ")" << endl;
    }
    

  
}
