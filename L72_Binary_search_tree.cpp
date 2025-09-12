#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
};


Node* Construct_BST(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = Construct_BST(root->left, data);
    }

    if(data > root->data){
        root->right = Construct_BST(root->right, data);
    }

    return root;

}

void take_input(Node* &root){
    int data;
    cout<<"Enter the data : "<< endl;
    cin>> data;

    while(data != -1){
        root = Construct_BST(root, data);
        cin>> data;
    }
}

void print_LOT(Node* &root){
    queue<Node* > q1;
    if(root==nullptr){
        return ;
    }

    q1.push(root);

    while(!q1.empty()){
        int size = q1.size();
        for(int i = 0; i < size; i++){
            Node* temp = q1.front();
            q1.pop();

            cout<< temp->data <<"  ";

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
        }

        cout<< endl;
    }
}

Node* construct_BST(){

}

void merge_two_BST(Node* root, int arr1[], int arr2[], int size1, int size2){

}

int main(){
    int arr1[7] = {1,2,3,4,5,6,7};

    int arr2[10] = {11,12,13,14,15,16,17,18,19,20};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node* root = nullptr;

    take_input(root);

    merge_two_BST(root, arr1, arr2, size1, size2);

    

    return 0;
}