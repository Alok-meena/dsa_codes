#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node{
    public:
     int data;
     node *left;
     node *right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


void levelorderTraversal(node *root){
    queue<node*>q;
    stack<int>s;
    q.push(root);
    q.push(NULL);
    int count=0;
    while(!q.empty()){
        node *temp=q.front();
        // s.push(temp->data);
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{ 
            
            cout<<temp->data<<" ";
            if(temp->left){
               q.push(temp->left);
            }
               if(temp->right){
               q.push(temp->right);
            }
            
            
            
        }
    }
}

node *inserttobst(node *root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data<data){
        root->right=inserttobst(root->right,data);
    }
    else{
        root->left=inserttobst(root->left,data);
    }
}
void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=inserttobst(root,data);
        cin>>data;
    }
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node *minvalue(node *root){
    node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node *maxvalue(node *root){
    node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node *deletefrombst(node *root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }  

        // 1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node *temp=root->left;
            delete root; 
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            node *temp=root->right;
            delete root; 
            return temp;
        }
        //two child

        if(root->left!=NULL && root->right!=NULL){
            int mini=minvalue(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left=deletefrombst(root->left,val);
        return root;
    }
    else{
        root->right=deletefrombst(root->right,val);
        return root;
    }
}

int main(){
    node *root=NULL;
    cout<<"enter the data to create bst:"<<endl;
    takeinput(root);
    levelorderTraversal(root);
    cout<<endl;
 
    inorder(root);
    cout<<endl;

    cout<<"minimum value of the bst is:"<<minvalue(root)->data;
    cout<<endl;
    cout<<"maximum value of the bst is:"<<maxvalue(root)->data;

    root=deletefrombst(root,50);

    //after deletion

    cout<<endl;

    levelorderTraversal(root);
    cout<<endl;
 
    inorder(root);
    cout<<endl;

    cout<<"minimum value of the bst is:"<<minvalue(root)->data;
    cout<<endl;
    cout<<"maximum value of the bst is:"<<maxvalue(root)->data;

    return 0;
}

t.c:- same O(H) and in worse case it is O(N) where H is height
s.c:-O(H) and O(N) worst case due to recursive calls 
