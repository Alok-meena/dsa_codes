Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)







DURINg coversion from roman to number we have to add up the value of the symbols in roman form 
there are 2rules:
  any symbol can be repeated consecutively only 3 times and in 2 consecutive symbols if fisrt symbol decimal value is smaller then it gets substracted o/w added

class Solution {
  public:
    int solve(char a){
        if(a=='I') return 1;
        else if(a=='V') return 5;
        else if(a=='X') return 10;
        else if(a=='L') return 50;
        else if(a=='C') return 100;
        else if(a=='D') return 500;
        else if(a=='M') return 1000;
    }
    int romanToDecimal(string &str) {
        // code here
        
        //HERE NO NO. CAN BE PRESENT MORE THAN CONSECUTIVELY 3 TIMES
        int ans=0;
        int n=str.length();
        
        for(int i=0;i<n;i++){
            
            //if i is not the last char then do this
            if(i<n-1){
                int v1=solve(str[i]);
                int v2=solve(str[i+1]);
                if(v1<v2){
                    ans=ans-v1;
                }
                else{
                    ans=ans+v1;
                }
            }
            else{
                ans=ans+solve(str[i]);
            }
        }
        
        return ans;
    }
};
