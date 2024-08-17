ohn was learning about arrays when his friend Ram arrived. Seeing John, Ram thought of a challenge for him. He challenged John to calculate the "measurement" of an array a of size n.

Given a 0-indexed array, Ram defined the measurement of the array as the sum of the "sanities" of all the elements in the array. To calculate the sanity of each element in the array, the following operations need to be performed:

Sort the given array.
Calculate the sanity of an element in the array, which is defined as the sum of its original index (before sorting) and the index of its last occurrence in the new array (after sorting).
Your task is to help John calculate the measurement of the array. Since the output may be too large, print it modulo 10^9+7.

Note that duplicate elements may exist in the array.

Input Format
The first line contains ‘n’ denoting the number of elements in the array a.

The next line contains n elements denoting the elements of the array a.

Output Format
Print the measurement of the given array

Constraints
1<=n<=106

1<=ai<=106

Sample Testcase 0
Testcase Input
4 
1 1 1 1
Testcase Output
18
Explanation
The given array is 1 1 1 1. Array is already sorted therefore,


Sanity for the first 1 = 0 + 3.
Sanity for the second 1 = 1 + 3
Sanity for the third 1 = 2 + 3
Sanity for the fourth 1 = 3 + 3


Measurement of second array = 3 + 4 + 5 + 6 = 18

Sample Testcase 1
Testcase Input
6
2 1 3 2 3 1
Testcase Output
33
Explanation
The given array is: 2 1 3 2 3 1
After sorting array it become: 1 1 2 2 3 3.

For the first 1, the sanity is : 1 + 1 (sum of the original index of element before sorting and index of its last occurrence in new array)
Similarly for next 1, the sanity is: 1 + 5
For the next 2, the sanity is: 0 + 3
For the next 2, the sanity is : 3 + 3
For the next 3, the sanity is: 2 + 5
For the next 3, the sanity is: 4 + 5


So the measurement of the array is the sum of the sanities of all elements in the array : = 2 + 6 + 3 + 6 + 7 + 9 = 33






FIRSTLY I TRIED TO SOLVE THIS QUES USING MAP BUT WE CANT AS map cannot handle duplicate values so we have to use vector and solve the question


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define mod 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int>a(n);
    vector<pair<int,long long>>v;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v.push_back({a[i],i});
    }

    sort(a.begin(),a.end());
    sort(v.begin(),v.end());

    map<int,int>m;

    //it will store last occurences only as when duplicate value appears it updates the index value okk
    for(int i=0;i<n;i++){
        m[a[i]]=i;
    }

    long long count=0;

    for(auto i:v){
        int value=i.first;
        int original_index=i.second;
        int sorted_index=m[value];
        long long total=(original_index+sorted_index)%mod;
        count=(count+total)%mod;
    }

    
    cout<<count%mod;
}
