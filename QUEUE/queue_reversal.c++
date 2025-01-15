








using extra space 

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        reverse(v.begin(),v.end());
        for(auto i:v){
            q.push(i);
        }
        
        return q;
    }
};

t.c:-O(n) and s.c-O(n)

in this approach we have to reverse the array also but can use stack and no reversal require as stack changes the order of the elements OKKK

can solve using recursion also
class Solution {
  public:
    void reverse(queue<int>&q)
        if(q.size()==0){
                    return q;
                }
                
                int val=q.front();
                q.pop();
                reverseQueue(q);
                q.push(val);
                
                return q;
        }
}

t.c:-O(n) and s.c:-O(n) but tle due to function call overhead 
