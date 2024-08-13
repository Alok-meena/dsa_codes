You are given a permutation of length 'N' containing elements from '1' to 'N'.



Let's define the two types of operations on the permutation.

In operation-1, you can select the indices 'i' and 'j' ('i' < 'j') and swap 'P[i]' and 'P[j]'.

In operation-2, you can perform a left shift on the permutation. For example, ['1', '2', '3'] becomes ['2', '3', '1'].



First you have to perform the operation-1 on the permutation exactly once. Then you have to perform the operation-2 on the permutation any number of times.



Determine whether the permutation 'P' can become sorted after performing the operations as mentioned. Return '1' in that case. Otherwise, return '0'.

Example:
N = 3
P = [3, 2, 1]
First you will choose indices '0' and '1' and perform operation-1. So, the resulting permutation is ['2', '3', '1']. Note that we are using 0-based indexing.
Then you will perform operation-2 two times. So, the resulting permutation is ['1', '2', '3'] which is sorted.
So, the answer for this case is '1'.






i did used brute force approach as i didnt get any other approach to solve this question okkk

APPROACH I USED :- i swapped each and every element and checked if the array become sorted or not

int canYouSort(int n, vector<int> &p) {
    // Write your code here.
    if(n<=2) return 1;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            
            vector<int>temp=p;
            swap(temp[i],temp[j]); 

            int pos=0;
            //after swapping i am finding position/ index of element 1 we are doing so as elements are given from 1 to N-1
            for(int k=0;k<n;k++){
                if(temp[k]==1){
                    pos=k;
                    break;
                }
            }

            bool isSorted=true;
            for(int k=0;k<n;k++){
                //after that i am checking from element 1 if next element is == k+1 then okk move on o/w not sorted EXAMPLE GIVEN AT THE LAST
                if(temp[(pos+k)%n]!=k+1){
                    isSorted=false;
                    break;
                }
            }

            if(isSorted){
                return 1;
            }
        }
    }

    return 0;
}

t.c:-O(n^3) and s.c:-O(n)


//example

//Consider a permutation [3, 4, 1, 2]:

// After a swap (say swapping 3 and 4 to get [4, 3, 1, 2]), the position of 1 is 2.
// We then check if starting from index 2, the permutation forms [1, 2, 3, 4] in a circular manner:
// temp[(2 + 0) % 4] should be 1
// temp[(2 + 1) % 4] should be 2
// temp[(2 + 2) % 4] should be 3
// temp[(2 + 3) % 4] should be 4
