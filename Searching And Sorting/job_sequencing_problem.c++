Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Examples :

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
Expected Time Complexity: O(nlogn)
Expected Auxilliary Space: O(n)

Constraints:
1 <= n <= 105
1 <= Deadline,id <= n
1 <= Profit <= 500





nothing special just sort in descending according to profit and then take a scheduling array of length maxdeadline+1 as we are taking 1 based indexing
okk and take care jaise ager kisi ki deadline 4 hai to use try kro atlast schedule krne ki taki usse pahle space ho / time ho baki jobs ko schedule krne ke liye okk
that's why we used a for loop from currentdead to 1 deadline k>0



struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        
        int maxidead=-1;
        for(int i=0;i<n;i++){
            maxidead=max(maxidead,arr[i].dead);
        }
        
        vector<int>schedule(maxidead+1,-1);
        
        int count=0;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            int currentdead=arr[i].dead;
            int currentprofit=arr[i].profit;
            int currentid=arr[i].id;
            
            for(int k=currentdead;k>0;k--){
                if(schedule[k]==-1){
                    count++;
                    maxprofit+=currentprofit;
                    schedule[k]=currentid;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        
        return ans;
    } 
};




t.c:-O(nlogn+n*m) s.c:-O(m)


if 2d array is given 

#include <algorithm>

static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]>b[2];
    }

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
        
        int maxidead=-1;
        for(int i=0;i<n;i++){
            maxidead=max(maxidead,jobs[i][1]);
        }
        
        vector<int>schedule(maxidead+1,-1);
        
        int count=0;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            int currentdead=jobs[i][1];
            int currentprofit=jobs[i][2];
            int currentid=jobs[i][0];
            
            for(int k=currentdead;k>0;k--){
                if(schedule[k]==-1){
                    count++;
                    maxprofit+=currentprofit;
                    schedule[k]=currentid;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        
        return ans;
}
