Multiply two linked lists
Difficulty: EasyAccuracy: 46.33%Submissions: 87K+Points: 2
Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 10^9+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
Expected Time Complexity: O(max(n,m))
Expected Auxilliary Space: O(1)
where n is the size of L1 and m is the size of L2

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103




class solution {
  public:
   
        const int MOD = 1e9 + 7;

    long long number(vector<int>&a){
        
        long long v=0;
        for(int i=0;i<a.size();i++){
            long long val=pow(10,i);
            v+=(a[i]*val)%MOD;
        }
        return v;
    }
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        vector<int>a;
        vector<int>b;
        vector<int>c;
        
        Node *t1=first;
        Node *t2=second;
        
        while(t1!=NULL || t2!=NULL){
            
            if(t1!=NULL){
                a.push_back(t1->data);
                t1=t1->next;
            }
            if(t2!=NULL){
                b.push_back(t2->data);
                t2=t2->next;
            }
        }
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        long long A=number(a);
        long long B=number(b);
        return (A*B)%MOD;
    }
};

t.c:-O(n+m) and s.c:-O(n+m)


same t.c and s.c code

int mod=1e9+7;
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        string a;
        string b;
        
        Node *temp=first;
        while(temp!=NULL){
            a.push_back(temp->data+'0');
            temp=temp->next;
        }
        
        temp=second;
        while(temp!=NULL){
            b.push_back(temp->data+'0');
            temp=temp->next;
        }
        
        long long num1=stoll(a);
        long long num2=stoll(b);
        
        long long ans=(num1*num2)%mod;
        return ans;
    }
};
