Given N activities with their start and finish day given in array start[ ] and end[ ].
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.



class Solution
{
    public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        
        return a.second<b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        
        sort(v.begin(),v.end());//it is done without mentioning on what basis so it will choose first element like here it is end[i]
        
        int count=1;
        int old=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>old){
                count++;
                old=v[i].first;
            }
        }
        return count;
    }
};
