Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5



class Solution{
    private:
      int findposition(int in[],int inorderstart,int inorderend,int element,int size){
          for(int i=inorderstart;i<=inorderend;i++){
              if(in[i]==element){ to bs jha eequal aaye vo index return kr do 
                  return i;
              }
          }
          return -1;
      }
      Node *solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n){// index ko bi refernce pass karna to retain it's value
          if(index>=n || inorderstart>inorderend){ // ager index greater than n ho jaye to  aor ager inorder ka start aage chla jaye aor end piche aa jaye
              return NULL;
          }
          
          int element=pre[index++];//to sbse pahle pre me se pahla root eleemment choose kiya and then isli node bnayi
          // creating a root node for the element
          Node *root=new Node(element);
         // finding elements index in the inorder
          int position=findposition(in,inorderstart,inorderend,element,n);// then hm position find out kr rhte element of pre ki in inorder  uper jao
          
          root->left=solve(in,pre,index,inorderstart,position-1,n); // fir root ke left me position 0 se leke pos -1 of inorder tk call kro and right me
          //pos+1 se inorder ke end tak
          root->right=solve(in,pre,index,position+1,inorderend,n);
          
          return root;
          
          
      }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderindex=0;
        Node *ans=solve(in,pre,preorderindex,0,n-1,n);
        return ans;
    }
};

 Time Complexity: O(N*N).//because of the for loop to find out the position of the element of preorder in inorder traversal
 Auxiliary Space: O(N).


in these questions, maps is useful in cases that have no equal values of nodes.
but if there are... then you've to go for the first approach whose TC is o(n^2). Correct me if I'm wrong
If you're trying with maps and gfg is not accepting, do it by the 1st approach

approach 2:-
using a map instead of finding the position of the element in N time which cause t.c to N2 we can use mapping 


class Solution{
    private:
      void createmapping(int in[],map<int,int>&nodetoindex,int n){
          for(int i=0;i<n;i++){
              nodetoindex[in[i]]=i; // to in[i] se value nikali and vo konse index pe hai uski mapping kr li
          }
      }
      Node *solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n,map<int,int>&nodetoindex){
          if(index>=n || inorderstart>inorderend){
              return NULL;
          }
          
          int element=pre[index++];
          Node *root=new Node(element);
          int position=nodetoindex[element]; // ab position nikalne ke liye [element] ko as a index use kiya to reach the second int which is position of elements
          
          root->left=solve(in,pre,index,inorderstart,position-1,n,nodetoindex);
          root->right=solve(in,pre,index,position+1,inorderend,n,nodetoindex);
          
          return root;
          
          
      }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,int>nodetoindex; // to isme pahla node ki value hai aor doosra corresponding index hai
        int preorderindex=0;
        
        createmapping(in,nodetoindex,n);
        Node *ans=solve(in,pre,preorderindex,0,n-1,n,nodetoindex);
        return ans;
    }
};

T.c:-O(N*logN)  // because insertion complexiyt of map is logN
S.C:-O(N)



@aayushiagarwal8797
10 months ago
Thank you sir :), for making tree simple and understandable .
I would like to highlight one point : 
Mapping solution will give wrong answer in case of duplicated nodes..... in such case , we can optimize findpos() function by checking from  inStart to inEND ..
 int findpos(int in[],int x,int n,int s,int e)
    {
        for(int i=s;i<=e;i++)
        {
            if(in[i]==x)
            return i;
        }
    }😇
