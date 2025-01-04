Boston Numbers
Medium
Difficulty
4
Submissions
100
Max Points
Status: Contest Over

0/100 Points
Problem
Submissions
Leaderboard
Discuss
A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. Write a program to check whether a given integer is a Boston number.


Input Format
There will be only one line of input:N , the number which needs to be checked.


Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)


Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.


Sample Input
378
Sample Output
1








#include<bits/stdc++.h>
using namespace std;



long digits_sum(long n){
	long digits_sum=0;
	long number=n;
	while(number){
		digits_sum+=(number%10);
		number/=10;
	}
	return digits_sum;
}

int main() {
	long n;
	cin>>n;

	long d_s=digits_sum(n);

	int i=2;
	long prime_sum=0;

  //so in this way also we can find the prime factors and also in other way by diving the number by i till root(n) okk
  //in this way

  //here after that also if the number is >1 then the number itself is also a prime number so include that also
  //take example of 17
 //  while(i*i<=n){
	// 	while(n%i==0){
	// 		prime_sum+=digits_sum(i);
	// 		n=n/i;
	// 	}
	//     i++;
	// }
	
	// if(n>1) prime_sum+=digits_sum(n);

  
	while(n!=1){
		if(n%i==0){
			prime_sum+=digits_sum(i);
			n=n/i;
		}
		else i++;
	}

	if(d_s==prime_sum) cout<<1;
	else cout<<0;

	return 0;
}
