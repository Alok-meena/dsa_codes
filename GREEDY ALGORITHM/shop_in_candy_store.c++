
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
For every candy you buy from the store and get K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example 1:

Input:
N = 4
K = 2
candies[] = {3 2 1 4}


TO PAHLE MIN AMOUNT HAI TO EK KAM KRO min amount ki candy buy kro by sorting it and k candy free max amount ki lo 
and reverse to get the max amount

class Solution
{
public:
    int solve1(int candies[],int n,int k){
        sort(candies,candies+n);
        int amount=0;
        int i=0;
        int j=n-1;//as we are buying free from last which is max
        while(i<=j){
            amount=amount+candies[i];
            i++;
            j=j-k;
        }
        return amount;
    }
    int solve2(int candies[],int n,int k){
        sort(candies,candies+n);
        int amount=0;
        int i=0;
        int j=n-1;//as we are buying free from last which is max
        while(i<=j){
            amount=amount+candies[j];
            j--;
            i=i+k;
        }
        return amount;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int>ans;
        int minAmount=solve1(candies,N,K);
        int maxAmount=solve2(candies,N,K);
        ans.push_back(minAmount);
        ans.push_back(maxAmount);
        return ans;
    }
};

t.c:-O(nlogn) and s.c:-O(1)


or can also do like


class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& arr, int k) {
        // Code here
        int mini=0;
        int maxi=0;
        
        int candies=arr.size();
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            mini+=arr[i];
            candies=candies-k-1;
            if(candies<=0) break;
        }

        candies=arr.size();
        
        for(int i=arr.size()-1;i>=0;i--){
            maxi+=arr[i];
            candies=candies-k-1;
            if(candies<=0) break;
        }
        
        return {mini,maxi};
        
        
    }
};
