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


Node* Flatten_BST(Node* &root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
        
    root->right =  Flatten_BST(root->right, data);
    return root;
}
    
void taken_input(Node* &root){
    if(root==nullptr){
        return ;
    }
        
    taken_input(root->left);
  
    int data = root->data;
        
    Flatten_BST(root, data);
        
    taken_input(root->right);
}
    


int main(){
    Node* root = nullptr;
    take_input(root);

    cout<<"Enter the taken input "<< endl;
    taken_input(root);


    cout<<"printhe output using LOT..."<< endl;
    print_LOT(root);
}