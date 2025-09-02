#include<iostream>
#include<queue>
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

    cout<<"Enter the data left side of "<< data << endl;
    root->left = build_tree();

    cout<<"Enter the data right side of "<< data << endl;
    root->right = build_tree();

    return root;

}

void print_Zig_Zag_element(Node* &root){
    queue<Node* > q1;

    vector<int> result;

    if(root==NULL){
        return ;
    }

    q1.push(root);

    bool left_to_right = true;

    while(!q1.empty()){
        int size = q1.size();
        vector<int> v1(size);
        for(int i = 0; i < size; i++){
            Node* temp = q1.front();
            q1.pop();

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
            int index;

            if(left_to_right){
                index = i;
            }
            else{
                index = size - i - 1;
            }

            v1[index] = temp->data;
        }

        left_to_right = ! left_to_right;

        for(auto i : v1){
            result.push_back(i);
        }
    }

    for(auto i  :result){
        cout<< i <<",  ";
    }
}

void print_left_Node(Node* &root){
    Node* temp = root;

    if(temp->left==NULL){
        return ;
    }

    cout<< temp->data << ",  ";

    print_left_Node(temp->left);
}


void print_leaves_Node(Node* &root){
    Node* temp = root;

    if(root==NULL){
        return ;
    }

    print_leaves_Node(temp->left);

    print_leaves_Node(temp->right);

    if(temp->left==NULL  && temp->right==NULL){
        cout<< temp->data<<",  ";
    }
}

void print_right_Node(Node* &root){
    Node* temp = root;

    if(temp->right==NULL){
        return ;
    }

    cout<< temp->data << ",  ";

    print_right_Node(temp->right);
}





int main(){

    Node* root =build_tree();

    //  1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1 

    //.......Q1

    // cout<< endl << endl; 
    // cout<<"Print the data in Zig Zag order "<< endl;
    // print_Zig_Zag_element(root);

    //.......Q2

    // cout<< endl<< endl;
    // cout<<"print only left Node "<< endl;
    // print_left_Node(root);

    //.......Q3

    // cout<< endl<< endl;
    // cout<<"print only leaves Node "<< endl;
    // print_leaves_Node(root);

    //.......Q4


    // cout<< endl<< endl;
    // cout<<"print only right Node "<< endl;
    // print_right_Node(root);

    return 0;
}
