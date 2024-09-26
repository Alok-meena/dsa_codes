Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


Examples :


Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).




1) brute force t.c:-O(n^3) s.c:-O(1)

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]<sum){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

2)  t.c:-O(n^2) and s.c:-O(1)

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        long long ans=0;
        
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            
            while(j<k){
                long long total=arr[i]+arr[j]+arr[k];
                if(total<sum){
                    ans+=k-j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};


Let me clarify the logic behind ans += (k - j) and how duplicates are handled in this approach.

Understanding ans += (k - j):
When you find that the sum of arr[i] + arr[j] + arr[k] is less than the target sum, it means that all the values between arr[j] and arr[k] form valid triplets with arr[i] because the array is sorted.

In other words:

Since arr[i] + arr[j] + arr[k] < sum, any element between arr[j + 1] to arr[k] will also form a valid triplet (because increasing arr[j] will still result in a sum smaller than sum).
Thus, there are k - j such valid pairs (because all elements from arr[j] to arr[k] are smaller than arr[k], and the array is sorted).

Example:
Suppose we have the array:

makefile
Copy code
arr = [1, 2, 3, 4, 5]
sum = 10
For i = 0 (arr[i] = 1), j = 1 (arr[j] = 2), and k = 4 (arr[k] = 5), we calculate:

css
Copy code
arr[i] + arr[j] + arr[k] = 1 + 2 + 5 = 8 < 10
This means that the triplets (1, 2, 3), (1, 2, 4), and (1, 2, 5) are all valid triplets. So instead of incrementing ans one by one, we directly add k - j = 4 - 1 = 3 valid triplets to ans.

Handling Duplicates:
Now, you asked about duplicates. The code actually handles duplicates correctly because we are:

Sorting the array: Once sorted, duplicate values will be adjacent to each other.
Using the two-pointer technique: After finding all valid pairs for a specific arr[i], we move the j and k pointers. Even if there are duplicates, the logic still works because the triplet will be counted once for every arr[j] and arr[k].
The sorting ensures that:

If arr[j] and arr[j+1] are the same, the combination arr[i] + arr[j] + arr[k] is still counted correctly without needing additional checks for duplicates.
Since the array is sorted and we are just moving pointers, any duplicates between arr[j] and arr[k] are implicitly handled by the logic.

Example with Duplicates:
Consider the array:

makefile
Copy code
arr = [1, 2, 2, 2, 3, 4]
sum = 7
For i = 0 (arr[i] = 1), j = 1 (arr[j] = 2), and k = 5 (arr[k] = 4), we calculate:

scss
Copy code
arr[i] + arr[j] + arr[k] = 1 + 2 + 4 = 7 == sum (not valid because we want strictly less than sum)
So we decrement k to k = 4 (arr[k] = 3).

Now,

css
Copy code
arr[i] + arr[j] + arr[k] = 1 + 2 + 3 = 6 < 7
This is a valid triplet, and because the array contains duplicates (arr[j] = 2 appears three times), we still only count this as k - j = 4 - 1 = 3 triplets:

(1, 2, 3)
(1, 2, 3) (with the second 2)
(1, 2, 3) (with the third 2)
The duplicate handling is implicitly correct because we're simply counting valid pairs between j and k, and all possible combinations are considered.

Final Thoughts:
ans += (k - j) works because it counts all possible triplets that form a valid sum for the current i.
Duplicates are handled implicitly by the two-pointer technique and sorting. You don't need to worry about skipping duplicates explicitly, as the logic naturally accounts for them.
Let me know if this clarifies your understanding!
