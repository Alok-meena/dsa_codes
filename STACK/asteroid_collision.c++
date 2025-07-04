
Code
Testcase
Testcase
Test Result
735. Asteroid Collision
Solved
Medium
Topics
premium lock icon
Companies
Hint
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0







class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;

        int n=asteroids.size();
        
        for(int i=0;i<n;i++){
            while(!s.empty() and s.top()>0 and asteroids[i]<0){ //+ and - yhi condition hai ager collision hua to alright that's why yhi use ki
                int sum=s.top()+asteroids[i];
                if(sum<0){
                    s.pop();
                }
                else if(sum>0){
                    asteroids[i]=0;
                    break;
                }
                else if(sum==0){
                    s.pop();
                    asteroids[i]=0;
                    break;
                }
            }
            if(asteroids[i]!=0) s.push(asteroids[i]);
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

here we can use vector instead of stack and use .back() .pop_back() alright
