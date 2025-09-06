#include<iostream>
#include<map>
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
    cout<<"Enter the data : "<< endl;
    cin>> data;

    Node * root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter teha data left side of "<< data << endl;
    root->left =build_tree();

    cout<<"Enter the data right side of "<< data << endl;
    root->right = build_tree();

    return root;
}

Node* Create_parent_mapping(Node* &root, int target, map<Node*, Node*> &nodeToparent){
    queue<Node* > q1;
    Node* res = NULL;
    q1.push(root);
    nodeToparent[root] = NULL;

    while(!q1.empty()){
        Node* temp = q1.front();
        q1.pop();

        if(temp->data==target){
            res = temp;
        }

        if(temp->left){
            q1.push(temp->left);
            nodeToparent[temp->left] = temp;
        }

        if(temp->right){
            q1.push(temp->right);
            nodeToparent[temp->right] = temp;
        }
    }

    return res;
}

int burn_tree(Node* root, map<Node*, Node*> &nodeToparent){
    map<Node*, bool> visited;
    queue<Node* > q1;

    q1.push(root);

    visited[root] = true;

    int ans = 0;

    while(!q1.empty()){
        int size = q1.size();
        bool flag = 0;
        for(int i = 0; i < size; i++){
            Node* temp = q1.front();
            q1.pop();

            if(temp->left && !visited[temp->left]){
                flag = 1;
                q1.push(temp->left);
                visited[temp->left] = 1;
            }

            if(temp->right && !visited[temp->right]){
                flag = 1;
                q1.push(temp->right);
                visited[temp->left] = 1;
            }

            if(nodeToparent[temp] && !visited[nodeToparent[temp]]){
                flag = 1;
                q1.push(nodeToparent[temp]);
                visited[nodeToparent[temp]] = 1;
            }
        }

        if(flag==1){
            ans++;
        }

    }

    return ans;
}


int main(){

    Node* root = build_tree();

    int target;
    cout<<"Enter the target : "<< endl;
    cin>> target;

    map<Node*, Node*> nodeToparent;

    Node* target_node = Create_parent_mapping(root, target, nodeToparent);

    int ans = burn_tree(target_node, nodeToparent);

    cout<<"Minimum time to taken to burn the complete entire tree : "<< endl;

    cout<< ans << endl;

}