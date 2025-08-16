premium leetcode


exact same ques as fruits into basket just use k instead of 2 alright

brute:

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int len=0;
        
        int n=s.length();

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            int j;
            
            for(j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.size()>k) break;
            }
            
            len=max(len,j-i);
        }
        return len;
    }
};

optimized:

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int len=0;
        
        int n=s.length();
        
        int l=0,r=0;

        unordered_map<char,int>mp;
        
        while(r<n){
            mp[s[r]]++;
            
            if(mp.size()>k){
                while(l<=r and mp.size()>k){
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                }
            }
            
            len=max(len,r-l+1);
            r++;
        }
        
        return len;
    }
};


that's all and to optimize to O(n) t.c use if instead while means do only once alright


aor ager exactly k ke liye hota to bs update the len only if mp.size()==k and set len=-1 initially alright

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int len=-1;
        
        int n=s.length();

       //can do like below also 
        // unordered_set<char>st;
        // for(auto i:s) st.insert(i);
        
        // if(st.size()<k) return -1;
        
        unordered_map<char,int>mp;
        
        int l=0,r=0;
        
        while(r<n){
            mp[s[r]]++;
            
            if(mp.size()>k){
                while(l<=r and mp.size()>k){
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                }
            }
            
            if(mp.size()==k) len=max(len,r-l+1);
            r++;
        }
        
        return len;
    }
};
