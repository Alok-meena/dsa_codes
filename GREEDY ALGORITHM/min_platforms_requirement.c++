Minimum Platforms
Difficulty: MediumAccuracy: 26.84%Submissions: 570K+Points: 4
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform
Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be there from 11:00 to 11:30
Constraints:
1≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359
Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0).



brtue force 

similar to this O(n^2) and O(1) s.c

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
         int n=dep.size();
        
        int maxi=1;
        
        for(int i=0;i<n-1;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(arr[j]<=dep[i] and dep[j]>=arr[i]){
                    cnt++;
                }
            }
            
            maxi=max(maxi,cnt);
        }
        
        return maxi;
    }
};


alright may be wrong as require more conditions

optimized sort both array by time and put in another array the if arrival platofrom++ require new o/w -- store max

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,char>>v;
        
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],'a'});
            v.push_back({dep[i],'d'});
        }
        
        sort(v.begin(),v.end(),[](auto a,auto b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first; //in ascending time but if same arrival time then include
            //the one with earlier dep time first
        });
        
        int maxplat=0,platforms=0;
        
        for(auto i:v){
            if(i.second=='a'){
                platforms++;
            }
            else platforms--;
            maxplat=max(maxplat,platforms);
        }
        
        return maxplat;
    }
};


t.c:-O(nlogn) and s.c:-O(n) 

but we can also do this in a single array alright in O(1) s.c


ya this is the correct code nothing sort kr diya then ptr i for arrival and j for dep 

and just check if arr[i] is before then plat++ i++ then dep plat-- j++ that's it and i<arr.size() should be used not j imp thing

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int maxplat=1,platforms=0;
        
        int i=0,j=0;
        
        while(i<dep.size()){
            if(arr[i]<=dep[j]){
                platforms++;
                i++;
            }
            else{
                platforms--;
                j++;
            }
            maxplat=max(maxplat,platforms);
        }
        
        return maxplat;
    }
};

