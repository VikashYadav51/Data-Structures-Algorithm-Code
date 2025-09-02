#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void print_left_view_element_1(Node* &root){
    queue<pair<Node*, int> > q1;

    map<int, int> node;

    vector<int> result;

    if(root==NULL){
        return ;
    }

    q1.push(make_pair(root, 0));

    while(!q1.empty()){
        int size = q1.size();
        vector<int> ans;

        for(int i = 0; i < size; i++){
            pair<Node*, int> temp = q1.front();
            q1.pop();

            Node* Front_Node = temp.first;
            int ld = temp.second;

            if(node.find(ld)==node.end()){
                node[ld] = (Front_Node->data);
                result.push_back(Front_Node->data);
            }

            if(Front_Node->left){
                q1.push(make_pair(Front_Node->left, ld+1));
            }

             if(Front_Node->right){
                q1.push(make_pair(Front_Node->right, ld+1));
            }
        }
        // for(auto i : node){
        //     result.push_back(i.second);
        // }
    }

    for(auto i : result){
        cout<< i <<",  ";
    }
}

void print_left_view_element_2_1(Node* &root, int ld, vector<int> & result, map<int, int> &node){

    if(root==NULL){
        return ;
    }

    if(node.find(ld)==node.end()){
        node[ld] = root-> data;
        result.push_back(root->data);
    }


    print_left_view_element_2_1(root->left, ld+1, result, node);

    print_left_view_element_2_1(root->right, ld+1, result, node);

}

void print_left_view_element_2(Node* &root){
    map<int, int> node;
    int ld = 0;
    vector< int> ans;

    print_left_view_element_2_1(root, ld, ans, node);

    for(auto i : ans){
        cout<< i <<",  ";
    }
}

void print_left_view_element(Node* &root){
    if(root==NULL){
        return ;
    }

    queue<Node* > q1;

    q1.push(root);

    vector<int> result;

    while(!q1.empty()){
        int size = q1.size();

        result.push_back(q1.front()->data);

        for(int i = 0; i < size; i++){
            Node* temp =q1.front();
            q1.pop();

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
        }

    }

    for(auto i : result){
        cout<< i <<",  ";
    }
}


void print_right_view_element(Node* &root){
    if(root==NULL){
        return ;
    }

    queue<Node* > q1;
    q1.push(root);

    vector<int> result;

    while(!q1.empty()){
        int max_size = q1.size();

        for(int i = 0; i < max_size; i++){
            Node* temp = q1.front();
            
            if(i < max_size - 1){
                q1.pop();
            }

            else if(i+1==max_size){
                result.push_back(temp->data);
                q1.pop();
            }


            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }

        }

        // result.push_back(q1.front()->data);
        // q1.pop();

    }

    for(auto i : result){
        cout<< i <<",  ";
    }


}

//  1 2 -1 4 -1 -1 3 -1 5 -1 6 -1 7 -1 8 -1 -1     

int main(){

    Node* root = build_tree();

    //.....Q1

    // cout<< endl << endl;
    // cout<<"Print the left view  element : "<< endl;

    // vector<int> result;
    // int ld = 0;

    // print_left_view_element_1(root);

    // cout<<endl << endl;

    // print_left_view_element_2(root);

    // cout<< endl <<endl;

    // ........Q2

    // print_right_view_element(root);
}
