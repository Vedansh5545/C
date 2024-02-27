/*
     Print Table of 2,3,4,5,6,7,8,9,10  C++ Programming
*/

#include<iostream>
using namespace std;

int main()
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            cout<<i*j<<"    ";
        }
        cout<<endl;
    }
    return 0;
}