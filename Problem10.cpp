/*
     Swapping of Two Numbers using only 2 Variables
*/
#include <iostream>

using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"After Swapping: "<<a<<" "<<b;
    return 0;
}