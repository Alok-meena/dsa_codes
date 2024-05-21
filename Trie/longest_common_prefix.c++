You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings.
If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”


1).Brute force approach..........

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans="";
    //this for loop is for traversing all the characters of the first string
    for(int i=0;i<arr[0].length();i++){// to ye loop ham pahli string ke characters ko traverse krne ke liye kr rhe hai that's why we have used indexing 
      //like 2D array because strings have their own index along with the indices of the vector
        char ch=arr[0][i];
        
        bool match=true;
        
        //this for loop is for comparing remaining strings with the characters of the first string
        for(int j=1;j<n;j++){//aor yha 1 se start kiya because fist string is traversed
            
            if(arr[j].size()<i || ch!=arr[j][i]){ // it is take care ki size arr[j] ka means string ka <i hi ho and arr[j][i] means 1st string ith index
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
    
}

Time Complexity
O(N*M), where N is the number of strings in the array and M is the shortest length of the string present in the array.

 

We are doing M iteration, and in each iteration, we are traversing through the strings that take O(N) time. Hence, the overall time complexity is O(N*M).

Space Complexity
O(1). but by including ans space it is O(M)



2). Using Trie





class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isterminal;
      int childcount;

      TrieNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
      }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }

    void insertutil(TrieNode* root,string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->childcount++;
            root->children[index]=child;
        }

        insertutil(child,word.substr(1));
    }

    void insertword(string word){
        insertutil(root,word);
    }

    void lcp(string first,string &ans){

        for(int i=0;i<first.length();i++){

            char ch=first[i];

            if(root->childcount==1){//iska mtlb hai ager kisi bhi node ka 1 child hai means common hai nhi hai aor 1 se jyada hai to to common nhi hai
                ans.push_back(ch);
                //then aage bdh jao

                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }

            if(root->isterminal){//aor ager last tk pahuch gye to break kr do
                break;
            }
        }
    }

};

string longestCommonPrefix(vector<string> &arr, int n)
{
   
    Trie* t=new Trie();
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }

    string ans="";
    string first=arr[0];

    t->lcp(first,ans);
    return ans;

}





Time Complexity
O(N*M), where N is the number of strings in the array and M is the maximum length of the string present in the array.

 

We will insert all the strings into the trie, and each insertion takes O(M) time. So the total time taken is O(M*N). 
We used O(M) time to find the longest common prefix. Hence, the overall time complexity is O(M*N).

Space Complexity
O(N*M), where N is the number of strings in the array and M is the maximum length of the string present in the array.

 

We are using O(M*N) space to store all strings into the trie. Hence, the overall space complexity is O(M*N).


