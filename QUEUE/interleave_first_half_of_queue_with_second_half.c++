 Interleave The First Half Of The Queue With The Second Half
Easy
40/40
Average time to solve is 15m
Contributed by
52 upvotes
Asked in companies
Problem statement
You have been given a queue of integers. You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.

Note :
The given queue will always be of even length.
For example :
If N= 10
and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
then the output will be
 Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^2
2 <= N <= 10^3
0 <= data <= 10^4
Where ‘T’ is the number of test cases, “data” is the value of the element of the queue.
Sample Input 1:
1
10
10 20 30 40 50 60 70 80 90 100
Sample Output 1:
10 60 20 70 30 80 40 90 50 100
Sample Input 2:
1
6
10 20 30 40 50 60 
Sample Output 2:
10 40 20 50 30 60 








#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    vector<int>v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }

    int n=v.size();
    int i=0;
    int j=n/2;
    while(j<n){
        q.push(v[i]);
        q.push(v[j]);
        i++;j++;
    }
}

or

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        queue<int>a;
        queue<int>b;
        
        int n=q.size();
        
        int cnt=0;
        while(cnt<n/2){
            a.push(q.front());
            q.pop();
            cnt++;
        }
        
        while(!q.empty() and cnt<n){
            b.push(q.front());
            q.pop();
            cnt++;
        }
        
        cnt=0;
        
        while(!a.empty() and !b.empty()){
            q.push(a.front());
            q.push(b.front());
            a.pop();
            b.pop();
        }
        
        return q;
    }
};

t.c:-O(n) and s.c:-O(n)

with same t.c and s.c

if we use stack for this purpose then

#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int>s;
    int sz=q.size();

    int n=sz/2;

    while(n--){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    n=sz/2;
    while(n--){
        q.push(q.front());
        q.pop();
    }
    
    n=sz/2;
    while(n--){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }
}
