Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.





class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
        stack<char>st;
        for(auto i:x){
            if(i=='{' || i=='[' || i=='(') st.push(i);
            else if(i=='}' || i==']' || i==')'){
                if(st.empty()) return false;
                if(i=='}' && st.top()=='{') st.pop();
                else if(i==']' && st.top()=='[') st.pop();
                else if(i==')' && st.top()=='(') st.pop();
                else{
                     return false;
                }
            }
        }
        
        return st.empty();
        
        
    }

};
