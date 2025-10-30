Check Mirror in N-ary tree
Difficulty: MediumAccuracy: 52.21%Submissions: 34K+Points: 4Average Time: 20m
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


Example 1:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.
Example 2:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
0
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.

Your Task:
You don't need to read input or print anything. Your task is to complete the function checkMirrorTree() which takes 2 Integers n, and e;  and two arrays A[] and B[] of size 2*e as input and returns 1 if the trees are mirror images of each other and 0 if not.


Expected Time Complexity: O(e)
Expected Auxiliary Space: O(e)


Constraints:
1 <= n,e <= 105




batan hai ki dono ek doosre ke mirror hai ki nhi to bhai ager honge to har ek node ke children ko store kr lo dono tree ke aor ager ek tree ke same node ke 
children ek doosre ke reverse hai to ans true hai ki mirror hai for that store children of one in stack to reverse and other in queue so that the order remain same
alright




class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,stack<int>>tree1;
        unordered_map<int,queue<int>>tree2;
        
        //for tree1
        for(int i=0;i<2*e;i+=2){
            int u=A[i];int v=A[i+1];
            tree1[u].push(v);
        }
        
        
        //for tree2
        for(int i=0;i<2*e;i+=2){
            int u=B[i];int v=B[i+1];
            tree2[u].push(v);
        }
        
        for(int i=1;i<=n;i++){
            while(!tree1[i].empty() and !tree2[i].empty()){
                int val1=tree1[i].top();
                tree1[i].pop();
                
                int val2=tree2[i].front();
                tree2[i].pop();
                
                if(val1!=val2) return false;
            }
        }
        
        return true;
    }
};

t.c:-O(e) and s.c:-O(e)


can do this instead this direct access using auto 

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,queue<int>>a;
        unordered_map<int,stack<int>>b;
        
        int i=0;
        while(i<2*e){
            a[A[i]].push(A[i+1]);
            b[B[i]].push(B[i+1]);
            i=i+2;
        }
        
        
        for(auto i:a){
            int node=i.first;
            queue<int>q=i.second;
            stack<int>s=b[node];
            
            while(!q.empty() and !s.empty()){
                int front=q.front();q.pop();
                int top=s.top();s.pop();
                
                if(front!=top) return 0;
            }
        }
        
        return 1;
    }
};
