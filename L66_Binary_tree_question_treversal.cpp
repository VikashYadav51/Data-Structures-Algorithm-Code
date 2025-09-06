#include<iostream>
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
    cout<<"Enter the data : "<< endl;
    int data;
    cin>> data;

    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"ENter the data left side of "<< data << endl;
    root->left = build_tree();

    cout<<"Enter the data right side of "<< data << endl;
    root->right = build_tree();

    return root;
}


int Find_position(int inOrder[], int inorder_Sindex, int inorder_eindex,  int element){
    for(int i = inorder_Sindex; i <= inorder_eindex; i++){
        if(element==inOrder[i]){
            return i;
        }
    }
    return -1;
}

Node* create_tree(int in[], int pre[], int &index, int inOrder_index, int inOrder_endIndex, int n){

    if(index >= n || inOrder_index > inOrder_endIndex){
        return NULL;
    }

    int element = pre[index++];
    Node* temp = new Node(element);

    int pos = Find_position(in, inOrder_index,inOrder_endIndex, element);

    temp->left = create_tree(in, pre, index, inOrder_index , pos - 1, n);

    temp->right = create_tree(in, pre, index, pos+1, inOrder_endIndex, n);

    return temp;
}

void print_post_order(Node* root){
    Node* temp = root;

    if(root==NULL){
        return ;
    }

    print_post_order(temp->left);

    print_post_order(temp->right);

    cout<< temp->data <<"  ";
}

int main(){
    int in[] = {3,1,4,0,5,2};

    int pre[] = {0,1,3,4,2,5};

    int size = sizeof(in) / sizeof(in[0]);

    int pre_order_index = 0;

    Node* temp = create_tree(in, pre, pre_order_index, 0, size-1, size);

    cout<<"Print the data in post order "<< endl;

    print_post_order(temp);
}