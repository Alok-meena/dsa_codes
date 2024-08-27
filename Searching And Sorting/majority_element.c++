






1). brute force


class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int i,j,cnt = 0;
        for(i=0;i<size;i++){
            cnt = 0;
            for(j=0;j<size;j++){
                if(a[i] == a[j])
                    cnt++;
            }
            if(cnt > (size/2))
                return a[i];
        }
        return -1;
        
    }
};

t.c:-O(n^2) and s.c:-O(1)

t.c:-O(n) and s.c:-O(n)

class Solution {
  public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size) {

        // your code here
        unordered_map<int,int>m;
        for(int i=0;i<size;i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.second>(size/2)) return i.first;
        }
        return -1;
    }
};


