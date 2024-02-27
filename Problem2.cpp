/*
    Calculator Program in C++ Programming
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    c = a- b;
    cout << a << " - " << b << " = " << c << endl;
    c = a * b;
    cout << a << " * " << b << " = " << c << endl;
    c = a / b;
    cout << a << " / " << b << " = " << c << endl;
    return 0;
}