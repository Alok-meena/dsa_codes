Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

Example 1:

Input:
A = "abd"
B = "bad"
Output: 1
Explanation: The conversion can take place in
1 operation: Pick 'b' and place it at the front.
Example 2:

Input:
A = "GeeksForGeeks"
B = "ForGeeksGeeks"
Output: 3
Explanation: The conversion can take
place in 3 operations:
Pick 'r' and place it at the front.
A = "rGeeksFoGeeks"
Pick 'o' and place it at the front.
A = "orGeeksFGeeks"
Pick 'F' and place it at the front.
A = "ForGeeksGeeks"



nothing just compare from the last okk if equal -- o/w just do i-- and match count++ okk and at starting check if have equal feq of the char then only 
go further o/w return -1



class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.length()!=B.length()) return -1;
        
        map<char,int>m;
        
        for(int i=0;i<A.length();i++){
            m[A[i]]++;
        }
        
        for(int i=0;i<A.length();i++){
            m[B[i]]--;
        }
        
        for(auto i:m){
            if(i.second!=0) return -1;
        }
        
        int i=A.length()-1;
        int j=B.length()-1;
        int count=0;
        
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--;j--;
            }
            else{
                i--;
                count++;
            }
        }
        
        return count;
    }
};

Time Complexity: O(N), As we iterate through the both the string and then we use two pointer approach in which we iterate through the both the string once in the worst case, so the total time complexity becomes O(N).
Space Complexity: O(1), As we use the map to store the frequency of the characters and we have only 26 characters.
