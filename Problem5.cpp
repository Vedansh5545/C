/*
    Reverse of Table 2,3,4,5,6,7,8,9,10
*/

#include <iostream>
using namespace std;
int main(){

    for (int i = 10; i >= 1; i--)
    {
        for (int j = 10; j >= 1; j--)
        {
            cout << i * j << " ";
        }
        cout << endl;
        cout << endl;

    }
    


    return 0;
}