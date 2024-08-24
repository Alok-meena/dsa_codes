Print Anagrams Together
Difficulty: MediumAccuracy: 65.78%Submissions: 67K+Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac 
god dog
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
is
no on
Explanation:
There are 2 groups of
anagrams "is" makes group 1.
"no", "on" make group 2.



 a word or phrase that is made by arranging the letters of another word or phrase in a different order





1st approach:


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>>m;
        int n=string_list.size();


   //{act,god,cat,dog,tac} ye vector hai apne pas and we are just sorting it and as key we store v[i] as a value 
     // ex act sort act then act->act,cat(after sort act to m[act]=cat store hoga) , tac 
                           //dgo->god,dog and then just store them into the ans vector
        for(int i=0;i<n;i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            m[s].push_back(string_list[i]);
        }
        
        vector<vector<string>>ans;

      //YHA PE SIZE MAT DE DENA ANS KO VO TAB DETE HAI JAB HAME PARTICULAR INDEX PE KOI VALUE DALNI HOTI HAI AGER DIRECT VECTOR ME DALNA HO TO PUSH_BACK USE KARNA
        
        for(auto i:m){
         //as hamne i.first me string aor i.second me vector<string> store ki hai to direct vector store ho jayega
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
};

t.c:-O(n*klogk) and s.c:-O(n*k) n is size of vector and k is len of strings



2:
