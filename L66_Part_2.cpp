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

int find_inorder_index(int in[], int element, int in_sIndex, int in_EndIndex){
    for(int i =in_sIndex; i <= in_EndIndex; i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}


Node* create_tree(int in[], int po[], int &size, int post_endIndex, int in_sIndex, int in_EndIndex){

    if(post_endIndex <= 0 || in_sIndex > in_EndIndex){
        return NULL;
    }

    int element = po[post_endIndex--];
    Node* temp = new Node(element);   

    int position = find_inorder_index(in, element, 0, in_EndIndex);

    temp->left = create_tree(in, po, size, post_endIndex, in_sIndex, position-1);

    temp->right = create_tree(in, po, size, post_endIndex,  position+1, in_EndIndex);

    return temp;

}


void print_pre_order(Node* root){
    Node* temp = root;

    if(temp==NULL){
        return ;
    }

    cout<< temp-> data<< "  ";
    
    print_pre_order(temp->left);


    print_pre_order(temp->right);
}

int main(){
    int in[] = {4,2,5,1,3};

    int post[] = {4,5,2,3,1};

    int size = sizeof(in) / sizeof(in[0]);

    int post_endIndex = size - 1;

    // int in_sIndex = 0;
    // int in_EndIndex = size - 1;

    Node* root = create_tree(in, post, size, post_endIndex, 0, size - 1);

    print_pre_order(root);
}
