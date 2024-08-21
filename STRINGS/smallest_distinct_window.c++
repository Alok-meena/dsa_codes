Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"







1: brute force 

class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        set<char>s;
        
        for(auto i:str){
            s.insert(i);
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<str.length();i++){
            for(int len=1;len<=str.length();len++){
                set<char>s1(s.begin(),s.end());
                string S=str.substr(i,len);
                for(auto j:S){
                    if(s.find(j)!=s.end()){
                        s1.erase(j);
                    }
                }
                
                if(s1.empty()){
                    ans=min(ans,len);
                }
            }
        }
        
        return ans;
    }
};

t.c:-O(n^3) and s.c:-O(n)


 
2:optimal

                                  in map and set's we can use m.clear() / s.clear() to empty the whole map or set


 class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        int n=str.length();

        //here we cannot use a set as we also have to count the char count 
        unordered_map<char,int>m;
        
        for(auto i:str){
            m[i]++;
        }
        
        int distinct=m.size();
        int tail=0,head=-1;
        
        int count=0;//to count distinct elements live during traversal
        int ans=n;
        
        m.clear();
        
        while(tail<n){
            //pahle ham head ko aage bdhayenge jab tak hame sare distinct char na mil jaye for this head+1<n here we are not modifying the head value and c<disti
            //
            while(head+1<n && count<distinct){
                m[str[++head]]++;
                if(m[str[head]]==1) count++;
            }

            //means we got a paritcular window so update the ans 
            if(count==distinct){
                ans=min(ans,head-tail+1);
            }

            //and now if head>=tail to ab tail ko aage badhao jab tk sare distinct element hai apne pass
            if(head>=tail){
                m[str[tail]]--; //sbse pahle to char ke count ko decrement kr do 
                if(m[str[tail]]==0) count--;//as ek distinct char window ke bahar kr rhe hai
                tail++;
                if(count==distinct){//means ex: aaabbcc to isme tail badhayenge aage to apna window ka size bhi decrease hoga so have to update the ans
                    ans=min(ans,head-tail+1);
                }
            }
        }
        
        return ans;
        
    }
};

t.c:-O(n) and s.c:-O(n)

it will not work with ordered_map as it have logn t.c for insertion,deletion,updation okk then t.c:-O(nlogn) that's why



