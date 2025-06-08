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






FOR THIS PROBLEM SORTING IS MUST because then only next dist - prev dist can be positive o/w it can be negative alright

O(n)

bool canplace(vector<int>&stalls,int k,int n,int minDistance){
    int placed_cows=1;
    int last_cow_location=stalls[0];
    
    for(int i=1;i<n;i++){
        //and we are chceking if this difference is greater than equal to mindist alright then only we can place o/w we cannot place for this distance alright
        if(stalls[i]-last_cow_location>=minDistance){ //min dist se jyada hai to bdiya
            placed_cows++;
            last_cow_location=stalls[i];
            if(placed_cows>=k) return true; //aor ager jitni cows hame place krni hai utni ho gyi y jyada to bs shi hai aor apna kam bhi ho jayega alright
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
            l=mid+1; //as we have to maximmize our ans so always have to go to the right alright
        }
        else{
            h=mid-1;
        }
    }

    return ans;
    
}

therefore t.c:-O(nlog(maxDistance)) and s.c:-O(1)


bat ye hai ki ager 2 dist pe nhi ld rhi to isse jyada dist pe bhi nhi ldegi aor ager 2 pe ld rhi hai so isse jyada dist pe bhi ldegi that is what the approach

that if not possible at any dist then move the dist to lower side alright


