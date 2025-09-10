#include<iostream>
#include<vector>
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

Node* Construct_BST(Node* &root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = Construct_BST(root->left, data);
    }

    else{
        root->right = Construct_BST(root->right, data);
    }

    return root;
}

void take_input(Node* &root){
    int data;
    cout<<"Enter the data ...."<< endl;
    cin>> data;

    while(data != -1){
        root = Construct_BST(root, data);
        cin>> data;
    }
}


//...................Check the given tree BST is or not........Approach(1)..........

void print_Inorder(Node* &root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        
        print_Inorder(root->left, ans);
        
        ans.push_back(root->data);
        
        print_Inorder(root->right, ans);
        
    }
    
bool Check_BST(vector<int> &arr, int size){
    if(size == 0){
        return false;
    }
        
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
            break;
        }
    }
    return true;
}


//..............................Approach(2)............

bool is_BST(Node* root, int mini, int maxi){
    if(root ==nullptr){
        return true;
    }

    if((root->data > mini) && (root->data < maxi) ){
        bool left = is_BST(root->left, mini, root->data);
        bool right = is_BST(root->right, root->data, maxi);
        return left &&  right;
    }
    
    return  false;
}


//...............................Q(3)...............Find Predessor ans successor element.......

int find_maxi_element(Node* root){
    if(root == nullptr){
        return -1;
    }

    if(root->left == nullptr && root->right == nullptr){
        return root->data;
    }

    if(root->left != nullptr && root->right == nullptr){
        return root->data;
    }

    return find_maxi_element(root->right);
}

int find_mini_element(Node* root){
    if(root == nullptr){
        return -1;
    }

    if(root->left == nullptr && root->right == nullptr){
        return root->data;
    }

    if(root->left == nullptr && root->right != nullptr){
        return root->data;
    }

    return find_mini_element(root->left);
}

void find_key(Node* root, int target, int &pre, int &succ){
    if(root == nullptr){
        return ;
    }

    if(target == root->data){

        if(root->left != nullptr){
            pre = find_maxi_element(root->left);
        }

        if(root->right != nullptr){
            succ = find_mini_element(root->right);
        }

        return ;
    }

    else if(target < root->data){
        succ = root->data;
        find_key(root->left, target, pre, succ);
    }

    else{
        pre = root->data;
        find_key(root->right, target, pre, succ);
    }
}


//.................................Q(4)................Lowest Common Anchestor....in BST.......

Node* find_key(Node* root, Node* target, vector<Node*> &nums1){
    if(root == nullptr){
        return nullptr;
    }
        
    nums1.push_back(root);
        
    if(target->data == root->data){
        return root;
    }
        
    if(target->data < root->data){
        root->left = find_key(root->left, target, nums1);
    }
        
    else{
        root->right = find_key(root->right, target, nums1);
    }
        
    return root;
}
    
Node* LCA_BST(vector<Node* > nums1, vector<Node* > nums2, int size1, int size2){
    Node* ans = nullptr;
        
    int i = 0; 
    int j = 0;
        
    while(i < size1 && j < size2){
        if(nums1[i]->data == nums2[j]->data){
            ans = nums1[i];
        }
        i++;
        j++;
    }
        
    return ans;
}



int main(){
    Node* root = nullptr;
    cout<<"Enter the data in take input function..."<< endl;
    take_input(root);

    //...................Q(3)..............

    // int pre = -1;
    // int succ = -1;
    // int target;
    // cout<<"Enter the target :"<< endl;
    // cin>> target;

    // cout<<"predessor and successor element is "<< endl;
    // find_key(root, target, pre, succ);
    // cout<< pre <<"  "<< succ <<endl;

    //............Q(4)......................










}