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
    int data;
    cout<<"Enter the data : "<< endl;
    cin>> data ;

    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the left side of "<<data << endl;
    root->left = build_tree();

    cout<<"Enter the data right side of "<< data << endl;
    root->right = build_tree();
}

Node* find_predessor(Node* root){
    Node* temp = root;

    temp = temp->left;

    while(temp->right != NULL && temp->right != root){
        temp = temp->right;
    }

    return temp;
}

void print_preOder_morris_trevarsal(Node* root){
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            cout<< curr->data << "  ";
            curr = curr->right;
        }

        else{
            Node* predessor = find_predessor(curr);
            if(predessor->right==NULL){
                predessor->right = curr;
                curr = curr->left;
            }

            else{
                predessor->right =NULL;
                cout<< curr->data <<"  ";
                curr  = curr->right;
            }  
        }
    }
}

int main(){

    Node* root = build_tree();

    cout<<"Print the data "<< endl;

    print_preOder_morris_trevarsal(root);



}