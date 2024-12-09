5 5
4 1 2 3 1
Sample Output 1 :
YES
Explanation Of Sample Input 1:
Sam can buy 4 pages book and 1-page book.
Sample Input 2:
2 1
1 2


  string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int count=0;
        for(int i=0;i<book.size();i++){
            int sum=0;
            for(int j=i+1;j<book.size();j++){
                sum+=book[j]+book[i];
                if(sum==target){
                    count=1;
                    break;
                }
                else{
                    sum=0;
                }
            }
            if(count==1){
                break;
            }
            
        }
        if(count==0){
            return "NO";
        }
        return "YES";

}
means if anyone of the pair exists then return yes t.c:-O(n^2)



  using hashing

#include <map>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int count=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int value=book[i];
            int more=target-value;
            if(mp.find(more)!=mp.end()){
                return "YES";//if we have to return the index then return {map[more],i} or in reverse order
            }
            mp[value]=i;
        }
        return "NO";

}
t.c:-O(nlogn) and s.c:-O(n)


  
O(n) for unordered_map and can goupto O(n^2) in case of searching in unordered_map




WHAT IF WE DONT ALLOW TO USE THE MAP THEN DO IT USING TWO POINTER APPROACH


#include <map>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    //firstly sort the array
    sort(book.begin(),book.end());
    int left=0;
    int right=n-1;
    while(left<right){
        if(book[left]+book[right]<target){
            left++;//as we want more so we dont have to decrease the max value
        }
        else if(book[left]+book[right]>target){
            right--;
        }
        else{
            return "YES";
        }
    }
    return "NO";

}

t.c:-O(n)+O(nlogn) for sorting and s.c is constant

but for indices use the map approach only



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mp;
        int k=-1;
        int j=-1;

        for(int i=0;i<n;i++){
            int val=target-nums[i];
            if(mp.find(val)!=mp.end()){
                k=mp[val];
                j=i;
                break;
            }
            mp[nums[i]]=i;
        }
        return {k,j};
    }
};
