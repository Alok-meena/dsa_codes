Stack Permutations
Difficulty: MediumAccuracy: 70.5%Submissions: 27K+Points: 4Average Time: 10m
You are given two arrays a[] and b[] of unique elements of  same size . Check if  array b[] is a stack permutation of the array a[] or not. Stack permutation means that array b[] can be created from array a[] using a stack and stack operations.


Examples:

Input: a[] = [1, 2, 3], b[] = [2 ,1 ,3]
Output: True
Explanation:
1. push 1 from a to stack
2. push 2 from a to stack
3. pop 2 from stack to b
4. pop 1 from stack to b
5. push 3 from a to stack
6. pop 3 from stack to b

Input: a[] = [1, 2, 3], b[] = [3 ,1 ,2]
Output: False
Explanation:Not Possible
Constraints:
1 ≤ a.size()=b.size()≤  105
0 ≤  a[i], b[i] ≤  2*105





class Solution {
  public:
    bool checkPerm(vector<int>& a, vector<int>& b) {
        // code here
        int i=0;
        int j=0;
        
        int n=a.size();
        
        stack<int>s;
        
        for(auto val:a){
            s.push(val);
            
            if(s.top()==b[j]){
                while(!s.empty() and s.top()==b[j]){
                    s.pop();
                    j++;
                }
            }
        }
        
        return s.empty();
    }
};

t.c:-O(N) and s.c:-O(N)
