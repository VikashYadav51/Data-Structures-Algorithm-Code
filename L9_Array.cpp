#include<iostream>
using namespace std;

// int main(){

//     int arr[8]  ={1,2,3};

//     int n;
//     cout<<"enter the value of n is "<< endl;
//     cin>> n;

//     for(int i=0; i <n; i++){
//         cout<< arr[i]<<" ";
//     }

//     return 0;
// }



///........Linear search........

// int main(){

//     int arr[10] = {2,6,4,8,3,11,16,14,18,20};

//     int key;
//     cout<<"enter the value of key is -> "<< endl;
//     cin>> key;

//     //int number = 0;

//     int n;
//     cout<<"enter the value of n is -> "<< endl;
//     cin>> n;

//     int i = 0;
 
//     while(i < n){
//         if(key==arr[i]){
//             cout<<"the key is persent at index numbe is "<< i << endl;
//         }
//         else{
//             i++;
//         }
//         i++;
//     }     
// }







///........ Reverse a array........

int reverse_array(int arr[], int n){
    int s = 0;
    int e = n - 1;

    while(s <= e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    for(int i = 0; i < n; i++){
        cout<< arr[i]<< ", ";
    }
    return 0;

}

// void print_array(int arr[], int n){

//     for(int i = 0; i < n; i++){
//         cout<< arr[i]<< ", ";
//     }
//     // return 0;
// }

int main(){

    int arr[5] = {1,5,4,9,3};

    int n;
    cout<<"enter the value of n is -> "<< endl;
    cin>> n;

    //int ans = reverse_array(arr,n);

    //print_array(arr,n);

    // cout<< ans << endl;

    reverse_array(arr,n);

    return 0;
}