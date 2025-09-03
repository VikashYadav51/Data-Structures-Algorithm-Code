#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){

    ///////////////////.............convert  Decimal into binary.........///////////////////

    vector<int> v;

    int n;
    cout<<"enter the value of n is "<< endl;
    cin>> n;

    // int remainder = 0;

    // while(n!=0){
    //     // remainder = n % 2;
    //     cout<< (n % 2) << " ";.............................((n & 1)==(n % 2))
    //     n = (n>> 1);
    // }



    //........... Print the binary number is .........................

    // while(n!=0){
    //     remainder = n % 2;
    //     v.push_back(remainder);
    //     n = (n>> 1);
    // }

    // cout<< v.size()<< endl;

    // for(int i = v.size() - 1; i >=0; i--){
    //     cout<< v[i]<< " ";
    // }




    /////////////////..............Binary convert to Decimal.......///////////////// 

    int ans = 0;
    int digit ;
    int i = 0;
    while(n!=0){

        digit = n % 10;
        if((digit & 1)==1){
            ans = ans + pow(2,i);
        }

        n = n /10;
        i++;
    } 
    cout<<"the decimal number is "<< ans << endl;




}



