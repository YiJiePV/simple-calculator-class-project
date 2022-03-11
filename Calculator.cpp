// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Karena Qian
CSC 1230
Maira Ribas Monteiro
10//2021 (completion)
A Very Simple Calculator Assignment
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
using namespace std;

void PrintGreetings() {
    cout << "+" << setfill('=') << setw(26) << "+" << endl;
    cout << "\|/\\/\\Falcon Calculator/\\/\\\|" << endl;
    cout << "+" << setfill('=') << setw(26) << "+" << endl;
    cout << endl;
}

void PrintByeBye() {
    cout << "Thank you for using Falcon Calculator!" << endl;
}

void PrintMenuError() {
    cout << "The choice is not valid." << endl;
    cout << endl;
}

void PrintCurrentValue(int a) {
    cout << "Current value: " << a << endl;
    cout << endl;
}

int MenuChoice() {
    int userInput;

    cout << "1) Add 2) Subtract 3) Multiply" << endl;
    cout << "4) Divide 5) Modulo 6) Square root" << endl;
    cout << "7) Exit" << endl;

    cout << "Choose Functionality : ";
    cin >> userInput;
    cout << endl;
    
    return userInput;
}

int InputAnotherValue() {
    int userInput;

    cout << "Input another value: ";
    cin >> userInput;
    cout << endl;

    return userInput;
}

int Add(int a, int b) {
    a = InputAnotherValue();
    b = InputAnotherValue();
    return a + b;
}

int Subtract(int a, int b) {
    a = InputAnotherValue();
    b = InputAnotherValue();
    return a - b;
}

int Multiply(int a, int b) {
    a = InputAnotherValue();
    b = InputAnotherValue();
    return a * b;
}

int Divide(int a, int b) {
    a = InputAnotherValue();
    b = InputAnotherValue();
    if (b == 0) {
        return -1;
    }
    else {
        return a / b;
    }
}

int Modulo(int a, int b) {
    a = InputAnotherValue();
    b = InputAnotherValue();
    if (b == 0) {
        return -1;
    }
    else {
        return a % b;
    }
}

int Sqrt(int a) {
    a = InputAnotherValue();
    return sqrt(a);
}

void ErrorCheck(int& a) {
    if (a < 0 || a > 99999) {
        cout << "Calculation Error, resetting..." << endl;
        cout << endl;
        a = 0;
    }
}

//For testing method ErrorCheck
void ErrorCheckTest(int a) {
    cout << endl;
    ErrorCheck(a);
    cout << "Current value: " << a << endl;
}

//Main testing method
int test() {
    int large = 99999; //upper limit
    int small = 0; //lower limit
    int tooSmall = -1; //surpasses lower limit
    int tooLarge = 12034321; //surpasses upper limit

    /*Expected output:
    +=========================+
    |/\/\Falcon Calculator/\/\|
    +=========================+*/
    PrintGreetings();

    /*Expected output:
    Thank you for using Falcon Calculator!*/
    PrintByeBye();

    /*Expected output:
    The choice is not valid.*/
    PrintMenuError();

    /*Expected output:
    Current value: 7*/
    PrintCurrentValue(7);

    /*Expected output:
    1) Add 2) Subtract 3) Multiply
    4) Divide 5) Modulo 6) Square root
    7) Exit
    Choose Functionality: */
    assert(MenuChoice() == 2);

    /*Expected output:
    Input another value: */
    assert(InputAnotherValue() == 19);

    assert(Add(2, 2) == 4);
    assert(Add(13452, 34233) == 47685);

    assert(Subtract(6, 3) == 3);
    assert(Subtract(203, 194) == 9);

    assert(Multiply(5, 5) == 25);
    assert(Multiply(534, 12) == 6408);
    assert(Multiply(12, 534) == 6408);

    assert(Divide(4, 2) == 2);
    assert(Divide(2404, 535) == 4);
    assert(Divide(535, 2404) == 0);
    assert(Divide(10, 0) == -1);

    assert(Modulo(10, 2) == 0);
    assert(Modulo(34053, 22) == 19);
    assert(Modulo(22, 34053) == 22);
    assert(Modulo(234, 0) == -1);

    assert(Sqrt(4) == 2);
    assert(Sqrt(99999) == 316);
    assert(Sqrt(0) == 0);

    /*Expected output:
    Current value: 99999*/
    ErrorCheckTest(large);

    /*Expected output:
    Current value: 0*/
    ErrorCheckTest(small);

    /*Expected output:
    Calculation Error, resetting...
    Current value: 0*/
    ErrorCheckTest(tooSmall);

    /*Expected output:
    Calculation Error, resetting...
    Current value: 0*/
    ErrorCheckTest(tooLarge);

    return 0;
}

//Main program method
int main() {
    //test();
    int menuInput; //for functionality input (idk why the assignment uses the functionality input as the first value in the calcuation XD)
    int userInput1 = 0;
    int userInput2 = 0;
    int current = 0; //for resulting calculations

    PrintGreetings();
    do {
        PrintCurrentValue(current);
        menuInput = MenuChoice();

        if (menuInput == 1) {
            current = Add(userInput1, userInput2);
        }
        else if (menuInput == 2) {
            current = Subtract(userInput1, userInput2);
        }
        else if (menuInput == 3) {
            current = Multiply(userInput1, userInput2);
        }
        else if (menuInput == 4) {
            current = Divide(userInput1, userInput2);
        }
        else if (menuInput == 5) {
            current = Modulo(userInput1, userInput2);
        }
        else if (menuInput == 6) {
            current = Sqrt(userInput1);
        }
        else if(menuInput == 7) {
            PrintByeBye();
        }
        else {
            PrintMenuError();
        }

        ErrorCheck(current);
    } while (menuInput != 7);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
