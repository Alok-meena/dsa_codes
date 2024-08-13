A string is considered valid if it can be written as a concatenation of ‘X’ number of ‘<’ characters, followed by ‘|’ character, and then ‘X’ number of ‘>’ characters where ‘X’ is some positive integer. For example “<<|>>” is a valid string. A super valid string is a concatenation of different valid strings. For example: “<<|>><|>” is a super valid string.



You are given a string ‘S’ of length ‘N’ where each character can be either ‘<’, ‘|’ or ‘>’ and are numbered from ‘0’ to ‘N - 1’. You have to count the number of super valid substrings of the given string.



Your task is to count the number of super valid substrings of the given string and return it.



Example:
‘N’ = 12
‘S’ = “<|>|<<|>><|>”

The super valid substrings of the given string ‘S’ are: “<|>”, “<<|>>”, “<|>”,  “<<|>><|>”, and “<|>”.

So, the count is equal to ‘5’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10
1 <= 'N' <= 10^5
‘S[i]’ belongs to the set {‘<’, ‘|’, ‘>’}       

Time Limit: 1 sec 
Sample Input 1:
2
9
<|><|><|>
6
>|<|<>
Sample Output 1:
6
0
Explanation of sample input 1:
For test case 1:
The super valid substrings of the given string ‘S’ are: “<|>”, “<|><|>”, “<|><|><|>”, ‘<|>”, “<|><|>”, and “<|>”,

So, the count is equal to ‘6’.

For test case 2:
Here, no substring is super valid. So, the count is equal to ‘0’.
Sample Input 2:
2
16
<|><|>><|><|><|>
2
||
Sample Output 2:
9
0
















long long superValidSubstrings (int n, string &s) {
   // Write your code here.
   long long ans=0;
   vector<int>count(n);

   for(int i=n-1;i>=0;i--){
      if(s[i]=='|'){
         int j=i-1;
         int k=i+1;
         while(j>=0 && k<n && s[j]=='<' && s[k]=='>'){
            count[j]=1+(k+1<n?count[k+1]:0);//ye isiliye use kiya hai kyoki ager beech me | nhi aaya to count karna hai dono ko ex: <<|>><|>
            j-=1;
            k+=1;
         }
      }

      ans+=count[i];
   }

   return ans;
}
