#include<iostream>
#include<vector>
using namespace std;

void Rotate_array(vector<int> arr, vector<int> &nums, int size, int k, int n){

    //........................Approach(1)..........extra Space (n)........T.C.....O(1)........
    // int start = 0;
    // int end = size - k;
    // int index = size - k;

    // while(end < size){
    //     nums.push_back(arr[end]);
    //     end++;
    // }

    // while(start < index){
    //     nums.push_back(arr[start]);
    //     start++;
    // }

    //....................Approach(2).........O(n)..........(1)...........

    // k%=n;
    // reverse(nums.begin(),nums.end());
    // reverse(nums.begin(),nums.begin()+k);
    // reverse(nums.begin()+k,nums.end());



}

bool check(vector<int>& nums, int n) {
        int count = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }

        if(nums[n-1] > nums[0]){
            count++;
        }

        cout << count<< endl;

        if(count <= 1){
            return true;
        }

        return false;
}

int maximumAndValue(vector<int> &arr, int size){   
    int start = 0; 
    int end = size - 1;
        
    int value;
    int maxiValue = 0;
        
    while(start < size && start< end){
        if(start < end){
            value = (arr[start] & arr[end]);
            end--;
        }

        maxiValue = max(value, maxiValue);
            
        if(start == end -1){
            start = start+1;
            end = size - 1;
        }
    }
    return maxiValue;
}

void pushZerosToEnd(vector<int>& arr) {
        int start = 0;
        int end = start+1;
        
        int size = arr.size();
        
        while(start < size && start < end && end < size){
            if((arr[start]==0)  && arr[end] != 0){
                swap(arr[start], arr[end]);
                start = start+1;
                // end = start + 1;
                end++;
                
            }
            
            if(arr[start] != 0 ){
                start++;
                end = start + 1;
                // end++;
            }
            
            if(arr[end]==0){
                end++;
            }
        }
        
}

int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        
        int maxiSum1 = 0;
        int maxiSum2 = 0;
        
        int i = 0;
        int j = 0;
        
        int maxiSum = 0;
        
        while(i < size1 && j < size2){
            if(arr1[i] > arr2[j]){
                maxiSum2 = maxiSum2 + arr2[j];
                j++;
            }
            
            else if(arr1[i] < arr2[j]){
                maxiSum1 = maxiSum1 + arr1[i];
                i++;
            }
            
            else{
                maxiSum = maxiSum + max(maxiSum1, maxiSum2) + arr1[i] ;
                maxiSum1 = 0;
                maxiSum2 = 0;
                i++;
                j++;
            }
        }
        // cout <<"MaxiSum "<< maxiSum << endl;
        
        while(i < size1){
            maxiSum1 = maxiSum1 + arr1[i];
            i++;
        }
        
        while(j < size2){
            maxiSum2 = maxiSum2 + arr2[j];
            j++;
            
        }
        
        maxiSum = maxiSum + max(maxiSum1, maxiSum2);
        
        return maxiSum;
        
}


vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        int i = arr1.size() -1;
        int j = arr2.size() - 1;
        int digit = 0;
        
        vector<int> nums;
        
        while(i >= 0 && j >= 0){
            int sum = arr1[i] + arr2[j] + digit;
            int bit = sum % 10;
            nums.push_back(bit);
            digit = sum / 10;
            i--;
            j--;
        }
        
        while(i >= 0 && j <0){
            int sum = arr1[i]+digit;
            int bit = sum % 10;
            nums.push_back(bit);
            digit = sum / 10;
            i--;
            
        }
        
        while(j >= 0 && i < 0){
            int sum = arr2[j]+digit;
            int bit = sum % 10;
            nums.push_back(bit);
            digit = sum / 10;
            j--;
        }
        
        if(digit){
            nums.push_back(digit);
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        
        return nums;
        
}

vector<int> increment(vector<int> arr, int N) {
        int size = arr.size();
        
        bool carry = true;
        for(int i = size-1; i>=0; i--){
            if(arr[i] < 9 &&  carry){
                arr[i] = arr[i]+1;
                carry = false;
                break;
            }
                
            if(arr[i]==9 && carry){
                arr[i] = 0;
                carry = true;
            }
        }
            
        if(carry){
            arr[0] = 1;
            arr.resize(size+1);//.............this line is important.......{9,9,9,,9} this case is only possibele
            size = arr.size();
            arr[size-1] = 0;
            
        }
        return arr;
        
}

vector<int> addToArrayForm(vector<int>& num, int k) {
        int size = num.size();
        int  ans = 0;
        int i = size -1;
        int carry = 0;
        vector<int> nums;

        while(i >= 0 || k> 0 || carry){
            ans = carry;
            if(i>=0){
                ans = ans +  num[i];
                i--;
            }

            if(k > 0 ){
                ans = ans + k % 10;
                k = k / 10;
            }
            
            carry = ans /10;

            nums.push_back(ans % 10);
        }

        // reverse(nums.begin(), nums.end());

        return nums;

}

int main(){


}