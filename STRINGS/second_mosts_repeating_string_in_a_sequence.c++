Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.



class Solution
{
  public:
    static bool sortbyValue(pair<string,int>a,pair<string,int>b){
        return a.second>b.second;
    }
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        string ans;
        
        vector<pair<string,int>>v(m.begin(),m.end());
        sort(v.begin(),v.end(),sortbyValue);
        
        int j=1;
        for(auto i:v){
            if(j==2){
                ans=i.first;
            }
            j++;
        }
        return ans;
    }
};

t.c:-O(nlogk) s.c:-O(k) where k is the no. of uinque strings 

as map always store unique values okk and we also sort that only and store that only that's why
