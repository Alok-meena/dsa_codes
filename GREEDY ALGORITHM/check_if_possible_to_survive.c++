Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.

Example 1:

Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to 
buy a box on the first day (Monday), 
it’s sufficient to eat from this box up to 
8th day (Monday) inclusive. Now, on the 9th 
day (Tuesday), you buy another box and use 
the chocolates in it to survive the 9th and 
10th day.


class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        //calculating no. of sundays
        
        int sunday=S/7;
        int buyingdays=S-sunday;
        int ans=0;
        int totalfood=S*M;
        
        if(totalfood%N==0){
            ans= totalfood/N;
        }
        else{
            ans=(totalfood/N) + 1;
        }
        
        if(ans<=buyingdays){
            return ans;
        }
        else{
            return -1;//if jyada ho gya
        }
        
    }
};


if((7*M > 6*N && S>6) || N < M) return -1 ;
return (S*M+(N-1))/N ; this is also ans t.c:-O(1) and O(1) for s.c also




// User function Template for C++

class Solution {
  public:
    int minimumDays(int s, int n, int m) {
        // code here
        if(m>n) return -1;
        if(s>6){
           if((7*m)>(6*n)) return -1;
        }
        
        int sundays=s/7;
        int buyDays=s-sundays;
        int tfood=s*m;
        
        if(tfood>(buyDays*n)) return -1;
        
        int ans=0;
        if(tfood%n==0){
            ans=tfood/n;
        }
        else{
            ans=(tfood/n)+1;
        }
        
        return ans;
    }
};



// User function Template for C++

class Solution {
  public:
    int minimumDays(int s, int n, int m) {
        // code here
        if(((7*m)>(6*n) and s>6) or n<m) return -1;
        
        int totalfood=s*m;
        int sundays=s/7;
        int buyingdays=s-sundays;
        
        if(totalfood>(buyingdays*n)) return -1;
        
        return (totalfood+n-1)/n;
    }
};
