#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* build_tree(){
    int data;
    cout<<"Enter the data : "<< endl;
    cin>> data;

    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the dta left side of "<< data <<" : "<< endl;
    root->left = build_tree();

    cout<<"Enter the dta right side of "<< data <<" : "<< endl;
    root->right = build_tree();

    return root;
}

pair<int, int> find_sum_of_longest_path(Node* root, int &maxi_sum, int &maxi_length, int sum, int length){
    // base case
    if (root == NULL) {
        return make_pair(maxi_length, maxi_sum);
    }

   
    sum = sum + root->data;
    length = length + 1;

    if (root->left == NULL && root->right == NULL) {
        if (length > maxi_length) {
            maxi_length = length;
            maxi_sum = sum;          
        } else if (length == maxi_length) {
            maxi_sum = max(maxi_sum, sum);
        }
    }

    // recursive calls
    find_sum_of_longest_path(root->left,  maxi_sum, maxi_length, sum, length);
    find_sum_of_longest_path(root->right, maxi_sum, maxi_length, sum, length);

    return make_pair(maxi_length, maxi_sum);
}


vector<int>  Path_first_lca_1(Node* root, vector<int> v1, int n1){
    if(root==NULL){
        return  {};
    }

    if(root->data == n1){
        return  v1;
    }

    v1.push_back(root->data);

     // search left
    vector<int> leftPath = Path_first_lca_1(root->left, v1, n1);
    if (!leftPath.empty()) return leftPath;

    // search right
    vector<int> rightPath = Path_first_lca_1(root->right, v1, n1);
    if (!rightPath.empty()) return rightPath;

    v1.pop_back();

    return {};
}

Node* Find_LCA(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* root_left = Find_LCA(root->left, n1, n2);

    Node* root_right = Find_LCA(root->right, n1, n2);

    if(root_left != NULL && root_right != NULL){
        return root;
    }

    else if(root_left != NULL && root_right==NULL){
        return root->left;
    }

    else if(root_left == NULL && root_right != NULL){
        return root->right;
    }

    else{
        return NULL;
    }

}



int main(){

    Node* root = build_tree();
    cout<<"Maximum Sum of Longest Path ....."<< endl;

    //   1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 

    //...........Q1

    // int maxi_sum = INT32_MIN;
    // int maxi_length = 0;
    // int sum = 0;
    // int length = 0;
    // pair<int, int> ans = find_sum_of_longest_path(root, maxi_sum, maxi_length, sum, length);
    // cout<< ans.second<< endl;
    // return 0;


    // .......Q1.....

    //  1 2 3 -1 -1 4 -1 -1 5 7 -1 -1 6 -1 -1
    // int n1;
    // cout<<"Enter the value of n1 "<< endl;
    // cin>> n1;

    // vector<int> ans = Path_first_lca_1(root, v1, n1);

    // for(auto i : ans){
    //     cout<< i << ",  ";
    // }


    //..........Q2
    // int n1, n2;
    // cout<<"Enter the value of n1 "<< endl;
    // cin>> n1;

    // cout<<"Enter the value of n2 "<< endl;
    // cin>> n2;

    // Node* ans = Find_LCA(root, n1, n2);
    // cout<< ans->data << endl;

    
}