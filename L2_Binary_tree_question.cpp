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

void Calculate_maximum_height(Node* root, int &maxi_height, int height){

    if(root==NULL){
        if(maxi_height < height){
            maxi_height = height;
        }
        return ;
    }

    Calculate_maximum_height(root->left, maxi_height, height++);

    Calculate_maximum_height(root->right, maxi_height, height++);
}

int maximum_height_2(Node* root){
    if(root==nullptr){
        return 0;
    }

    int op1 = maximum_height_2(root->left);

    int op2 = maximum_height_2(root->right);

    return max(op1, op2) + 1;
}

void minimum_height(Node* root, int &miniHeight, int height){
    if(root==nullptr){
            return ;
        }

        height = height + 1; //.....that line is important.........
            
        if(root->left ==nullptr && root->right ==nullptr){
            if(height < miniHeight){
                miniHeight = height;
            }
            return ;
        }

        minimum_height(root->left, miniHeight, height);

        minimum_height(root->right, miniHeight, height);
}


int maximum_diamter(Node* root){
    if(root==nullptr){
        return 0;
    }

    int op1 = maximum_diamter(root->left);

    int op2 = maximum_diamter(root->right);

    int op3 = maximum_height_2(root ->left) + maximum_height_2(root->right) + 1;

    return max(op1, max(op2, op3));

}

pair<int, int> maximum_diamter_1(Node* root){
    if(root==nullptr){
        return make_pair(0,0);
    }

    pair<int, int> left = maximum_diamter_1(root->left);

    pair<int, int> right = maximum_diamter_1(root->right);

    int op1 = left.first;

    int op2 = right.first;

    int op3 = (left.second + right.second) + 1;

    pair<int, int> result;

    result.first = max(op1, max(op2, op3));

    result.second = max(left.second, right.second) + 1;

    return result;
}


bool check_tree_balance(Node* root){
    if(root==nullptr){
        return true;
    }

    if(root->left==nullptr && root->right ==nullptr){
        return true;
    }

    bool op1 = check_tree_balance(root->left);

    bool op2 = check_tree_balance(root->right);

    int height_diffrence = abs(maximum_height_2(root->left) - maximum_height_2(root->right));

    if(op1 && op2  && (height_diffrence <= 1)){
        return true;
    }

    else{
        return false;
    }
}

pair<bool, int> check_tree_balance_2(Node* root){
    if(root==nullptr){
        return make_pair(true, 0);
    }

    if(root->left ==nullptr && root->right == nullptr){
        return make_pair(true, 1);
    }

    pair<bool, int>  left = check_tree_balance_2(root->left);

    pair<bool, int> right = check_tree_balance_2(root->right);

    bool op1 = left.first;

    bool op2 = right.first;

    int op3 = abs(left.second - right.second);

    if(op1 && op2 && op3 <=1){
        return make_pair(true, max(left.second , right.second)  + 1);
    }

    else{
        return make_pair(false, max(left.second , right.second)  + 1);
    }

}

int calculate_Sum(Node* root){
    if(root==nullptr){
        return 0;
    }

    int op1 = calculate_Sum(root->left);

    int op2 = calculate_Sum(root->right);

    return (op1 + op2 + root->data);
}


bool check_sum_tree(Node* root){
    if(root==nullptr){
        return true;
    }

    if(root->left==nullptr && root->right ==nullptr){
        return true;
    }

    bool op1 = check_sum_tree(root->left);

    bool op2 = check_sum_tree(root->right);

    int value = calculate_Sum(root->left) + calculate_Sum(root->right);

    if(op1 && op2 && (value==root->data)){
        return true;
    }

    else{
        return false;
    }
}

pair<bool, int> check_sum_tree_1(Node* root){
    if(root==nullptr){
        return make_pair(true, 0);
    }

    if(root->left==nullptr && root->right ==nullptr){
        return make_pair(true, root->data);
    }

    pair<bool, int> left = check_sum_tree_1(root->left);

    pair<bool, int> right = check_sum_tree_1(root->right);

    bool op1 = left.first;

    bool op2 = right.first;

    int op3 = left.second + right.second ;

    if(op1 && op2 && (root->data == op3)){
        return make_pair(true, 2 * root->data);
    }

    else{
        return make_pair(false, 2 * root->data);
    }
}





int main(){

    Node* root = build_tree();

    //   1  2 3 -1 5 -1 -1 4 -1 6 7 -1 -1 -1 8 -1 9 10 -1 -1 -1

    //.......Q1........Approach(1)......................Maximum height

        // cout<<"Maximum height of tree is "<< endl;
        // int maxi_height = 0;
        // Calculate_maximum_height(root, maxi_height, 0);
        // cout<< maxi_height;

    //..........................Approach(2).....................

        // cout<<"Maximum height of tree is "<< endl;
        // int ans = maximum_height_2(root);
        // cout<< ans << endl;

    //............Q2........Approach(1)..............Minimum Height

        // cout<<"Calculate the minimum height of tree is"<< endl;
        // int miniHeight = INT32_MAX;
        // minimum_height(root, miniHeight, 0);
        // cout<< miniHeight << endl;


    //............Q3...........Approach(1).........Maximum diamter

        // cout<<"Maximum Diamter is "<< endl;
        // pair<int, int> ans = maximum_diamter_1(root);
        // cout<< ans.first<< endl;

    //.............Q4..............Approach(1)..........tree is balance.....

        // cout<<"check the tree is balance or not "<< endl;
        // bool ans = check_tree_balance(root);
        // if(ans){
        //     cout<<"Given tree is a balance tree "<< endl;
        // }

        // else{
        //     cout<<"Given tree is not a balance tree "<< endl;
        // }

    //..............Q4..............Approach(2)...................

            // pair<bool, int> ans = check_tree_balance_2(root);
            // if(ans.first){
            //     cout<<"Given tree is a balance tree "<< endl;
            // }

            // else{
            //     cout<<"Given tree is not a balance tree "<< endl;
            // }


    //..............Q5...................Approach(1)..................

        // bool ans =check_sum_tree(root);

        // if(ans){
        //     cout<<"Given tree is sum tree "<< endl;
        // }

        // else{
        //     cout<<"Giben tree is not a sum tree "<< endl;
        // }

        // pair<bool, int> ans = check_sum_tree_1(root);
        // if(ans.first){
        //     cout<<"Given tree is sum tree "<< endl;
        // }

        // else{
        //     cout<<"Giben tree is not a sum tree "<< endl;
        // }

}
