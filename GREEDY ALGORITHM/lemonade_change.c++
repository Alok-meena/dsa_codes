860. Lemonade Change
Solved
Easy
Topics
premium lock icon
Companies
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
 

Constraints:

1 <= bills.length <= 105
bills[i] is either 5, 10, or 20.



i was started doing like this but no

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sum=0;

        for(int i=0;i<bills.size();i++){
            int ret=bills[i]-5;

            if(i==0){
                sum+=bills[i];
                continue;
            }

            if(sum%ret!=0) return false;
            
        }

        return true;
    }
};


listen just think like a golggape vala if u dont have 5 rupee and have 10 u cant give 5 to anyone offering u 10 right

so u have to take track of 5 10 20 count of nnotes that's it 


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>v(3,0);

        for(auto i:bills){
            if(i==5){
                v[0]++;
            }
            else if(i==10){
                if(v[0]>=1){
                    v[1]++;
                    v[0]--;
                }
                else return false;
            }
            else if(i==20){
                if(v[1]>=1 and v[0]>=1){
                    v[2]++;
                    v[1]--;
                    v[0]--;
                }
                else if(v[0]>=3){
                    v[2]++;
                    v[0]-=3;
                }
                else return false;
            }
        }

        return true;
    }
};

simple O(n) solution alright
