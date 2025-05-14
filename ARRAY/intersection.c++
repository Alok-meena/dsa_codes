brute force

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();

        int i=0,j=0;
        while(i<n or j<m){
            if(i<n) s.insert(nums1[i++]);
            if(j<m) s.insert(nums2[j++]);
        }

        for(auto i:s){
            auto it1=find(nums1.begin(),nums1.end(),i);
            auto it2=find(nums2.begin(),nums2.end(),i);
            if(it1!=nums1.end() and it2!=nums2.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

t.c :- O(n+m)*(n+m)


optimized : 

t.c:-O(n+m) and s.c:-O(n+m)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end());
        set<int>a;

        for(auto i:nums2){
            if(s.count(i)){
                a.insert(i);
            }
        }
        vector<int>ans(a.begin(),a.end());
        return ans;
    }
};




class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //to is tarike se kisi me bhi sari values dali ja skti hai vector ki


        
        set<int>set1(nums1.begin(),nums1.end());//by this set gets elements which are unique
        set<int>set2(nums2.begin(),nums2.end());
        
        vector<int>ans;
        for(auto value:set1){
            if(set2.find(value)!=set2.end()){//we know that set2.find() operator if found returns and iterator to the element if not found then it return set2.end()
                ans.push_back(value);
            }
        }
        return ans;
        
    }
};

another way:-


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n1=nums1.size();
        int n2=nums2.size();


        vector<int>v;
        vector<int> visited(n2, 0);  // Initialize visited array with 0
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j] && visited[j]==0){
                    if(v.empty() || v.back()!=nums1[i]){
                        v.push_back(nums1[i]);
                    }
                    visited[j]=1;
                    break;
                }
                if(nums1[i]<nums2[j]){
                    break;
                }
            }
        }

        return v;
        
    }
};


t.c:-O(n1*n2) and s.c:-O(n2)

using while loop


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                // To avoid duplicates, check if the result is empty or last element is different
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};


can do like this also

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n1=nums1.size();
        int n2=nums2.size();


        vector<int>v;
        
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]>nums1[i]){
                j++;
            }
            else{
                if(v.empty() || v.back()!=nums1[i]){
                    v.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
        }
        
        return v;
        
    }
};

O(n1+n2) and O(1) are t.c and s.c
