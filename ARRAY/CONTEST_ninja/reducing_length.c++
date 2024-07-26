You are given an array 'A' of 'N' integers numbered from '0' to 'N - 1' and an integer 'X'.



In one operation, you can select 'i' ('0' <= 'i' <= 'N - 2') such that 'A[i]' and 'A[i + 1]' are less than 'X', remove 'A[i]' and 'A[i + 1]' and insert 'A[i] + A[i + 1]' at the same place.

For example, if you select 'i' equal to '1' in the array ['2', '6', '1', '9'], the resulting array is ['2', '6 + 1', '9'] = ['2', '7', '9'].



Determine whether you can have the length of the array '1' after performing any number of operations (possibly '0'). Return '1' in that case. Otherwise, return '0'.



Example:
N = 3
X = 5
A = [4, 3, 1]
In the first operation, you can select 'i' equal to '1'. So, the resulting array is ['4', '4'].
In the second operation, you can select 'i' equal to '0'. So, the resulting array is ['8'].
As the length of the array is '1', the answer for this case is '1'.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'N' <= 10^5
1 <= 'X' <= 10^9
1 <= 'A[i]' <= 10^4

Time limit: 1 sec
Sample input 1:
2
3 4
3 1 1
4 3
1 2 1 1
Sample output 1:
1
0
Explanation of sample input 1:
For test case 1:
In the first operation, you can select 'i' equal to '1'. So, the resulting array is ['3', '2'].
In the second operation, you can select 'i' equal to '0'. So, the resulting array is ['5'].
As the length of the array is '1', the answer for this case is '1'.

For test case 2:
It can be proved that you can not have the length of the array '1' after performing any number of operations.
So, the answer for this case is '0'.
Sample input 2:
2
6 12
4 2 1 8 1 3
6 11
2 2 2 2 2 10
Sample output 2:
0
1




so what we are doing is first calculating sum and then calculating prefixsuma and suffixsum if it is <x then okk suffixsum is calculated by sum-prefixsum
okk


int canYouReduce(int n, int x, vector<int> &v) {
    // Write your code here.
    
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }

    int prefix=0;
    for(int i=0;i<v.size();i++){
        prefix+=v[i];

        if(prefix<x && sum-prefix<x){
            return 1;
        }
    }
    
    return 0;
}
