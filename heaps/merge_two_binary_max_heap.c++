Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}


class Solution{
    private:
    //we have used 0 based indexing so this heapify function is based on 0 based indexing
    void heapify(vector<int>&arr,int n,int i){ // this heapify function is for 0 based indexing..........
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){// ager ye condition satisfy ho jayegi mtlb hme swap krna hai node apni shi position pe nhi hai 
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }

        // instead of this you can do this also
         vector<int> ans(n + m);

        // Fill the first n elements of ans with elements from array a
        for (int i = 0; i < n; i++) {
            ans[i] = a[i];
        }

        // Fill the remaining m elements of ans with elements from array b
        for (int i = n; i < n + m; i++) {
            ans[i] = b[i - n]; // Adjust index to start from 0 for array b
        }




      
        int size=ans.size();

        for(int i=size/2-1;i>=0;i--){// this is for 1 based indexing and for 0 based indexing it is from n/2-1 equal to 0
          heapify(ans,size,i);
        }
        return ans;
    }
    
};

Expected Time Complexity: O(n.Logn) // O(N) for merging and O(logn) for heapify so O(nlogn)
Expected Auxiliary Space: O(n + m)
