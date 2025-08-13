





brute force: -

i tried this but not optimized in brute also

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=0;
        int m=0;
        for(int i=1;i<=10000;i++){
            if(arr[m]!=i){
                j++;
                if(j==k) return i;
            }
            else{
                m++;
                if(m==arr.size()) m=0;
            }
        }

        return -1;
    }
};

this is the actual brute force
