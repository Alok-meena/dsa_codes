Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

Example 1:

Input:
S = "0100110101"
Output: 4
Explanation: 
The required substrings are 01, 0011, 01 and 01.

Example 2:

Input:
S = "0111100010"
Output: 3










int maxSubStr(string str){
        //Write your code here
        int count0=0,count1=0,count=0;
        
        for(auto i:str){
            if(i=='0') count0++;
            else count1++;
            
            if(count0==count1){//jaise hi equal mile to reset count of 0 and 1 to 0
                count++;
                count0=0;
                count1=0;
            }
        }
        
        if(count0!=0 && count1!=0){//if some 0 and 1 remain not equal it means that splitting is not possible then return -1
            return -1;
        }
        
        return count;
}

t.c:-O(N) and s.c:O(1)
