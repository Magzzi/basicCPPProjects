#include <iostream>
#include <cmath>
#include <conio.h>
#include <limits>

using namespace std;

class Calculator{
    private:
        int res = 0;
        
        
    public:

        int addition(int num);
        int subtraction(int num);
        int multiplication(int num);
        int division(int num);
        void getResult();
};

int Calculator::addition(int num){
    res += num;
    getResult();
    return res;
}

int Calculator::subtraction(int num){
    res -= num;
    getResult();
    return res;
}

int Calculator::multiplication(int num){
    res *= num;
    getResult();
    return res;
}

int Calculator::division(int num){
    if (num != 0) {
        res /= num;
    } else {
        cout << "Error: Division by zero." << endl;
    }
    getResult();
    return res;
}

void Calculator::getResult(){
    cout << "Result: " << res << endl;
}


int main()
{
    Calculator c;
    
    char op;
    
    int n;
    
    while (true){
        
        c.getResult();
        cout << "Enter a number: ";
        if (!(cin >> n)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }
        
        cout << "Enter an operation (+, - , *, /, =): ";
        cin >> op;
        switch(op){
            case '+':
                c.addition(n);
                break;
            case '-':
                c.subtraction(n);
                break;
            case '*':
                c.multiplication(n);
                break;
            case '/':
                c.division(n);
                break;
            case '=':
                c.getResult();
                return 0;
            default:
                cout << "Invalid Operation";
                break;
        }
        cout << "\n\n---------------------------------------------\n\n";
    }

    return 0;
}