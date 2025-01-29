

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
    //iska mtlb hai ki hame binary treee ki tarah normally khi bhi insertion nhi krna ese krna hai ki bst apni properties ko retain kre
    //to kisi node ki pos find krte krte NULL tk pahuch gya root then create a new node there and return it okkk that's why ==null ke sath compare kiya hai okk
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
int main(){
    node *root=NULL;
    cout<<"enter the data to create bst:"<<endl;
    takeinput(root);
    levelorderTraversal(root);
    cout<<endl;
 
    inorder(root);

    return 0;
}
