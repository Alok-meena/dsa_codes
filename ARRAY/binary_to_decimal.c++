#include<bits/stdc++.h>
using namespace std;

int b_d(int digit,int power){
	int m=pow(2,power);
	return m*digit;
}
int main() {
	int n;
	cin>>n;

	int decimal=0;
	int i=0;

	while(n){
		int rem=n%10;
		int val=b_d(rem,i);
		i++;
		decimal+=val;
		n=n/10;
	}
	cout<<decimal;
	return 0;
}
