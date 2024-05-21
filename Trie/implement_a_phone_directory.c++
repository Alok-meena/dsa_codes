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
        if(curr->isterminal){//ager strings me last tk pahuch gye to temp me dal do
            temp.push_back(prefix);
            
        }

        for(char ch='a';ch<='z';ch++){
            //to ham check krenge ki in sare character me a-z koi bhi inka child hai ya nhi
            TrieNode* next=curr->children[ch-'a'];

            if(next!=NULL){//iska mtlb child exist kr rha hai
                prefix.push_back(ch);//to prefix me dal do fir 
                printSuggestions(next,temp,prefix);//fir call kro for the complete prefix
                //aor jese hi end tk pahuchoge to prefix ko temp me dalke vapas aa jao
                //aor fir prefix ko khali kro aor next child ko check kro
                prefix.pop_back();
            }
        }

    }

    vector<vector<string>> getSuggestions(string str){//ye jo query string pass ho ke hmare pas aayi hai
        // ye hai prefix jise ham search krenge
        TrieNode* prev=root;
        vector<vector<string>>output;
        string prefix="";

        for(int i=0;i<str.length();i++){
            char last_character=str[i];//to last character hmne c ko hi liya hai (coding)

            prefix.push_back(last_character);//aor fir prefix me dal diya

            //check for last_character
            TrieNode* curr=prev->children[last_character-'a'];//aor c ko curr mark kr diya

            //if not found
            if(curr==NULL){//mtlb character nhi mila to NULL
                break;
            }
            //if found
            vector<string>temp;//but ager mil gya to sari suggestions ko print kr lo
            printSuggestions(curr,temp,prefix);//ye hme vo sari strings de dega jo aayegi

            //aor prefix jo print me pass kiya tha usme characters hogi jo push ki hai 
            output.push_back(temp);//aor fir ye temp jo strings store krega use output me dalo
            // jise ham return krenge and then clear it because now not needed
            temp.clear();
            prev=curr;//aor ab prev jo root pe that curr pe le aao for next character
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
