Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
In case the kth smallest element doesn't exist return -1. 

Example 1:

Input:
n = 2, q = 3
range[] = {{1, 4}, {6, 8}}
queries[] = {2, 6, 10}
Output: 
2 7 -1
Explanation: 
After combining the given ranges, 
the numbers become 1 2 3 4 6 7 8. As here 2nd 
element is 2, so we print 2. As 6th element is 
7, so we print 7 and as 10th element doesn't 
exist, so weprint -1.
Example 2:

Input:
n = 2, q = 2
range[] = {{2, 6}, {5, 7}} 
queries[] = {5, 8}
Output: 
6 -1
Explantion: 
After combining the ranges, we'll take Union of 
range= {2,3,4,5,6,7}, here  5th smallest number 
will be 6 and 8th smallest number does not exists.


brute force combining range in set to avoid duplicates and then find the corresponding values 

class Solution{
    public:
    vector<int> kthSmallestNum(int n, vector<vector<int>>& range, int q, vector<int> queries){
        vector<int> ans;
        set<int> combination;
        
        // Step 1: Combine the ranges
        for(int i = 0; i < n; i++) {
            for(int j = range[i][0]; j <= range[i][1]; j++) {
                combination.insert(j);
            }
        }
        
        // Step 2: Sort the combined elements and remove duplicates
        vector<int>combined(combination.begin(),combination.end());
        sort(combined.begin(), combined.end());
        // combined.erase(unique(combined.begin(), combined.end()), combined.end());

        // Step 3: Process each query
        for(int i = 0; i < q; i++) {
            int index = queries[i] - 1; // kth smallest means 1-based index, so subtract 1 for 0-based indexing
            
            if(index < combined.size()) {
                ans.push_back(combined[index]);
            } else {
                ans.push_back(-1); // If query index is out of bounds, return -1
            }
        }
        
        return ans;
    } 
};

t.c:-O(klogk+k+q)


2) optimized approach


class Solution{
    public:
    
    vector<vector<int>> merge(int n,vector<vector<int>>&intervals){
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());//first sort based on first value right
        
        vector<int>v=intervals[0];
        
        for(int i=1;i<n;i++){
            if(v[1]>=intervals[i][0]){//then if the 1st value of next interval is smaller than current range 2nd value then update the second value o/w update
// ans and push and again check for next interval
                v[1]=max(v[1],intervals[i][1]);
            }
            else{
                ans.push_back(v);
                v=intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
    
    int findkth(int k,vector<vector<int>>&intervals){
        int n=intervals.size();
        
        for(int i=0;i<n;i++){
            if(k<=(intervals[i][1]-intervals[i][0]+1)){// means jo bhi element nikal rhe ager vo hmari range me hai ex (1,5) 2nd element
            // then 5-1+1=5 2<=5 therefor return 1+2-1=2 as your ans for this 
                return (intervals[i][0]+k-1);
            }
            else{
               //iska mtlb hai ki ager current interval range me apni value nhi hai to fir utne elements ko subtract kr do aor agli range me dhundna
//ex (1,5) (7,10) 7th element then 7>5 therefor k=7-5=2 now this lies in (7,10) interval return 7+2-1=8 as your output okk
                k-=abs(intervals[i][1]-intervals[i][0]+1);
            }
        }
        if(k) return -1;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        
        vector<vector<int>>intervals=merge(n,range);//to sbse pahle to ham ek correct pair of intervals ki range lenge okk
        vector<int>ans;
        
        for(int i=0;i<queries.size();i++){
            int x=findkth(queries[i],intervals);
            ans.push_back(x);
        }
        
        return ans;
    } 
};

Total Time Complexity=O(nlogn)+O(q⋅n)   Total Space Complexity=O(n+q)
