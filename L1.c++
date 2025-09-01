#include<iostream>
using namespace std;

// int main(){
//     int n;
//     cout<<"enter the value of n is "<< endl;
//     cin>> n;

//     int number = 1;
//     int sum  = 0;
//     while(number <= n){
//         sum = number + sum;
//         number++;
//     }
//     cout<< "the sum of n is "<< endl;
//     cout<< sum << endl;
// }




// int main(){
//     int n;
//     cout<<"enter the value of n is "<< endl;
//     cin>> n;

//     int number = 1;
//     int factorial  = 1;
//     while(number <= n){
//         factorial = number * factorial;
//         number++;
//     }
//     cout<< "the sum of n is "<< endl;
//     cout<< factorial << endl;
// }




// int main(){

//     int n;
//     cout<<"enter the value of n is "<< endl;
//     cin>> n;

//     int i = 2;

//     while( i < n){
//         if(n / i == 0){
//             cout<<"this is not the prime "<< i << endl;
//         }

//         else{
//             cout<<"this is the prime "<< i << endl;
//         }
//         i++;
//     }
// }



// bool checkprime(int n, int i){
//     if(n%i==0){
//         return 0;
//     }

//     else{
//         i++;
//     }
//     return 1;
// }

// int main(){

//     int n;
//     cout<<"enter the value of n is "<< endl;
//     cin>> n;


//     int i = 2;

//     checkprime(n, i);

//     cout<< "this  number is prime or not "<< checkprime(n, i) << endl;
     
// }

bool check_prime(int n){
    int number = 2;
    while(number < n){
        if(n % number==0 ){
            return 1;
        }
        number++;
    }
    return 0;
}


int main(){
    // int a, b;
    // cout<<"enter the value of a is "<< endl;
    // cin>> a;

    // cout<<"enter the value of b is "<< endl;
    // cin>> b;

    // cout<<"the sum of a and b is "<< endl << a + b << endl;



    int n;
    cout<<"enter the value of n is "<< endl;
    cin>> n;

    // int number = 2;
    // while(number<n){
    //     if(n%number==0){
    //        cout<<"given number is not prime number "<< endl;
    //        break;
    //     }
    //     else{
    //         cout<<"given number is prime number "<< endl;
    //     }
    //     number++;
    // }
    // return 0;


    if(check_prime(n)){
        cout<<"given number is not prime number "<< endl;

    }

    else{
        cout<<"given number is prime number "<< endl;
    }


}



