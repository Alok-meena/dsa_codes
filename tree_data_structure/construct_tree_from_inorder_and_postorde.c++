Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Example 1:

Input:
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 
1 2 4 8 5 3 6 7
Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be

          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8





class Solution
{
    private:
    
    int findposition(int in[],int inorderstart,int inorderend,int element,int size){
          for(int i=inorderstart;i<=inorderend;i++){
              if(in[i]==element){ 
                  return i;
              }
          }
          return -1;
      }
      Node *solve(int in[],int post[],int &index,int inorderstart,int inorderend,int n){
          if(index<0 || inorderstart>inorderend){ // doosri condition to same rhega but first me change because we are starting from the last node equal to 
              //mt lagana because pichle preorder vale me 0th indexing thi to >=n liya but yha <0 loge becaue 0 ko to include karna hai
              return NULL;
          }
          
          int element=post[index--];// index bhi -- because piche ja rhe
          Node *root=new Node(element);
          int position=findposition(in,inorderstart,inorderend,element,n);
          
          root->right=solve(in,post,index,position+1,inorderend,n);//yha hm last se start kr rhe hai aor last se 1st element ke bad next element inorder ke right 
         // me hai to that's why pahle right ki call ki hai
          
          root->left=solve(in,post,index,inorderstart,position-1,n); 

          return root;
          
          
      }
    public:

    Node *buildTree(int in[], int post[], int n) {
        int postorderindex=n-1;//starting last node se because postorder me root last me hota hai 
        Node *ans=solve(in,post,postorderindex,0,n-1,n);
        return ans;
    }
};


 Time Complexity: O(n2)
 Auxiliary Space: O(n)
