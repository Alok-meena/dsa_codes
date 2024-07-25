Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is 1 if you modify the given array successfully.

Geeky Challenge: Solve this problem in O(n) time complexity.

Example 1:

Input: 
n = 5
array[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 
1
Explanation: 
One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be 1.
Example 2:

Input: 
n = 6 
array[] = {1, 4, 3, 6, 2, 1}
[a, b] = [1, 3]
Output: 
1
Explanation: 
One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be 1.








class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        sort(array.begin(),array.end());
        
    }
};






2: now if current element is smaller than a so take it as left as possible to the start and increment both ja and start and if a[j] is greater than b
take it as right as possible means at the end of the array and do end-- as it's position is full and dont do j++ as we again have to check the current element
which comes after swapping because it is possible that it may go to the start or remain at it's position

O(n) and O(1) 


class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int start=0;
        int end=array.size()-1;
        int j=0;
        while(j<=end){
            
            if(array[j]<a){
                swap(array[j++],array[start++]);//yha start++ and j++ dono kiya because start and i dono ko 0 se kiya hai to left vala khudh hi se swap ho rha hai
            }
            else if(array[j]>b){
                swap(array[j],array[end--]);
            }
            else{
                j++;
            }
        }
        
    }
};
