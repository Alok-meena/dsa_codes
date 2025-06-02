





#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="hello guys welcome back";

    vector<string>temp;

    int i=0;
    while(i<s.length()){
        string t;
        while(i<s.length() and s[i]!=' '){
            t.push_back(s[i]);
            i++;
        }
        reverse(t.begin(),t.end());
        temp.push_back(t);

        i++;
    }

    for(auto i:temp) cout<<i<<" ";

}
