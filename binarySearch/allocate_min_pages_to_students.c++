Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 275K+Points: 4Average Time: 35m
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 

  

t.c:-O(nlogs)
 where s is sum of ele's of the array alright


class Solution {
  public:
    bool ispossilbe(vector<int>&v,int k,int value){
        int student_count=1; //here we have to start with 1st student alright as we are allocating pages to that student
        int page_sum=0;
        
        for(auto i:v){
            if(page_sum+i<=value){ //and it should be less than equal to vlaue alright not only less than 
                page_sum+=i;
            }
            else{
                student_count++;
                if(student_count>k or i>value){ //and here if stduent_c  is greater than only dont include equal to o/w wrong ans
                    return false;
                }
                page_sum=0;
                page_sum+=i;
            }
        }
        
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        //baki chlega to min aor 0 pe bhi but for efficiency take max ele only alright
        int mini=*max_element(arr.begin(),arr.end()); //it is imp to take max value because hame max no. of pages allcoated ko minimize karna hai 
        //aor bhai ssuno we have to minimize the max no. of pages so in worst case jo max pages honge vo array ke max pages hi honge alright
        int maxi=0;
        
        for(auto i:arr){
            maxi+=i;
        }
        
        int low=mini;
        int high=maxi;
        
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(ispossilbe(arr,k,mid)){
                ans=mid; //so this is one of the possible ans but we want to minimize this max ans so store it and go to left
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return ans;
    }
};
