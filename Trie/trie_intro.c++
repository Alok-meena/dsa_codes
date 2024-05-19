 
#include <iostream>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isterminal;

      TrieNode(char data){
        this->data=data;
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
        root=new TrieNode('\0');//to hmne root node ko null character se start kr diya
      }

      void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){//mtlb sari string traverse kr li to last character ko terminal mark do
            root->isterminal=true;
            return;
        }

        //assumption , that word will be in small letter
        int index=word[0]-'a';//to reach to the index where we have to insert the character
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){//mtlb hmara pahla character present hai to exist kr rha hai
            child=root->children[index];//to bs aage bdha diya
        }
        else{
            //absent
            child=new TrieNode(word[0]);//new node create kr li if present nhi hai to aor creation me sbse pahle to pahla character hi aayega to use kiya word[0]
            root->children[index]=child;
        }

        //RECURSION
        insertUtil(child,word.substr(1));// word ka aage vala part pass kr diya pahle character ko chod kar  aor substr(1) mtlb ex abcd hai to bcd pass kiya then cd hoga agle recursive call me
          // to 0th index ko chod ke baki ko pass kr rhe hai
      }

      void insertWord(string word){
        insertUtil(root,word);
      }

      bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isterminal;//mtlb ager current string khtm hogyi hai aor hm abhi terminal node pe hai ya nhi hai to string present o/w not
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];//bas same hai insertion ki tarah ager mil gya to aage bdh jao nhi to return false and then call it again
        }
        else{
            //absent
            return false;
        }

        //recursion
        return searchUtil(child,word.substr(1));
      }

      bool searchWord(string word){
        return searchUtil(root,word);
      }

       //Return True if the Trie node has no child, else false
    bool isEmpty(TrieNode* root)
    {
        for(int i=0;i<26;i++)
            if(root->children[i])
                return false;
        
        return true;
    }

    TrieNode* deleteUtil(TrieNode* root, string word)
    {
        if(root == NULL)
            return NULL;
        
        //Last character being processed
        if(word.length() == 0)
        {
            //This will not be a word after removal
            if(root->isterminal)
                root->isterminal = false;
            
            //If this is not a prefix of any other word. [not helping to make any other word]
            if(isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            
            return root;
        }
        
        //Recursion call
        int index = word[0] - 'a';
        root->children[index] = deleteUtil(root->children[index], word.substr(1));
        
        //Backtracking
        //If root has no child (as it's only child got deleted) and it is also not end of any other word
        if(isEmpty(root) && root->isterminal == false)
        {
            delete root;
            root = NULL;
        }
        
        return root;
    }
    
     bool deleteWord(string word){
    if (searchWord(word)) {  // Only attempt to delete if the word exists
        root = deleteUtil(root, word);
        return true;
    }
    return false;
     }
};

int main(){
  Trie *t = new Trie();
    t->insertWord("abcd");
    cout << "Present or Not: " << t->searchWord("abcd") << endl;
    bool deleted = t->deleteWord("abcd");
    cout << "Deleted or Not: " << deleted << endl;
    cout << "Present or Not after deletion: " << t->searchWord("abcd") << endl;

    delete t;

}


