Given an integer n, write a function that returns count of trailing zeroes in n!. 

Examples : 

Input: n = 5
Output: 1 
Explanation: Factorial of 5 is 120 which has one trailing 0.


Input: n = 20
Output: 4
Explanation: Factorial of 20 is 2432902008176640000 which has 4 trailing zeroes.


Input: n = 100
Output: 24


  The idea is to calculate the factorial of the number and then count the number of trailing zeros by repeatedly dividing the factorial by 10 till the last digit is 0. The number of times the factorial is divided by 10 is the number of trailing zeros. This approach is not useful for large numbers as calculating their factorial will cause overflow. 


[Expected Approach] Repeated division by 5 – O(logN base 5) Time and O(1) Space
The idea is to consider all prime factors of factorial n. A trailing zero is always produced by prime factors 2 and 5. If we can count the number of 5s and 2s in n!, our task is done. 



  Consider the following examples:


n = 5: There is one 5 and three 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is min(1, 3) = 1.
n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of trailing 0s is min(2, 8) = 2.


We can observe that the number of 2s in prime factors is always more than or equal to the number of 5s. So, if we count 5s in prime factors, we are done. 

means jo bhi factorial aayega uske prime factors me se min count of 2 and 5 dekh lo to count no. of zeroes



Consider the following examples:


n = 5: There is one 5 and three 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is min(1, 3) = 1.
n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of trailing 0s is min(2, 8) = 2.


We can observe that the number of 2s in prime factors is always more than or equal to the number of 5s. So, if we count 5s in prime factors, we are done. 


A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. But, numbers like 25, 125, etc have more than 5 instead of floor (n / 5). For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on.

Following is the summarized formula for counting trailing 0s:

Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + …





we just have to count the no. of 2's and 5's combinations in the prime factors of the given number right






172. Factorial Trailing Zeroes
Solved
Medium
Topics
Companies
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0

class Solution
{
    public:
       
        
        int findNum(int n)
        {
        //complete the function here
           int count=0;
           while(n/5>0){
               count+=(n/5);
               n=n/5;
           }
           return count;
        
        }
};
