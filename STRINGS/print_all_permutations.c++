Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.








class Solution
{
	public:
	    void solve(string s,vector<string>&ans,int index){
	        if(index>=s.length()){
	            ans.push_back(s);
	            return;
	        }
	        
	         unordered_set<char> seen;
           //ye for loop lgaya kyo taki current index ke char ko agge ke end tk ke char se swap kr ske 
            for(int j = index; j < s.length(); j++)
            {
                if(seen.find(s[j]) != seen.end()) // if s[j] is already used, skip it
                    continue;

                seen.insert(s[j]);
                swap(s[index], s[j]);
                solve(s, ans, index + 1);
                swap(s[index], s[j]);//backtrack as we are doing changes in the original string itself so make sure it remains same
            }
	    }
		vector<string> find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    sort(S.begin(),S.end());
		    int index=0;
		    solve(S,ans,index);
		    return ans;
		}
};



Use a set to track characters that have already been swapped at the current index.

Only proceed with a swap if the character has not been used at the current index.

this is for the cases like string ex:--- ABB and more like this


Time Complexity
The time complexity of generating permutations is O(n * n!), where n is the length of the string. This is because there are n! permutations and each permutation takes O(n) time to construct and insert into the result vector.

Space Complexity
The space complexity is O(n * n!) to store all the permutations, plus O(n) for the recursion stack and O(n) for the seen set used in each recursive call. So, the overall space complexity is O(n * n!).




