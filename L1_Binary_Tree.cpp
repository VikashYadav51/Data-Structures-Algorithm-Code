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
        this->left = NULL;
        this->right = NULL;
    }
};


Node* build_tree(){
    int data;
    cout<<"Enter the Node value "<< endl;
    cin>> data;

    Node* root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter the data left side of "<< data << " : "<< endl;
    root->left = build_tree();

    cout<<"Enter the data left side of "<< data << " : "<< endl;
    root->right = build_tree();
    
}

void print_tree_element(Node* root){
    queue<Node* > q1;

    q1.push(root);

    while(!q1.empty()){
        Node* temp = q1.front();
        q1.pop();

        cout<< temp->data<<"  ";

        if(temp->left){
            q1.push(temp->left);
        }

        if(temp->right){
            q1.push(temp->right);
        }
    }
}

void print_data_lot(Node* root){
    queue<Node* > q1;
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

void print_inOder(Node* root){
    if(root==nullptr){
        return ;
    }

    print_inOder(root->left);

    cout<< root->data<< "  ";

    print_inOder(root->right);
}

void print_preOrder(Node* root){
    if(root==nullptr){
        return ;
    }

    cout<< root->data << "  ";

    print_preOrder(root->left);

    print_preOrder(root->right);


}

void print_postOrder(Node* root){
    if(root==nullptr){
        return ;
    }

    print_postOrder(root->left);

    print_postOrder(root->right);

    cout<< root->data <<"  ";
}

int main(){
    Node* root = nullptr;
    root = build_tree();

    //.................Q(1).........Approach(1)................

        // cout<<"print the tree data for method 1: "<< endl;
        // print_tree_element(root);

    //.............................Approach(2)...................

        // cout<<"Print hte tree data according to level wise order "<< endl;
        // print_data_lot(root);

    //..................Q(2)..........InOrder element.............

        cout<<"Print the tree element in inorder way "<< endl;
        print_inOder(root);
        cout<< endl<< endl;

    //...................Q(3)...........PreOrder element............

        cout<<"Print the tree element in preorder way "<< endl;
        print_preOrder(root);
        cout<< endl<< endl;

    //......................Q(4)..........PostOrder element..........

        cout<<"Print the element in post Order way "<< endl;
        print_postOrder(root);
        cout<< endl<< endl;
        
    return 0;
}