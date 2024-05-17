Ninja is given an array of integers that contain numbers in random order.
He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.


int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int>count;

    int maxfreq=0;
    int maxans=0;

    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxfreq=max(maxfreq,count[arr[i]]);
    }
    
    for(int i=0;i<arr.size();i++){
        if(maxfreq==count[arr[i]]){
            maxans=arr[i];
            break;
        }
    }
    return maxans;
    
}

Time Complexity
O(N) where N is the length of the array.

 

As we are traveling the entire array only twice, so time complexity is O(N)

Space Complexity
O(N) where N is the length of the array.

 

Using hashing, we count and store the frequency for all the unique elements.
So, in the worst case, if we have all the unique elements, then we will require O(N) space.
