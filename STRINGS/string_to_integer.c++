class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();

        while(i<n and s[i]==' ') i++;

        int sign=1;

        if(i<n and s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n and s[i]=='+'){
            i++;
        }

        long long sum=0;

        while(i<n){
            if(isdigit(s[i])){
                sum*=10;
                sum+=s[i]-'0';
                i++;

                if(sign>0 and sum>INT_MAX) return INT_MAX;
                if(sign<0 and -sum<INT_MIN) return INT_MIN;
            }
            else break;
        }

        sum*=sign;

        return sum;
    }
};
