Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)








class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        
        int left=0;
        int right=arr.size()-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]==key){
                return mid;
            }
            
            //now checking which part is sorted
            
            // If the left part is sorted
            if(arr[left]<=arr[mid]){
                
                //checking if exits in left part
                if(arr[left]<=key && key<=arr[mid]){
                    right=mid-1;//check in left part
                }
                else{
                    left=mid+1;//o/w check in right part
                }
            }
            
            //but if right part is sorted then
            else{
                //checking in right part
                if(arr[mid]<key && key<=arr[right]){ //to yha pe arr[mid] ke equal to nhi ho skta hai because vo hamne uper hi include kr liya hai okk so not
//possible here right yes sir absolutely kese ho yar aap log
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
