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
    if(root->data==val){ // to value mil gyi then 4 cases h
        //0 child

        if(root->left==NULL && root->right==NULL){// ager 0 child simply delete it
            delete root;
            return NULL;
        }  

        // 1 child
        //left child
        if(root->left!=NULL && root->right==NULL){// if one child either left or right then store the child and delete the root and return the child
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

        if(root->left!=NULL && root->right!=NULL){// and if two child so either take max value from left or min value from right and replace the root value
            // with it in this case we have taken min value from right
            int mini=minvalue(root->right)->data;
            root->data=mini;//then root ke data ko replace kr diya min value se
            root->right=deletefrombst(root->right,mini);// then we also have to delete that min value in right subtree to deletenode function ko call kr diya
            // to ye vha jake easily delete kr dega
            return root;

            // to max value from left subtree hogi rightmost node and right subtree ki min value hogi leftmost node okkk


            //code to take max value from left part 
            // int maxi=maxvalue(root->left)->data;
            // root->data=maxi;
            // root->left=deletefrombst(root->left,maxi);
            // return root;
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
