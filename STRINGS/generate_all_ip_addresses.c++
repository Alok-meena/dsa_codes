Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:

Input:
S = 1111
Output: 1.1.1.1
Example 2:

Input:
S = 55
Output: -1







class Solution{
  public:
  
    bool check(string s){
        int n=s.length();
        
        if(n<=0 || n>3) return false;
        if(s[0]=='0' && n>1) return false; //for this case 1.1.1.05 no trailing 0's should be there
        int value=stoi(s);//string to integer (s to i ==> stoi)
        if(value>255) return false;
        
        return true;
    }
    
    string generate_string(int i,int j,int k,string s,int n){
        //generating substrings like here
        string s1=s.substr(0,i+1);//from 0 to i+1 length as outer loop is for first partition
        string s2=s.substr(i+1,j-i);//similarly for this but we want length from j-i 0kk after 1st partition
        string s3=s.substr(j+1,k-j);
        string s4=s.substr(k+1,n-k-1);//here -1 due to 0 based indexing
        
        if(check(s1) && check(s2) && check(s3) && check(s4)){
            return s1+"."+s2+"."+s3+"."+s4;
        }
        
        return "";//this is in o/w case
    }
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        
        int n=s.length();

       //we used three loops in order to do 3 partitions and after doing it we are generating the string by adding the dot's
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    string str=generate_string(i,j,k,s,n);
                    if(str.length()>0){
                        ans.push_back(str);
                    }
                }
            }
        }
        
        return ans;
    }

};


t.c:-O(n^3) and s.c:-O(n)
