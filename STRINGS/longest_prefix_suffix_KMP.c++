Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 








class Solution{
  public:		
    bool check(string a,string b){
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    
	    int flag=1;
	    
	    for(int i=0;i<s.length()-1;i++){
	        if(s[i]!=s[i+1]){
	            flag=0;
	        }
	    }
	    
	    if(flag) return s.length()-1;
	    int ans=0;
	 
	    
	    string prefix="";
	    string suffix="";

      //hamne len 1 se start kiya loop as we require last suffix from n-len index and of len 1 aor ye lenght jo hamne di hai vo 1 se n-1 tk hi di hai 
    // as we are not allowed to include the whole string len 
	    for(int len=1;len<n;len++){
	        prefix=s.substr(0,len);
	        suffix=s.substr(n-len,len);
	        if(check(prefix,suffix)){
	            ans=max(ans,len);
	        }
	
	    }
	    
	    return ans;
	    
	}
};

t.c:-O(n^2) and s.c:-O(n)



2): now it will be solved using kmp algo  KMP:------(Knuth–Morris–Pratt)

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    vector<int>LPS(n,0);
	    
	    int prefix=0;
	    int suffix=1;
	    
	    while(suffix<n){
	        if(s[prefix]==s[suffix]){
	            LPS[suffix]=prefix+1;//s[prefix] ka index +1
	            suffix++;
	            prefix++;
	        }
	        else{
	            if(prefix==0){//means ageer prefix=0 hai to ham 0th index ke pahle ja hi nhi skte hai
	                LPS[suffix]=0;
	                suffix++;
	            }
	            else{
	                prefix=LPS[prefix-1];
	            }
	        }
	    }



    O(n) and O(n) are t.c and s.c
	    return LPS[n-1];
	}
};

t.c:-O(n) and s.c:-O(n) and the jumps taken by prefix pointer will remain negligible


//just add this if we have to return the string as prefix always start from 0th index and suffix always end at n-1 index
        int len=lps[n-1];
        if(len==0) return "";
        return s.substr(0,len);
