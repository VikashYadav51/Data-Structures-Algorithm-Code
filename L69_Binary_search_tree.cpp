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

//............Construct the binary Search tree........................

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

//.................................Print the binary search tree..................
void print_LOT(Node* root){
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

//........................................Print the inorder element..........
void print_inOrder(Node* root){
    Node* temp = root;

    if(temp==NULL){
        return ;
    }

    print_inOrder(temp->left);

    cout<< temp->data << "  ";

    print_inOrder(temp->right);
}

void print_preOrder(Node* root){
    Node* temp = root;

    if(temp==NULL){
        return ;
    }

    cout<< temp->data << "  ";

    print_preOrder(temp->left);

    print_preOrder(temp->right);
}

void print_postOrder(Node* root){
    Node* temp = root;

    if(temp==NULL){
        return ;
    }

    print_postOrder(temp->left);

    print_postOrder(temp->right);

    cout<< temp->data << "  ";
}


bool Search_BST(Node* root, int target){
    if(root == nullptr){
        return false;
    }
    
    if(root->data == target){
        return true;
    }

    if(target < root->data){
        bool check_left = Search_BST(root->left, target);
    }
    else{
        bool check_right = Search_BST(root->right, target);
    }
}

int find_minimum_value(Node* root){

    //..................................Approach(1)...........using recursion....
    // if(root==nullptr){
    //     return 0;
    // }

    // if(root->left == nullptr && root->right ==nullptr){
    //     return root->data;
    // }

    // if(root->left == nullptr && root->right !=  nullptr){
    //     return root->data;
    // }

    // find_minimum_value(root->left);

    //.......................................Approach(2)................using iterative way.....

    Node* temp = root;
    while(temp->left!= nullptr){
        temp = temp->left;
    }
    return temp->data;

}

Node* delete_node(Node* &root, int target){
    if(root==nullptr){
        return root;
    }

    if(root->data == target){
        //..........0 Child...

        if(root->left==nullptr && root->right==nullptr){
            delete root;
            root =nullptr;
            return nullptr;
        }

        //..........1 Child.........

        if(root->left != nullptr && root->right == nullptr){
            Node* temp = root->left;
            delete root;
            root = nullptr;
            return temp;
        }

        if(root->left == nullptr && root->right != nullptr){
            Node* temp = root->right;
            delete root;
            root = nullptr;
            return temp;
        }

        //..........2 Child..........

        if(root->left != nullptr && root->right != nullptr){
            int mini = find_minimum_value(root->right);
            root->data = mini;
            root->right = delete_node(root->right, mini);
            return root; 
        }
    }

    else if(target < root->data){
        root->left = delete_node(root->left, target);
        return root;
    }

    else{
        root->right = delete_node(root->right, target);
        return root;
    }

    return root;
}

int main(){
    Node* root = nullptr;

    cout<<"Enter the data in take input Function..."<< endl;
    take_input(root);

    cout<<"Print the data in LOT order before deletion  : "<< endl;
    print_LOT(root);

    // cout<< endl;

    // cout<<"print the data in inorder way "<< endl;
    // print_inOrder(root);
    // cout<< endl;

    // cout<<"print the data in preorder way "<< endl;
    // print_preOrder(root);
    // cout<< endl;

    // cout<<"print the data in postorder way "<< endl;
    // print_postOrder(root);
    // cout<< endl;



    // int target;
    // cout<<"Enter the target "<< endl;
    // cin>> target;

    // bool ans = Search_BST(root, target);
    // if(ans){
    //     cout<<"Target is persent in tree "<< endl;
    // }

    // else{
    //     cout<<"Target is not persent in tree "<< endl;
    // }

    // cout<<"Minimum value in BST "<< endl;
    // int ans = find_minimum_value(root);
    // cout<< ans << endl;



    int target;
    cout<<"Enter the target "<< endl;
    cin>> target;

    root = delete_node(root, target);

    cout<<"After deletion the target node BST  is "<< endl;
    print_LOT(root);


}



