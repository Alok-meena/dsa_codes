Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());//sorting normally so it will be on the basis of first element start

        int start=intervals[0][0];
        int end=intervals[0][1];

        
        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});//it can be done as only 2 columns are there
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        //adding last interval as it will not be compared and it will also be stored in start and end 
        ans.push_back({start,end});
        return ans;
    }
};


Overlapping Intervals
Difficulty: MediumAccuracy: 57.41%Submissions: 85K+Points: 4
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105







class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        
        for(auto interval:arr){
            if(ans.empty() || interval[0]>ans.back()[1]){
                ans.push_back(interval);
            }
            else{
                ans.back()[1]=max(ans.back()[1],interval[1]);
            }
        }
        
        return ans;
        
    }
};

O(n)+O(nlogn)=O(nlogn) is the t.c and s.c:-O(n)


if in pair given then do this 

 #include <bits/stdc++.h>
using namespace std;

int main(){

    vector<pair<int,int>>v={{1,3},{2,4},{3,8}};
    
    vector<pair<int,int>>ans;
    sort(v.begin(),v.end());

    ans.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        if(v[i].first<=ans.back().second){
            ans.back().second=max(ans.back().second,v[i].second);
        }
        else{
            ans.push_back(v[i]);
        }
    }

    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    
} 
 
