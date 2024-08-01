You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.
Example 2:

Input:
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.







1st:O(n*n) and s.c:-O(1)

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int len=s1.length();
        if(s1==s2) return 1;
        
        for(int i=1;i<len;i++){
            char ch=s1[0];
            for(int j=0;j<len-1;j++){
                s1[j]=s1[j+1];
            }
            s1[len-1]=ch;
            if(s1==s2){
                return 1;
            }
        }
        
        return 0;
    }
};

2nd:

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // Check if lengths are not the same
        if (s.length() != goal.length()) return 0;
        
        // Concatenate s1 with itself
        string temp = s + s;
        
        // Check if s2 is a substring of temp
        
        for(int i=0;i<temp.length();i++){
            int flag=1;
            int d=i;
            for(int j=0;j<goal.length();j++){
                if(goal[j]!=temp[d++]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                return 1;
            }
        }
        
        return 0;
    }
};

t.c:-O(n^2) and O(2*n) is s.c

the above code can be done using stl functions

#include <string>
using namespace std;

class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2) {
        int len = s1.length();
        
        // Check if lengths are not the same
        if (len != s2.length()) return false;
        
        // Concatenate s1 with itself
        string temp = s1 + s1;
        
        // Check if s2 is a substring of temp
        return temp.find(s2) != string::npos; //so if index return by find is not equal to npos then the substr s2 is present in the string temp
    }
};

The idea is to concatenate String P with itself and find out whether String Q is present in the resulting string as a substring. 
Let res be the string which is formed by the concatenation of String P with itself.
This approach works because all the N possible rotations of String P exist in the string res as a substring


3rd: which is the same thing we are doing above

int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    if(p.length()!=q.length()) return 0;

    string newstring=p+p;
    int i=0;
    int j=0;

    while(i<newstring.length()){
        if(newstring[i]==q[j]){
            i++;
            j++;

            if(j==q.length()) return 1;
        }

        else if(j!=0){
            j=0;//iska mtlb ki koi similar character mil gya hoga to b 0 nhi hai to fir 0 kr do
        }
        else{
            i++;//a ko to aage bdate hi rhna hai
        }
    }

    return 0;
}

t.c:-O(2n) and s.c:-O(2n)
