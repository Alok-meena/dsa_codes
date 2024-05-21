You are given a list/array of strings which denotes the contacts that exist in your phone directory.
The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’.
One special property of the search function is that when a user searches for a contact from the contact list
then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

Note :
If no suggestions are found, return an empty 2D array.




class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isterminal;

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
            root->children[index]=child;
        }

        insertutil(child,word.substr(1));
    }

    void insertword(string word){
        insertutil(root,word);
    }

    void printSuggestions(TrieNode* curr,vector<string>&temp,string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
            
        }

        for(char ch='a';ch<='z';ch++){
            TrieNode* next=curr->children[ch-'a'];

            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }

    }

    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev=root;
        vector<vector<string>>output;
        string prefix="";

        for(int i=0;i<str.length();i++){
            char last_character=str[i];

            prefix.push_back(last_character);

            //check for last_character
            TrieNode* curr=prev->children[last_character-'a'];

            //if not found
            if(curr==NULL){
                break;
            }
            //if found
            vector<string>temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;
        }

        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t=new Trie();

    //insert all contact in trie

    for(int i=0;i<contactList.size();i++){
        t->insertword(contactList[i]);
    }

    //return ans

    return t->getSuggestions(queryStr);
}


O(N * (W ^ 2)), where ‘N’ is the number of elements in the given array/list and ‘W’ is the average length of the string.


Space Complexity
O(N * W), where ‘N’ is the number of elements in the given array/list and ‘W’ is the average length of the string.
