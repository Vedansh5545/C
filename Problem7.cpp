/*
     How to print Odd or Even Numbers from 1 to 100
*/

#include <iostream>
using namespace std;
int main(){
    cout<<"How to print Odd or Even Numbers from 1 to 100"<<endl;
    cout<<"even numbers"<<endl;
    for(int i=1;i<=100;i++){
        if(i%2==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<"odd numbers"<<endl;
    for(int i=1;i<=100;i++){
        if(i%2!=0){
            cout<<i<<" ";
        }
    }
    return 0;
}