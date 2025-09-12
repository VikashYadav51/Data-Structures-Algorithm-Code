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

Node* build_tree(){
    int data;
    cout<<"Enter the data "<< endl;
    cin>> data;

    Node* root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter the data left side of "<< data <<" : "<< endl;
    root->left = build_tree();

    cout<< "Enter the data right side of "<< data <<" : "<< endl;
    root->right = build_tree();

    return root;
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

class information{
    public:
    int maxi_data;
    int mini_data;
    bool is_BST;
    int maxi_size;


};

information Calculate_maxi_size_BST(Node* &root, int &size){
    if(root == nullptr){
        return {INT32_MIN, INT32_MAX,true, 0};
    }

    information left =  Calculate_maxi_size_BST(root->left, size);

    information right = Calculate_maxi_size_BST(root->right, size);

    information currNode;

    currNode.maxi_size = left.maxi_size + right.maxi_size + 1;
    currNode.maxi_data = max(root->data, right.maxi_data);
    currNode.mini_data = min(root->data, left.mini_data);

    if((left.is_BST) && (right.is_BST) && (root->data > left.maxi_data) && (root->data < right.mini_data)){
        currNode.is_BST = true;
    }

    else{
        currNode.is_BST = false;
    }

    if(currNode.is_BST){
        size = max(size, currNode.maxi_size);
    }
    else{
        return currNode;
    }
}

int main(){
    Node* root = nullptr;
    root = build_tree();

    int maxi_size = 0;

    Calculate_maxi_size_BST(root, maxi_size);

    cout<<"Maximum size of BST "<< maxi_size<< endl ;


}