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

void print_vertical_element(Node* &root){

    queue<pair<Node*, pair<int, int> > > q1;

    map<int, map<int, vector<int> > > node;

    vector<int> result;
    
    if(root==NULL){
        return ;
    }

    q1.push(make_pair(root, make_pair(0,0)));

    while(!q1.empty()){
        pair<Node*, pair< int, int> > temp = q1.front();

        q1.pop();

        Node* front_Node = temp.first;

        int hd = temp.second.first;

        int ld = temp.second.second;

        node[hd][ld].push_back(front_Node->data);

        if(front_Node->left){
            q1.push(make_pair(front_Node->left, make_pair(hd-1, ld + 1)));
        }

        if(front_Node->right){
            q1.push(make_pair(front_Node->right, make_pair(hd+1, ld+1)));
        }
    }

    for(auto i : node){

        for(auto j : i.second){

            for(auto k : j.second){

                result.push_back(k);
            }
        }
    }

    for(auto i : result){
        cout<< i <<",  ";
    }
}

void print_top_element(Node* &root){
    queue<pair<Node*, int> > q1;

    map<int, vector<int> > node;

    vector<int> result;

    if(root==NULL){
        return ;
    }

    q1.push(make_pair(root, 0));

    while(!q1.empty()){
        pair<Node*, int> temp = q1.front();

        q1.pop();

        Node* front_Node = temp.first;

        int hd = temp.second;


        if(node.find(hd)==node.end()){
            node[hd].push_back(front_Node->data);
        }

        if(front_Node->left){
            q1.push(make_pair(front_Node->left, hd-1));
        }

        if(front_Node->right){
            q1.push(make_pair(front_Node->right, hd+1));
        }

    }

    for(auto i : node){
        for(auto j : i.second){
            result.push_back(j);
        }
    }

    for(auto i : result){
        cout<< i << ",  ";
    }
}

void print_bottom_view_element(Node* &root){
    queue<pair<Node*, int> > q1;

    map<int, vector<int> > node;

    vector<int> result;

    if(root==NULL){
        return ;
    }

    q1.push(make_pair(root, 0));

    while(!q1.empty()){
        pair<Node*, int> temp = q1.front();

        q1.pop();

        Node* front_Node = temp.first;

        int hd = temp.second;

        node[hd].clear();
        node[hd].push_back(front_Node->data);
        

        if(front_Node->left){
            q1.push(make_pair(front_Node->left, hd-1));
        }

        if(front_Node->right){
            q1.push(make_pair(front_Node->right, hd+1));
        }

    }

    for(auto i : node){
        for(auto j : i.second){
            result.push_back(j);
        }
    }

    for(auto i : result){
        cout<< i << ",  ";
    }
}

vector<int>  print_left_view_of_binary_tree(Node* &root, int level, vector<int> &ans){
    if(root==NULL){
        return ans;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    print_left_view_of_binary_tree(root->left, level+1, ans);

    print_left_view_of_binary_tree(root->right, level+1, ans);

    return ans;
}

void print_left_view_element(Node* &root, int ld){
    map<int, int> node;

    if(root==NULL){
        return ;
    }


    print_left_view_element(root->left, ld+1);

    print_left_view_element(root->right, ld+1);

    if(node.find(ld)==node.end()){
        node[ld] = root-> data;
    }

    vector<int> ans;

    for(auto i : node){
        ans.push_back(i.second);
    }

    for(auto i : ans){
        cout<< i << ",  ";
    }


}
    
int main(){

    Node* root =build_tree();

    //   1 2 4 -1 -1 5 -1 -1 3 6 8 -1 -1 9 -1 10 -1 11 -1 -1 7 -1 -1

    // cout<< endl << endl;

    //......Q1

    // cout<<"Print the element in vertical order "<< endl;
    // print_vertical_element(root);

    //...... Q2

    // cout<< endl << endl;
    // cout<<"Print the top view  element : "<< endl;
    // print_top_element(root);

    //...........Q3.

    // cout<< endl << endl;
    // cout<<"Print the bottom view  element : "<< endl;
    // print_bottom_view_element(root);


    //...........Q4.

    cout<< endl << endl;
    cout<<"Print the left view  element : "<< endl;
    int ld = 0;

    vector<int > ans;
    print_left_view_element(root, ld);

    return 0;
}