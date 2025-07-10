721. Accounts Merge
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.








class DisjointSet{
    public:
    
    vector<int>rank,parent;
    
    DisjointSet(int size){
        rank.resize(size+1);
        parent.resize(size+1);
        
        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }
    
    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);
        
        if(up==vp) return;
        
        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int>mailtoNode;

        for(int i=0;i<n;i++){
            //always start with j=1 as we have to skip the names and take only mails
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];

                //if the mail is not pointing to any node then make it to point o/w if it is pointing to someone means
                //it should point to some other node but pointing to some other so merge them alright
                if(mailtoNode.find(mail)==mailtoNode.end()){
                    mailtoNode[mail]=i;
                }
                else{
                    ds.unionByRank(i,mailtoNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        
        //now here we are just merging all the mails to correct nodes 
        for(auto it:mailtoNode){
            string mail=it.first;
            //we will always put the mail under the ultimate paretn because that is the place where the mail should be 
            //because if the mail belongs to some other person then definitely it should belong to that 
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        //now preparing answer
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto st:mergedMail[i]){
                temp.push_back(st);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

t.c:-O(mlogm) and s.c:-O(n+m) alright


to run the gfg code we have to make 2 changes dont know why ?

  // User function Template for C++
class DisjointSet{
    public:
    
    vector<int>rank,parent;
    
    DisjointSet(int size){
        rank.resize(size+1);
        parent.resize(size+1);
        
        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }
    
    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);
        
        if(up==vp) return;
        
        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};


class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& accounts) {
        // code here
        int n=accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int>mailtoNode;

        for(int i=0;i<n;i++){
            //always start with j=1 as we have to skip the names and take only mails
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];

                //if the mail is not pointing to any node then make it to point o/w if it is pointing to someone means
                //it should point to some other node but pointing to some other so merge them alright
                if(mailtoNode.find(mail)==mailtoNode.end()){
                    mailtoNode[mail]=i;
                }
                else{
                    ds.unionByRank(mailtoNode[mail],i);  //pass this format not i,mailtoNode[mail] it is not passing 3rd test case alright
                }
            }
        }

        vector<string> mergedMail[n];
        
        //now here we are just merging all the mails to correct nodes 
        for(auto it:mailtoNode){
            string mail=it.first;
            //we will always put the mail under the ultimate paretn because that is the place where the mail should be 
            //because if the mail belongs to some other person then definitely it should belong to that 
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        //now preparing answer
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto st:mergedMail[i]){
                temp.push_back(st);
            }
            ans.push_back(temp);
        }
        
        reverse(ans.begin(),ans.end());   //reverse this

        return ans;
    }
};
