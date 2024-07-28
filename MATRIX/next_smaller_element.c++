You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.




//brute force

#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                ans.push_back(arr[j]);
                break;
            }
            else if(j==n-1){
                ans.push_back(-1);
            }
        }
    }
    ans.push_back(-1);

    return ans;
}

n^2 complexity



2nd Using stack


#include <stack>
#include <algorithm>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    
    for(int i=n-1;i>=0;i--){
        while(st.top()>=arr[i]){
                st.pop();
            }
        ans.push_back(st.top());
        st.push(arr[i]);
    }

    reverse(ans.begin(),ans.end()); 
    return ans;
}

no need to reverse if you will do like this 

  #include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);

    }
    return ans;
}
t.c:-O(n) and O(n) space

can find prevsmaller element by starting it with 0 to n-1
