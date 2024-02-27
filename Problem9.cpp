/*
     Swapping of Two Numbers 
*/

#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Before Swapping: "<<a<<" "<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<"After Swapping: "<<a<<" "<<b<<endl;
    return 0;
}