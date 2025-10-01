Huffman Encoding
Difficulty: MediumAccuracy: 32.4%Submissions: 36K+Points: 4
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. 
Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree 
and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
Steps to print codes from Huffman Tree
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary 
Tree.


in this code the concept form the ques connecting 2 ropes and send min sum is used



class Node{
    public:
       int data;
       Node *left;
       Node *right;
       
       Node(int d){
           data=d;
           left=NULL;
           right=NULL;
       }
};

Why not greater<Node*>:
The greater<Node*> comparator would compare the memory addresses of Node pointers, not their data (frequency). 
We need to compare the frequencies, so a custom comparator is required.


Comparator (cmp class): Ensures that nodes are compared based on their frequency data (data member) rather than their memory addresses.

class cmp{
    public://it should be public
Exactly! In C++, when operator() is used inside a class, it turns that class into a functor or function object.
Functors are objects that can be treated as if they are functions because they overload the function call operator (). 
This allows instances of the class to be used in contexts where a function is expected, such as in standard library algorithms
like std::sort, std::priority_queue, or custom sorting routines.
    
        bool operator()(Node *a,Node *b){
            return a->data > b->data;//and reversing the sign < it behaves like max-heap

  When constructing a Huffman tree, you need to always combine the two nodes with the smallest frequencies.
  Using a->data > b->data ensures that the priority queue is a min-heap, so the smallest elements are always at the top and can be easily accessed and removed.

    means AGER A KA DATA BDA HAI TO B KO TOP PE RKHO AND O/W IN "<" THIS CASE IS A DATA CHOTA HAI TO B KO UPER RKHO MAX HEAP
        }
};
class Solution
{
	public:
	    void traversal(Node *root,vector<string>&ans,string temp){
          //pre-order traversal is root left right
	        //base case
	        if(root->left==NULL && root->right==NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        traversal(root->left,ans,temp+'0');
	        traversal(root->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    //creating minheap
		    priority_queue<Node*,vector<Node*>,cmp>pq;//yha comparator use kiya hai ye  nhi greater<Node*>
		    for(int i=0;i<N;i++){
		        Node *temp=new Node(f[i]);//creating a new node to insert into pq
		        pq.push(temp);
		    }
		    
		    //same concept as ropes ques for >1 pq size
		    
		    while(pq.size()>1){
		        //right bhi le skte the hamne left le li

            //ISME YE PAHLE SBSE CHOTA ELEMENT DEGA TO USE LEFT ME RKHO AND USKE BAD VALE KO RIGHT ME RKHO
		        Node *left=pq.top();
		        pq.pop();
		        
		        Node *right=pq.top();
		        pq.pop();
		        
		        Node *newNode=new Node(left->data+right->data);
		        newNode->left=left;
		        newNode->right=right;
		        
		        pq.push(newNode);
		    }
		   
		    
		    //so yha se apna tree create ho gya hai
		    //aor pq me ek element bcha hoga jo ki root node hoga
		    
		    Node *root=pq.top();
		    vector<string>ans;
		    string temp="";

        //now preorder traversl is called
		    traversal(root,ans,temp);
		    
		    return ans;
		    

		}
		
};

//BAS YHA BHI KYA KIYA NODES BNAYI AOR PQ ME DAL DI THEN MIN PAKAD KE UNKI NODE BNATE GYE BS 


t.c:-O(nlogn) and s.c:-O(n)


and if we have to store this mapping with each char then we can just add char in node and use mapping

like below:

class Solution {
  public:
  
    class node{
        public:
        int data;
        char ch;
        node *left;
        node *right;
        
        node(int data,char ch){
            this->data=data;
            this->ch=ch;
            this->left=NULL;
            this->right=NULL;
        }
    };
    
    class cmp{
        public:
        
        bool operator()(node *a,node *b){
            return a->data>b->data;
        }
    };
    
    void preorder(node *root,map<char,string>&mapping,string path){
        if(root->left==NULL and root->right==NULL){
            mapping[root->ch]=path;
            return;
        }
        
        preorder(root->left,mapping,path+'0');
        preorder(root->right,mapping,path+'1');
    }
    
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        priority_queue<node*,vector<node*>,cmp>pq;
        
        for(int i=0;i<S.length();i++){
            node *temp=new node(f[i],S[i]);
            pq.push(temp);
        }
        
        while(pq.size()>1){
            node *a=pq.top();pq.pop();
            node *b=pq.top();pq.pop();
            
            node *root=new node(a->data+b->data,'$');
            
            root->left=a;
            root->right=b;
            
            pq.push(root);
        }
        
        map<char,string>mapping;
        
        node* root=pq.top();
        string path;
        
        preorder(root,mapping,path);
        
        vector<string>ans;
        
        for(int i=0;i<S.length();i++){
            ans.push_back(mapping[S[i]]);
        }
        
        return ans;
    }
};

