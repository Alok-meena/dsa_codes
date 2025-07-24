N meetings in one room
Difficulty: EasyAccuracy: 45.3%Submissions: 236K+Points: 2
There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is 
finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? 
Return the maximum number of meetings that can be held in the meeting room.

 

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Examples :

Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int solve(int start[],int end[],int n){
        int count=1;
        for(int i=1;i<n;i++){
            int newStart_time=start[i];
            int oldmeet_end_time=end[i-1];
            if(newStart_time>oldmeet_end_time){
                count++;
            }
        }
        return count;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        sort(end,end+n);
        return solve(start,end,n);

        
        
    }
};

this is also correct but as we are sorting end only so to mainatain it's order with start pair both of them and then sort them


using greedy approach 

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int solve(vector<pair<int,int>>&v,int n){
        int count=1;//to consider the first meeting
        int oldtime=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>oldtime){
                count++;
                oldtime=v[i].second;
            }
        }
        return count;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(start[i],end[i]));
        }
        
        sort(v.begin(),v.end(),cmp);
        return solve(v,n);

        
        
    }
};

t.c:-O(nlogn) and s.c:-O(n)


  https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1 try this ques also



  By making it static, you indicate that this function belongs to the class Solution and does not rely on instance-specific data.
If you were to use cmp as a non-static member function, it would require an instance of Solution to call it, which would complicate its usage with std::sort.



we can also store the order of meetings like


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        
        vector<vector<int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i],i+1});
        }
        
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a[1]<b[1];
        });
        
        int cnt=1;
        int End=v[0][1];
        
        for(int i=1;i<n;i++){
            if(v[i][0]>End){
                cnt++;
                End=v[i][1];
                cout<<v[i][2]<<" ";
            }
        }
        
        cout<<v[n-1][2]<<endl;
        
        return cnt;
    }
};

t.c:-O(nlogn) and s.c:-O(n)
