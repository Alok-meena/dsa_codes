443. String Compression
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.








class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans;

    int count=1;
    for(int i=1;i<chars.size();i++){
        if(chars[i]==chars[i-1]){
            count++;
        }
        else{
            ans.push_back(chars[i-1]);
            if(count<10){
                char ch=count+'0';
                if(count>1) ans.push_back(ch);
            }
            else{
                vector<char>ch;
                while(count){
                    int value=count%10;
                    ch.push_back(value+'0');
                    count/=10;
                }
                reverse(ch.begin(),ch.end());
                for(auto i:ch){
                    ans.push_back(i);
                }
            }
            count=1;
        }
    }

    ans.push_back(chars[chars.size()-1]);
            if(count<10){
                char ch=count+'0';
                if(count>1) ans.push_back(ch);
            }
            else{
                vector<char>ch;
                while(count){
                    int value=count%10;
                    ch.push_back(value+'0');
                    count/=10;
                }
                reverse(ch.begin(),ch.end());
                for(auto i:ch){
                    ans.push_back(i);
                }
            }

    chars=ans;
    return ans.size();
    }
};

or we can convert the count to string instead of converting using while loop alright


class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans;

    int count=1;
    for(int i=1;i<chars.size();i++){
        if(chars[i]==chars[i-1]){
            count++;
        }
        else{
            ans.push_back(chars[i-1]);
            if(count<10){
                char ch=count+'0';
                if(count>1) ans.push_back(ch);
            }
            else{
                string s=to_string(count);
                for(auto i:s){
                    ans.push_back(i);
                }
            }
            count=1;
        }
    }

    ans.push_back(chars[chars.size()-1]);
            if(count<10){
                char ch=count+'0';
                if(count>1) ans.push_back(ch);
            }
            else{
                string s=to_string(count);
                
                for(auto i:s){
                    ans.push_back(i);
                }
            }

    chars=ans;
    return ans.size();
    }
};



more optimized s.c :- O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int ansindex=0; //ye index ham return krenge as the size of our array alright
        int i=0;

        while(i<chars.size()){
            int j=i+1;
            while(j<chars.size() and chars[i]==chars[j]){
                j++;
            }

            chars[ansindex++]=chars[i];
            int count=j-i;

            if(count>1){
                string s=to_string(count);
                for(auto i:s){
                    chars[ansindex++]=i;
                }
            }
            i=j; //ye kra means jab equal nhi aaya 
        }

        return ansindex;
    }
};

are dhyan se suno hm curr array me hi changes kr denge alright easily okk ho jayega 
