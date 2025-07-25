
## basics of trees


  #include <iostream>
#include <queue>
#include <stack>
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


//THIS IS TREE BUILD BY PREORDER TRAVERSAL OKK

we can also do this in this way

node* buildTree(){
	int data;
	cin>>data;

	node *root=new node(data);

	string l,r;
	cin>>l;

	if(l=="true"){
		root->left=buildTree();
	}

	cin>>r;
	if(r=="true"){
		root->right=buildTree();
	}

	return root;

}

node* treebuild(node *root){

    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter the data for inserting left of:"<<data<<endl;
    root->left=treebuild(root->left);

    cout<<"Enter the data for inserting right of:"<<data<<endl;
    root->right=treebuild(root->right);

    return root; //to bhai return bhi to kroge to the main function 
}

void levelorderTraversal(node *root){
    queue<node*>q;
    stack<int>s;
    q.push(root);
    q.push(NULL);

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
            //yhi pe print karna o/w there will be error due to NULL exception okk
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

void reverse_levelorderTraversal(node *root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    s.push(root);

    while(!q.empty()){
        node *temp=q.front();
        // cout<<temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
            s.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
            s.push(temp->right);
        }
        
    }
    while(!s.empty()){
        node *temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
    }
}

more simple 
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        if (!root) return {};

        vector<int> result;
        queue<Node*> q;
        stack<int> s;

        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Push the node data into the stack
            s.push(node->data);

            // Enqueue left and right children
            if (node->right) q.push(node->right); //yha pahle right ko dalna pdega tabhi to stack use reverse krega alright ye dekh lena
            if (node->left) q.push(node->left);
        }

        // Pop all elements from the stack and store them in the result vector
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};

or

void levelordertraversal(node* root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
                s.push(NULL);
            }
        }

        else{
            s.push(temp);
        
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
    }

    while(!s.empty()){
        node *temp=s.top();
        if(temp==NULL) cout<<endl;
        else{
            cout<<temp->data<<" ";
        }
        s.pop();
    }
}

to get how many levels in the tree use the below code :

void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<"level:"<<level<<endl;
            level++;
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";        
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


this is also correct 

for : 

1         4 5 6
2 3       2 3
4 5 6     1

this is the best approach dry run and u will understand
so if we first go to the right and push it's data then we will get the data in correct reverse level order okkk

  

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void iterativeInorder(node *root) {
    stack<node*> s;
    node *curr = root;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

iterative inorder traversal we can also write like 

simple what we want left root right to pahle left jate jaao until null then store ans and go right

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        
        stack<Node*>s;
        
        Node *temp=root;
        
        while(true){
            if(temp!=NULL){
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()) break;
                temp=s.top();
                ans.push_back(temp->data);
                s.pop();
                temp=temp->right;
            }
        }
        
        return ans;
    }
};


//as preorder is root left right so first push root into stack and then push right and then left as we want left right and stack will reverse that order into this 
//okk
void iterativePreorder(node *root) {
    stack<node*> s;
    if (root != nullptr)
        s.push(root);

    while (!s.empty()) {
        node *curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right != nullptr)
            s.push(curr->right);
        if (curr->left != nullptr)
            s.push(curr->left);
    }
}


and in this we must have to use two stacks as what we want left right root so if we do push root then left then right so stack will reverse this order to correct
it do use another stack to reverse the order again okk

void iterativePostorder(node *root) {
    if (root == nullptr)
        return;

    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != nullptr)
            s1.push(curr->left);
        if (curr->right != nullptr)
            s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

node* build_from_levelorder(node* &root){
    queue<node*>q;
    int data;
    cout<<"enter data for root:"<<endl;
    cin>>data;
    if(data==-1) return NULL;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }

    return root;
}

int main(){
    
    node *root=NULL;

    build_from_levelorder(root);
    levelorderTraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    // root=treebuild(root);
    // cout<<"level order traversal"<<endl;
    // reverse_levelorderTraversal(root);
    // cout<<endl;
    // iterativeInorder(root);
    // cout<<endl;
    // iterativePreorder(root);
    // cout<<endl;
    // iterativePostorder(root);

}
