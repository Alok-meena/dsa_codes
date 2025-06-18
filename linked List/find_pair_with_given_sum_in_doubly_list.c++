Find pairs with given sum in doubly linked list
Difficulty: EasyAccuracy: 66.01%Submissions: 61K+Points: 2
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)






approach 1:

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ans;
        
        vector<int>v;
        Node *t=head;
        while(t!=NULL){
            v.push_back(t->data);
            t=t->next;
        }
        
        for(int i=0;i<v.size();i++){
            int val=target-v[i];
            auto it=find(v.begin()+i+1,v.end(),val);
            if(it!=v.end()){
                ans.push_back({v[i],val});
            }
        }
        
        return ans;
        
    }
};

t.c:-O(n^2) and s.c:-O(n) as find option has O(n) t.c


optimized

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>>ans;
        
        vector<int>v;
        Node *temp=head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        int n=v.size();
        for(int i=0;i<n-1;i++){
            int value=target-v[i];
            
            int l=i+1;
            int h=n-1;
            
            while(l<=h){
                int mid=(l+h)/2;
                if(v[mid]==value){
                    ans.push_back({v[i],v[mid]});
                    break;
                }
                else if(v[mid]>value){
                    h=mid-1;
                }
                else l=mid+1;
            }
        }
        
        return ans;
    }
};

t.c:-O(nlogn) and s.c:-O(n)

more optimized

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ans;
        
        unordered_set<int>st;
        
        Node *curr=head;
        while(curr!=NULL){
            int val=target-curr->data;
            
            if(st.find(val)!=st.end()){
                ans.push_back({val,curr->data});
            }
            
            st.insert(curr->data);
            curr=curr->next;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

t.c:-O(n) and s.c:O(n)


more optimized is binary search as it is applicable to it as it is doubly list



class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ans;
        
        Node *ptr1=head;
        Node *ptr2=head;
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }
        
        while(ptr1!=ptr2 && ptr2->next!=ptr1){
            int sum=ptr1->data + ptr2->data; 
            
            if(sum==target){
                ans.push_back({ptr1->data,ptr2->data});
                ptr2=ptr2->prev;
                ptr1=ptr1->next;
            }
            else if(target>sum){
                ptr1=ptr1->next;
            }
            else{
                ptr2=ptr2->prev;
            }
        }
        
        return ans;
        
    }
};

t.c:-O(n) and s.c:-O(1)
  
