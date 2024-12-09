


so lcm of numbers is min value which is divisible both all of them
and reverse in case of hcf max value which divides all of the given numbers





Problem
Submissions
Leaderboard
Discuss
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.


Input Format

Constraints
0 < N1 < 1000000000
0 < N2 < 1000000000


Output Format

Sample Input
4 
6
Sample Output
12
Explanation

The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
this is the most important line to solve this ques

(we will iterate from max value to 1  and check the min value which will be divisible by both of them)

lcm 


#include<bits/stdc++.h>
using namespace std;
int main() {

	int a;
	int b;
	cin>>a>>b;

	int ans=INT_MAX;

	for(int i=a*b;i>=1;i--){
		if(i%a==0 && i%b==0){
			ans=min(ans,i);
		}
	}

	cout<<ans;

	return 0;
}


Problem
Submissions
Leaderboard
Discuss
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the GCD of N1 and N2. Print the value returned.


Input Format
Two integers seperated by a new line.


Constraints
0 < N1 < 1000000000
0 < N2 < 1000000000


Output Format
Output a single integer which is the GCD of the given integers.


Sample Input
16 
24
Sample Output
8
Explanation
The largest number that divides both N1 and N2 is called the GCD of N1 and N2




#include<iostream>
using namespace std;
int main() {
	int a;
	int b;
	cin>>a>>b;

	int ans=-1;

	for(int i=1;i<=min(a,b);i++){
		if(a%i==0 && b%i==0){
			ans=max(ans,i);
		}
	}

	cout<<ans;
	return 0;
}
