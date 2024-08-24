A cafe has N computers. Several customers come to the cafe to use these computers. A customer will be serviced only if there is any unoccupied computer at the moment the customer visits the cafe. If there is no unoccupied computer, the customer leaves the cafe. 

You are given an integer N representing the number of computers in the cafe and a sequence of uppercase letters S. Every letter in S occurs exactly two times. The first occurrence denotes the arrival of a customer and the second occurrence denotes the departure of the same customer if he gets allocated the computer. 

You have to find the number of customers that walked away without using a computer.


Example 1:

Input:
N = 3
S = GACCBDDBAGEE
Output: 1
Explanation: Only D will not be able to 
get any computer. So the answer is 1.

Example 2:


N = 1
S = ABCBAC
Output: 2
Explanation: B and C will not be able to 
get any computers. So the answer is 2.


  t.c:-O(n) and s.c:-O(1) as there are only 26 char




class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int computers_available=n;
        // vector<char>v;
        map<char,int>m;
        int count=0;
       
        for(auto i:s){
            if(m[i]==0){
                if(computers_available>0){
                    m[i]=1;
                    computers_available--;
                }
                else{
                    m[i]=-1;
                    count++;
                }
            }
            else if(m[i]==1){
                // m[i]=0;
                computers_available++;
            }
        }
        
        return count;
    }
};
