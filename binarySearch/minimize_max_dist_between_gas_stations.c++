Minimize Max Distance to Gas Station
Difficulty: HardAccuracy: 38.36%Submissions: 96K+Points: 8Average Time: 40m
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Example 1:

Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

Constraint:
10 <= n <= 10000 
0 <= stations[i] <= 109 
0 <= k <= 105



brute force : - t.c :-O(n*k+k)

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        
        vector<int>howMany(n-1,0);
        
        for(int gasStations=1;gasStations<=k;gasStations++){
            double maxSection=-1;
            double maxIdx=-1;
            
            for(int i=0;i<n-1;i++){
                double diff=stations[i+1]-stations[i];
                double sectionLen=diff/(howMany[i]+1);
                if(maxSection<sectionLen){
                    maxSection=sectionLen;
                    maxIdx=i;
                }
            }
            howMany[maxIdx]++;
        }
        
        double maxAns=-1;
        for(int i=0;i<n-1;i++){
            double diff=stations[i+1]-stations[i];
            double sectionLen=diff/(howMany[i]+1);
            maxAns=max(maxAns,sectionLen);
        }
        return maxAns;
    }
};

optimized using pq (max heap) t.c:-O(nlogn+klogn)

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        
        vector<int>howMany(n-1,0);
        priority_queue<pair<long double,int>>pq;
        
        for(int i=0;i<n-1;i++){
            long double diff=stations[i+1]-stations[i];
            pq.push({diff,i});
        }
        
        for(int gasStations=1;gasStations<=k;gasStations++){
            long double diff=pq.top().first;
            int secIdx=pq.top().second;
            pq.pop();
            
            howMany[secIdx]++;
            long double initialDiff=stations[secIdx+1]-stations[secIdx];
            long double newdiff=initialDiff/(howMany[secIdx]+1);
            pq.push({newdiff,secIdx});
        }
        
        return pq.top().first;
    }
};
