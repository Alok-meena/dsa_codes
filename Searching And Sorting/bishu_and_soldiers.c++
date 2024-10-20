Problem
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
Sample Output
3 6
7 28
2 3








#include <bits/stdc++.h>
using namespace std;


void solve(int power,int soldiers[],int n){
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(soldiers[i]<=power){
            count++;
            sum+=soldiers[i];
        }
    }
    cout<<count<<" "<<sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int power;
        cin>>power;
        solve(power,arr,n);
        cout<<endl;
    }
}

t.c:-O(n*q) s.c:-O(n)



optimized using binary search


#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;

    sort(arr,arr+n);

    int sum[n];
    int value=0;
    for(int i=0;i<n;i++){
        value+=arr[i];
        sum[i]=value;
    }
    for(int i=0;i<q;i++){
        int power;
        cin>>power;
        int index=upper_bound(arr,arr+n,power)-arr;
        int Sum=sum[index-1];
        cout<<index<<" "<<Sum;
        cout<<endl;
    }
}

t.c:-O(nlogn+qlogn) and s.c:-O(n)+logn for sorting
