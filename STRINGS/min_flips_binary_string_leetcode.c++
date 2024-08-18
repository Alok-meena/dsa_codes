1888. Minimum Number of Flips to Make the Binary String Alternating
Solved
Medium
Topics
Companies
Hint
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".


t.c:-O(n) and s.c:-O(n)










class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        //jo pahla type 1 operation hai uske hisab se hamne sari rotations ke liye s+s concatenate kr diya hai
        string str=s+s;

      //then creating two possible strings of str after operations
        string s1="";//for 01...
        string s2="";//for 10...
        for(int i=0;i<str.length();i++){
            s1+=(i%2==0)?'0':'1';
            s2+=(i%2==0)?'1':'0';
        }

        int ans=str.size();
        int ans1=0;
        int ans2=0;

        //ex 1100 then str=11001100 
         //             s1=01010101
       //               s2=10101010
       //to ans1 bta rha hai ki kitne type1 operation lge str me taki vo s1 ko replicate kre mtlb usme convert ho and similar for ans2 and ans is for all 
      //rotations

        for(int i=0;i<str.length();i++){
            //here the expression gives 1/0 not t/f okk
            ans1+=(str[i]!=s1[i]);
            ans2+=(str[i]!=s2[i]);

            if(i>=n){
                //esa hote hi pichli window ke type2 operations ko htate jao and at last ans update ho jayega
                ans1-=(str[i-n]!=s1[i-n]);
                ans2-=(str[i-n]!=s2[i-n]);
            }

           //so that correct ans is updated after s length which is the given string
           //jaise hi i>=n-1 hoga to hmara ans har bar update hoga to bas ans-= kr rhe hai taki jaise hi 1 pichli window ka htaya nyi window ka ans add bhi hoga 
          //and we will return the min value as the answer
            if(i>=(n-1)){
                ans=min(ans,min(ans1,ans2));
            }
        }
        return ans;
    }
};
