Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
Deadline of the job is the time before which job needs to be completed to earn the profit.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).






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
    static bool cmp(Job a,Job b){//job a and job b as type of arr is job and a and b means value is coming
        return a.profit>b.profit;//des order me kr diya to pick max profit
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //structure of the code is already given
        
        sort(arr,arr+n,cmp);
        
        int maxDeadline=0;
        for(int i=0;i<n;i++){
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        
        vector<int>schedule(maxDeadline+1,-1);//as we will do 1 based indexing so +1 size
        
        int count=0;//to calculate no. of jobs done
        int maxprofit=0;
        
        for(int i=0;i<n;i++){
            int currprofit=arr[i].profit;
            int currDead=arr[i].dead;
            int currJobId=arr[i].id;
            
            for(int k=currDead;k>0;k--){
                //ham timeline 1 se le rhe so 0 tk nhi jana hai
                if(schedule[k]==-1){
                    count++;
                    schedule[k]=currJobId;
                    maxprofit+=currprofit;
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

t.c:-O(nlogn)+O(n*k) ans s.c:-O
