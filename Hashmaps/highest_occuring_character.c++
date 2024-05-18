


#include <algorithm>
char highestOccurringChar(char input[]) {
    // Write your code here
    int arr[26]={0};
    int n=strlen(input);
    for(int i=0;i<n;i++){
        char ch=input[i];
        arr[ch-'a']++;
    }
    int count=-1;
    int ans=-1;
    for(int i=0;i<26;i++){
        if(arr[i]>count){
            count=arr[i];
            ans=i;
        }
    }
    return ans+'a'; 
}



2nd approach :
using maps

#include<bits/stdc++.h>

char highestOccurringChar(char input[]) {

    // Write your code here

    map<char,int> mpp;

    int n=strlen(input);

    for(int i=0;i<n;i++){

        mpp[input[i]]++; // means mapp[intput[i]] se hmne mapp[a] character ko access kiya aor increment bhi

    }

    int maxi=-1;

    char ans;

    for(auto it:mpp){

        if(it.second>maxi){

            maxi=it.second;

            ans=it.first; //aor bs corresponding max count ke corresponding first me jo character hai use return krva diya hai

        }

    }

    return ans;

}
