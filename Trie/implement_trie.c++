Problem statement
Implement Trie Data Structure to support these operations:

insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".


Three type of queries denote these operations:

Type 1: To insert a string "word" in Trie.
1 word

Type 2: To check if the string "word" is present in Trie or not.
2 word

Type 3: To check if there is any string in the Trie that starts with the given prefix string "word".
3 word


/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isterminal;

      TrieNode(char data){
        data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
      }
};

class Trie {

public:
          TrieNode* root;


    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode('\0');

    }
    

     void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){//mtlb sari string traverse kr li to last character ko terminal mark do
            root->isterminal=true;
            return;
        }

        //assumption , that word will be in small letter
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //RECURSION
        insertUtil(child,word.substr(1));
      }


    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root,word);

    }


    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isterminal;
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }

        //recursion
        return searchUtil(child,word.substr(1));
      }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);

    }
  

   bool prefixutil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }

        //recursion
        return prefixutil(child,word.substr(1));
      }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixutil(root,prefix);
    }
};
