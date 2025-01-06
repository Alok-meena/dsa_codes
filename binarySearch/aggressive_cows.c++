Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3


Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.


Sample Input 2 :
5 2
4 2 1 3 6


Sample Output 2 :
5


Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?


Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec


  in the ques given that min dist b/w all cows should be max 
so let's check what is our ans search space min dist is min of thee array and max dist is max of the array that's all

now apply binary search if with distance mid we can place the cow then we will store the ans and move towards right okk 
because we have to maximize the answer okk o/w we should move towards left becaause if we cant place with mid distance then not possible with greater distance also
 then move towards left because ans apna left me hi hoga 






FOR THIS PROBLEM SORTING IS MUST 

O(n)

bool canplace(vector<int>&stalls,int k,int n,int minDistance){
    int placed_cows=1;
    int last_cow_location=stalls[0];
    
    for(int i=1;i<n;i++){
        if(stalls[i]-last_cow_location>=minDistance){
            placed_cows++;
            last_cow_location=stalls[i];
            if(placed_cows>=k) return true;
        }
    }

    //here we should have to include the condtion >=k o/w if only ==k then if more than k cows can be placed than false will be return but 
  //we want to maximize the min distance that's why we did so

    if(placed_cows>=k){
        return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());

    int n=stalls.size();
    int l=0; //min dist b/w 2 cows possible is 0
    int h=stalls[n-1];

    int ans=-1;

    //can also do like this brute force checking for all of the distances O(n*maxDist)
    // for(int i=l;i<=h;i++){
    //     if(canplace(stalls,k,n,i)){
    //         ans=max(ans,i);
    //     }
    // }

    //O(log(maxdistance) where maxdist=stalls[n-1]
    while(l<=h){
        int mid=(l+h)/2;

        if(canplace(stalls,k,n,mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    return ans;
    
}

therefore t.c:-O(nlog(maxDistance)) and s.c:-O(1)
