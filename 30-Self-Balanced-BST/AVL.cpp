#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct node{
    int key;
    node *left, *right;
    int height;
    node(int key){
        this->key = key;
        left = nullptr;
        right  = nullptr;
        height = 1;
    }


};

void BFS1(node* root){
    std::queue<node*> q1;
    std::queue<node*> q2;
    q1.push(root);
    while(!q1.empty()){
        while(!q1.empty()){
            node* n = q1.front();
            q1.pop();
            std::cout << n->key << ' ';
            if(n->left != nullptr){
                q2.push(n->left);
            }
            if(n->right != nullptr){
                q2.push(n->right);
            }
        }
        q1.swap(q2);
        std::cout << std::endl;
    }
}

void BFS(node* root){
    std::cout << "bfs" << std::endl;
    std::queue<node*> q1;
    std::queue<node*> q2;
    q1.push(root);
    while(!q1.empty()){
        bool flag = false;
        while(!q1.empty()){
            node* n = q1.front();
            q1.pop();
            if(n != nullptr) {
                if(n->left || n->right) flag = true;
                std::cout << n->key << ' ';
                q2.push(n->left);
                q2.push(n->right);
            } else {
                std::cout << "* ";
                q2.push(nullptr);
                q2.push(nullptr);
            }
        }
        if(flag) q1.swap(q2);
        std::cout << std::endl;
    }
}

int height(node* root){
    return (root == nullptr) ?  0:root->height; 
}

node* left_rot(node* x){
    node* y = x->right;
    x->right = y->left;;
    y->left = x;
    x->height = std::max(height(x->left),height(x->right))+1;
    y->height = std::max(height(y->left),height(y->right))+1;
    return y;
}

node* right_rot(node* x){
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = std::max(height(x->left),height(x->right))+1;
    y->height = std::max(height(y->left),height(y->right))+1;
    return y;
}

node* balance(node* root){
    int diff = height(root->left) - height(root->right);
    if(diff > 1){
        if(height(root->left->right) > height(root->left->left)) root->left = left_rot(root->left);       
        return right_rot(root);
    }
    if(diff < -1){
        if(height(root->right->left) > height(root->right->right)) root->right = right_rot(root->right);
        return left_rot(root);
    }
    return root;  
}

void inorder1(node* root){
    if(root == nullptr) return;
    inorder1(root->left);
    std::cout << root->key << ' ';
    inorder1(root->right);
}

void inorder2(node* root){
    node* cur = root;
    std::stack<node*> s;
    while(cur || !s.empty()){
        if(cur == nullptr){
            cur = s.top();
            s.pop();
            std::cout << cur->key << ' ';
            cur = cur->right;
        } else{
            s.push(cur);
            cur = cur->left;
        }
    }
}

void inorder(node* root){
    node* cur = root;
    while(cur){
        if(cur->left == nullptr){
            std::cout << cur->key << ' '; 
            cur = cur->right;

        } 
        else{
            node* n = cur->left;
            while(n->right && n->right != cur){
                n = n->right;
            }
            if(n->right){
                n->right = nullptr;
                std::cout << cur->key << ' ';
                cur = cur->right;
            } else{
                n->right = cur;
                cur = cur->left;
            }
        }
    }
}

void preorder1(node* root){
    if(root == nullptr) return;
    std::cout << root->key << ' ';
    preorder1(root->left);
    preorder1(root->right);
}

void preorder(node* root){
    std::stack<node*> s;
    if(root != nullptr) s.push(root);
    while(!s.empty()){
        node* n = s.top();
        s.pop();
        std::cout << n->key << ' ';
        if(n->right){
            s.push(n->right);
        }
        if(n->left){
            s.push(n->left);
        }
    }
}

void preorder3(node* root){
    node* cur = root;
    while(cur){
        if(cur->left == nullptr){
            std::cout << cur->key << ' ';
            cur = cur->right;
        } else{
            node* n = cur->left;
            while(n->right && n->right != cur){
                n = n->right;
            }
            if(n->right == cur){
                n->right = nullptr;
                cur = cur->right;
            } else{
                std::cout << cur->key << ' ';
                n->right = cur;
                cur = cur->left;
            }
        }
   }
}

void postorder(node* root){
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    std::cout << root->key << ' '; 
}

void postorder2(node* root){
    node* prev = nullptr;
    node* cur = root;
    std::stack<node*> s;
    while(cur || !s.empty()){
        if(cur){
            s.push(cur);
            cur = cur->left;           
        } else{
            node* n = s.top();
            if(n->right == prev || n->right == nullptr){
                std::cout << n->key << ' ';
                prev = n;
                s.pop();
            } else{
                cur = n->right;
            }
        }        
    }
}

node* insert(node* root,int key){
    if(root == nullptr) return new node(key);
    if(root->key == key) return root;
    if(key > root->key){
        root->right = insert(root->right,key);
    } else{
        root->left = insert(root->left,key);
    }
    root->height = std::max(height(root->right),height(root->left))+1;
    return balance(root);
}

node* minvalue(node* root){
    while(root->left != nullptr) root = root->left;
    return root;
}

node* maxvalue(node* root){
    while(root->right != nullptr) root = root->right;
    return root;
}

node* deletion(node* root, int key){
    if(root == nullptr) return nullptr;
    if(key < root->key) root->left = deletion(root->left,key);   
    else if(key > root->key) root->right = deletion(root->right,key);
    else{
        if(root->left == nullptr || root->right == nullptr){
            node* tmp = (root->left == nullptr) ? root->right : root->left;
            delete root;
            return tmp;
        }
        else{
            node* tmp = minvalue(root->right);
            root->key = tmp->key;
            root->right = deletion(root->right,tmp->key);
        }
    }
    root->height = std::max(height(root->right),height(root->left)) + 1;
    return balance(root);      
}

int main(){
    node* root = nullptr;
    root = insert(root,0);
    root = insert(root,8);
    root = insert(root,11);
    root = insert(root,9);
    root = insert(root,6);
    root = insert(root,10);
    root = insert(root,1);
    inorder(root);
    std::cout << "\n------\n";
    BFS(root);
    std::cout << std::endl;
    root = deletion(root,10);
    root = deletion(root,8);
    BFS(root);
    std::cout << "\n------\n";
    root = deletion(root,11);
    BFS(root);
    std::cout << "\n------\n";
    root = deletion(root,6);
    BFS(root);
    for(int i = 0; i < 15; i++){
        root = insert(root,i);
    }   
    BFS(root);
    std::cout << "\n------\n";
    inorder(root);
    std::cout << "\n------\n";
    inorder(root);
    inorder(root);
    std::cout << "\n------\n";
    preorder1(root);
    std::cout << "\n------\n";
    preorder(root);
    std::cout << "\n------\n";
    preorder3(root);
    std::cout << "\n------\n";
    postorder(root);
    std::cout << "\n------\npostorder2\n";
    postorder2(root);
    std::cout << "\n------\n";
    return 0;
}
