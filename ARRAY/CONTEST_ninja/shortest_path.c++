There are ‘N’ shops numbered from ‘0’ to ‘N - 1’. Each shop contains lights of type ‘R’, ‘G’ or ‘B’ represented by a string ‘S’. You can start your journey from any shop ‘i’ where ‘i’ ranges from ‘0’ to ‘N - 1’.



In one minute you can move from shop ‘i’ to ‘i + 1’. Your task is to collect at least one light of each type ‘R’, ‘G’ and ‘B’ in the minimum number of minutes possible.



Your task is to tell the minimum number of minutes required to collect at least one light of each type and return it. If it is impossible to collect each type of light, return ‘-1’.



Example:
‘N’ = 8
‘S’ = “RRGGBGGR”

One of the possible ways is to start your journey from ‘1st’ cell. The path would look like: “1 -> 2 -> 3 -> 4”. So, the minimum number of minutes required to collect each type of light will be ‘4’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10
1 <= 'N' <= 10^5
‘S[i]’ belongs to the set ‘{‘R’, ‘G’, ‘B’}’

Time Limit: 1 sec 
Sample Input 1:
2
8
RRRRBBBG
3
GRR
Sample Output 1:
4
-1
Explanation of sample input 1:
For test case 1:
You can start your journey from ‘3rd’ cell and end your journey at ‘7th’ cell. The minutes required will be equal to ‘4’.

For test case 2:
Here, it is impossible to collect each type of light. So, the answer for this test case is ‘-1’.


1:brute force


int shortestPath (int n, string &s) {
   // Write your code here.
   int ans=INT_MAX;

   for(int i=0;i<n-2;i++){
      int arr[3]={1,1,1};
      int length=0;
      if(s[i]=='R' && arr[0]==1){
         arr[0]=0;
      }
      else if(s[i]=='G' && arr[1]==1){
         arr[1]=0;
      }
      else if(s[i]=='B' && arr[2]==1){
         arr[2]=0;
      }
      for(int j=i+1;j<n;j++){
         if(s[j]=='R' && arr[0]==1){
         arr[0]=0;
         }
         else if(s[j]=='G' && arr[1]==1){
            arr[1]=0;
         }
         else if(s[j]=='B' && arr[2]==1){
            arr[2]=0;
         }

         length++;
         // cout<<length<<" ";
         if(arr[0]==arr[1] && arr[1]==arr[2]){
            ans=min(ans,length);
            // cout<<ans<<" ";
            break;
         }
      }
   }
   if(ans==INT_MAX){
         return -1;
   }
    return ans;
}


2: optimal


int shortestPath (int n, string &s) {
   // Write your code here.
   int posR=-1,posG=-1,posB=-1;
   int ans=INT_MAX;

   for(int i=0;i<n;i++){
      int minpos;
      if(s[i]=='R'){
         posR=i;
      }
      else if(s[i]=='G'){
         posG=i;
      }
      else if(s[i]=='B'){
         posB=i;
      }

      minpos=min({posR,posG,posB});


      //to ager ham r g b sabhi ko traverse kr le tabhi minpos>=0 hogi nhi to ek me -1 hoga to min -1 hi aayega so ager sare traverse ho gye then update the min pos
      //in the answer
      if(minpos>=0){
         ans=min(ans,i-minpos);
      }
   }

   if (ans == INT_MAX) {
      return -1;
   }

   return ans;
}

O(n) and s.c:-O(1)
