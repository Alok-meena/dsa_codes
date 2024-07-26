Problem statement
Two numbers ‘X’ and ‘Y’ are said to be ‘Zamn’ if both of them have different parities. You are given an array ‘A’ of size ‘N’ where each element is numbered from ‘0’ to ‘N - 1’.



You have to count the triplets ‘i’, ‘j’ and ‘k’ such that ‘i’ < ‘j’ < ‘k’ and both ‘(A[i], A[j])’, and ‘(A[j], A[k])’ are ‘Zamn’. These triplets are called ‘Zamn’ triplets.



Your task is to count all the ’Zamn’ triplets of the given array and return it.



##### Example:

‘N’ = 4
‘A’ = [1, 2, 5, 4]

The ‘Zamn’ triplets of the given array are: ‘(0, 1, 2)’ and ‘(1, 2, 3)’.

So, the count is equal to ‘2’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10
    1 <= 'N' <= 50
0 <= ‘A[i]’ <= 10^5

Time Limit: 1 sec 
Sample Input 1:
2
5
2 2 5 4 6
3
1 1 1
Sample Output 1:
4
0
Explanation of sample input 1:
For test case 1:
The ‘Zamn’ triplets of the given array are: ‘(0, 2, 3)’, ‘(0, 2, 4)’, ‘(1, 2, 3)’ and ‘(1, 2, 4)’. So, the count is equal to ‘4’.

For test case 2:
There is no ‘Zamn’ triplet in the given array. So, the count is equal to ‘0’.
Sample Input 2:
2
7
1 3 5 2 5 3 1
4
2 7 4 7
Sample Output 2:
9
2







to suno different parities means ki {odd even odd} / o/w similar pattern means pair with different parity to bas pura array from 1 to n-2; tk access kro and
if current element is odd/even then we know that we can count the even odd on both sides as per to the current element and ans me multiply krke add krte jao 
sare pairs ko bas yhi karna hai

int zamnTriplets (int n, vector <int> &a) {
   // Write your code here.
   int ans=0;

   for(int i=1;i<a.size()-1;i++){
      if(a[i]%2==1){
         int even_before=0,even_after=0;
         for(int j=i+1;j<a.size();j++){
            if(a[j]%2==0){
               even_after++;
            }
         }
         for(int j=i-1;j>=0;j--){
            if(a[j]%2==0){
               even_before++;
            }
         }
         ans+=even_before*even_after;
      }
      else{
         int odd_before=0,odd_after=0;
            for(int j=i+1;j<a.size();j++){
               if(a[j]%2==1){
                  odd_after++;
               }
            }
            for(int j=i-1;j>=0;j--){
               if (a[j] % 2 == 1) {
                  odd_before++;
               }
            }
            ans+= odd_before * odd_after;
      }
   }

   return ans;

}
