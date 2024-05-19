
#include <iostream>
using namespace std;

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

class Trie{
    public:
      TrieNode* root;

      Trie(){
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

      void insertWord(string word){
        insertUtil(root,word);
      }

      bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isterminal;
        }

        int index=word[0]-'A';
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
    
    TrieNode* deleteWord(string word)
    {
        return deleteUtil(root, word);
    }
};

int main(){
    Trie *t=new Trie();
    t->insertWord("abcd");
    cout<<"Present or Not :"<<t->searchWord("abcd")<<endl;
    cout<<"deleted or not:"<<t->deleteWord("abcd");

}
