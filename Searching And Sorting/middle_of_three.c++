Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).


Example 1:

Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element.

Example 2:

Input:
A = 162, B = 934, C = 200
Output:
200
Exaplanation:
Since 200>162 && 200<934,
So, 200 is the middle element.

  






class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        vector<int>v;
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        sort(v.begin(),v.end());
        
        return v[1];
    }
};


class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if (A < B)
        return (B < C)? B : max(A, C);
      return (A < C)? A : max(B, C);

    }
};

t.c:-O(1) and same s.c
