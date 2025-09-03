#include<iostream>
using namespace std;

// int main(){

//     int n;
//     cout<<"enter the calue of n is -> "<<endl;
//     cin>> n;

//     switch(n){
//         case 10:
//             cout<<"your age is 10 "<< endl;
//             break;

//         case 15:
//             cout<<"your age is 15 "<<endl;
//             break;

//         case 22:
//             cout<<"you are above 20 "<< endl;
//             break;

//         default:
//             cout<<"better luck to next time "<< endl;

//     }

//     return 0;
// }





//.........Function...........///////////

// int noofsetbits(int a){
//     int count = 0;
//     while(a!=0){
//         if((a&1) ==1){
//             count++;
//         }
//         a = a>>1;
//     }
//     return count;
// }

// int main(){

//     int a;
//     cout<<"enter the value of a is -> "<< endl;
//     cin>> a;

//     int b;
//     cout<<"enter the value of b is -> "<< endl;
//     cin>> b;

//     noofsetbits(a);

//     cout<<"total number of setbits are -> "<< noofsetbits(a) << endl;

//     return 0;
// }



///..........Fibbonacchi series.......................//

void Fibbonacchi_Series(int a, int b, int n){
    cout<< a <<" "<< b <<" ";
    // int c = a + b;
    int number;
    cout<<"enter the number "<< endl;
    cin>> number;
    for(int i = 3; i <= n; i++){
        int c = a + b;
        cout<< c <<" ";
        a = b;
        b = c;
        
        // if(number==i){
        //     cout<< c << endl;
        // }

        
        // swap(a,b);
        // swap(b,c);
    }
}

int main(){
   int a = 0;
   int b = 1;

   int n;
   cout<< "enter the value of n is "<< endl;
   cin>> n;

   // cout<< a << b <<" ";

   Fibbonacchi_Series(a, b, n); 
}


