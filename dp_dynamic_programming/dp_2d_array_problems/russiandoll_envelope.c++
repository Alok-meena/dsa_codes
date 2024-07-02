You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
MEANS 
In the context of the problem, "no rotate" means that you cannot change the orientation of the envelopes.
Specifically, each envelope must be placed with its width (wi) and height (hi) as given in the input. You cannot swap the width and height of any envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1





the below is my code



JUST KYA KIYA PAHLE WIDTH KE ACCORDING SORT KIYA AND THEN IF WIDTH EQUAL AAYI THEN HEIGHT KE ACCORDING DESCENDING ORDER ME SORT KIYA
BECASUE LIS HMARA INCREASING ORDER ME FIND KARTA HAI SEQUENCE KO SO LARGE HEIGHT KO PAHLE LE AAYE IF 2 WIDHTS ARE EQUAL FIR TO AGER EQUAL AA GYI 2 WIDTH
TO AOR ENVELOPES ko unme aage nhi dal payenge


YE HMARA 2D ARRAY THA TO COMAPARATOR KA USE KARNA HI PDA NORMAL 1 D ME TO HO JATA

AND THEN HEIGHTS PE HAMNE LONGEST INCREASING SEQUENCE LGA DIYA 

  
class Solution {
public:

//Basically a non-static member passes this referring to the object in question as the first parameter.
//So if we use sortByFirst without static keyword, there are a total of 3 parameters being passed,
//and the sort function is not able to handle that. That is why we use the static keyword

    static bool comparator(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];//to isse jab dono width equal hui to height ko descending order me 
            //sort kr diya jayega
        }

        return a[0]<b[0];//means by this we will sort according to width
    }

    int solve(int n,vector<vector<int>>&envelopes){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){//1 se hi start karna hai because 0th element to pahle hi dal diya ans me
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                //just bda index find kro in ans 
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comparator);//3 parameter pass kiye to error na aaye and compilter smj jaye that's why we used static keyword
        return solve(n,envelopes);
    }
};

t.c:-O(nlogn)===(O(nlogn)+O(nlogn)=O(nlogn)) of sort and binarysearch
s.c:-O(n)



IF HEIGHT AND WIDTH ARE GIVEN AS SEPARAT VECTORS THEN CODE FOR IT IS :---


#include <vector>
#include <algorithm>


static bool comparator(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];//to isse jab dono width equal hui to height ko descending order me 
            //sort kr diya jayega
        }

        return a[0]<b[0];//means by this we will sort according to width
    }

    int solve(int n,vector<vector<int>>&envelopes){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                //just bda index find kro in ans 
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        return ans.size();
    }

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    // Write your code here.
    vector<vector<int>>envelopes;
    for(int i=0;i<n;i++){
        envelopes.push_back({width[i],height[i]});
    }

    sort(envelopes.begin(),envelopes.end(),comparator);
    return solve(n,envelopes);
}
