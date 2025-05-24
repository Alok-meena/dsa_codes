Problem statement
You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.



The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].



Your task is to find the minimum number in this array.



Note :
All the elements in the array are distinct. 


Example :
Input: arr = [3,4,5,1,2]

Output: 1

Explanation: The original array was [1,2,3,4,5] and it was rotated 3 times.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4
3 4 1 2   


Sample Output 1 :
1


Explanation of Sample Input 1 :
The original array was [1, 2, 3, 4] and it was rotated 2 times.


Sample Input 2 :
6
25 30 5 10 15 20


Sample Output 2 :
5


Explanation of Sample Input 2 :
The original array was [5, 10, 15, 20, 25, 30] and it was rotated 2 times.


Expected Time Complexity:
Try to solve this with O(log(n)) time complexity.


Constraints :
1 <= n <= 10^5
1 <= arr[i] <= 10^9

Time Limit: 1 sec





int findMin(vector<int>& arr)
{
	// Write your code here.
	int n=arr.size();

    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        //left part sorted
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]); //ager left sorted hai to min to low hi hoga alright
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]); //ager right sorted hai to right me jane k ko fayda nhi for min as curr ele is possible min and update ans and go to left alright
            high=mid-1;
        }
    }
	return ans;
}
