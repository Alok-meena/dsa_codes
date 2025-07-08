Alien dictionary
Hard
120/120
Average time to solve is 46m
Contributed by
309 upvotes
Asked in companies
Problem statement
You have been given a sorted (lexical order) dictionary of an alien language.



Write a function that returns the order of characters as a string in the alien language. This dictionary will be given to you as an array of strings called 'dictionary', of size 'N'.



Example :
If the dictionary consists of the following words:-
["caa", "aaa", "aab"], and 'K' is 3.

Then, the order of the alphabet is -
['c', 'a', 'b']
Note:
If the language consists of four letters, the four letters should be the starting four letters of the English language. 

However, their order might differ in the alien language.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 1
a aa aaa
Sample Output 1 :
true
Explanation For Sample Output 1 :
The words are 'a', 'aa', and 'aaa'. Since the unique character here is 'a', the array to be returned will just be ['a']. 

The 'true' being printed signifies that the output returned by the function is valid.
Sample Input 2 :
3 3
caa aaa aab
Sample Output 2 :
true
Constraints :
1 ≤ N ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50

Time Limit: 1 sec




coding ninja one : k is given


string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<int> adj[k];

    int n=dictionary.size();

    int i=0,j=1;
    while(i<n and j<n){
        string a=dictionary[i];
        string b=dictionary[j];
        int len=min(a.length(),b.length());

        for(int d=0;d<len;d++){
            if(a[d]!=b[d]){
                adj[a[d]-'a'].push_back(b[d]-'a');
                break;
            }
        }
        i++;
        j++;
    }

     vector<int>indegree(k,0);
        for(auto i:adj){
            for(auto j:i){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        string order;
        for(auto i:ans){
            order.push_back('a'+i);
        }

    return order;
}

ye ques bahut imp hai suno  the note

Note:
If the language consists of four letters, the four letters should be the starting four letters of the English language. 

mtlb ager k=4 hai to char's me z nhi hoga o/w hmara adj list 4 size ka aor 25 ko kese map krega okk 

to ab geeksforgeeks ka ques jha k nhi diya tha we have to solve it like below alright

to bhai uper vale code me 2 cases ka dhyan hi nhi diya hai ek to if longer string is before and cycle is present so below is correct code


class Solution {
  public:
    string findOrder(vector<string> &dictionary) {
        // code here
        
        unordered_map<int,vector<int>>adj;
        set<int>s;
        
        for(auto st:dictionary){
            for(auto ch:st){
                s.insert(ch-'a');
            }
        }

    int n=dictionary.size();

    int i=0,j=1;
    while(i<n and j<n){
        string a=dictionary[i];
        string b=dictionary[j];
        int len=min(a.length(),b.length());
        bool found=false;

        for(int d=0;d<len;d++){
            if(a[d]!=b[d]){
                adj[a[d]-'a'].push_back(b[d]-'a');
                found=true;
                break;
            }
        }
        
        if(!found and a.length()>b.length()) return "";
        i++;
        j++;
    }
    
    int k=s.size();

     vector<int>indegree(26,0);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<26;i++){
            if(s.count(i) and indegree[i]==0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        string order;
        
        if(ans.empty() or ans.size()!=s.size()) return "";
        for(auto i:ans){
            order.push_back('a'+i);
        }

    return order;
    }
};

t.c and s.c :-O(v+e) alright mpp O(26+E)


and there is a similar looking ques on leetcode but is of easy type but in that used approach of above 2 ques alright

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>v(26,0);
        for(int i=0;i<26;i++){
            v[order[i]-'a']=i;
        }

        //here above we are storing the ordering rank of given alien order alright

        int n=words.size();

        for(int i=0;i<n-1;i++){
            string a=words[i];
            string b=words[i+1];

            int len=min(a.length(),b.length());
            bool found=false;

            for(int j=0;j<len;j++){
                if(v[a[j]-'a']<v[b[j]-'a']){
                    found=true;
                    break;
                }
                else if(v[a[j]-'a']>v[b[j]-'a']){
                    return false;
                }
            }

            if(!found and a.length()>b.length()) return false;
        }

        return true;
    }
};
