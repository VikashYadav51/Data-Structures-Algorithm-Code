#include<iostream>
using namespace std;

//..........Selection Sorting Algorithms.....
/* Sorting is a method or technique where we have sort the array using diffrent diffrent sorting algorithms.  */

/* Selection Sorting is method where we have sort the array in assending or desending order firstly we have  tookthe by comparison  one lowest or biggest element in 
        unsorted array  and movwe it to sorted part......*/

void selection_sorting(int arr[], int size){
    if(size == 0 || size ==1){
        return ;
    }

    for(int i = 0; i < size; i++){
        int index = i;
        for(int j = i+1; j < size; j++){
            if(arr[index] > arr[j]){
                index = j;
            }
        }
        swap(arr[index], arr[i]);
    }
}

//........................bubble sorting ..........//.......

/* in bubble sorting we sort the array by comparison the adajcent element.....*/

void bubble_sorting(int arr[], int size){
    if(size == 0 || size == 1){
        return ;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

/* ............Insertion Sorting..................*/

void insertion_sorting(int arr[], int size){
    if(size==0 || size==1){
        return ;
    }

    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j =i - 1;

        while( j >= 0){
            if(arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }
         
        }
        arr[j+1] = key;
    }

}

int main(){
    int arr[6] = {11,3,6,2,5,1};
    int size = 6;
    // selection_sorting(arr, size);
    // cout<<"After Selection sorting the element -> "<< endl;

    // for(int i = 0; i < size; i++){
    //     cout<< arr[i]<<"  ";

    // } 

    // bubble_sorting(arr, size);
    // cout<<"After bubble sorting the element -> "<< endl;
    // for(int i = 0; i < size; i++){
    //     cout<< arr[i]<<"  ";

    // }
    


    insertion_sorting(arr, size);
    cout<<"After Insertion sorting the element -> "<< endl;
    for(int i = 0; i < size; i++){
        cout<< arr[i]<<"  ";

    }

}




