#Approach 1...
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
	 // to suno bahut simple hai for example for elements -8,-2,3,-6,10 and k=2 pahli window ke liye loop chla diya aor sare negative elements ke index ko queue me 
	 // dal diya  then q=0,1 and then ans dal diya obviously front hi hoga to dal do nhi mila koi bhi to 0 but tbhi dalna jab q ki size >0 hogi 
	 // tik then agla loop  hmne k se chlaya to suno jese yha pe -8 -2 the to dono ka index q me hoga to dono ko q me dal diya isliye i=k se start kiya loop ko
	 // then niche dekho
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             // ab i=k se start kiya to pahle ye dekho ki d ki ander jo front element hai mtlb negative vo window me exist krta hai ya nhi to pahli bat to q ki
	     // size >0 honi chahihe aor then condition lgayi i-q.front()>=k hona chahihe mtlb i kya hai current element ka index to i-q.front() q jisme index h
	     // ager vo >=k hai to vo out of window hai because jese yha pe jb i=k hai to hm element 3 pe hai aor q.front() me 0 to 2-0>=k
	     //to 0 vala out of loop ho gya because ye <k hona chaihe to be in the window yhi condition imp hai then simple ager current element negative h
	     // to q me dal do aor fir se q ki size>0 to ans me dal do nhi h to 0 dal to if not found ;
             if(!dq.empty() && (i - dq.front())>=K ) {
                 dq.pop_front(); // DHYAN SE front element ko pop krnege na ki pop_back ookkkk
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) { // queue ki size check karna na ki q.empty() karna...
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }

#Approach 2....

( easy one )
#include <queue>
vector<int> firstNegative(vector<int> arr, int n, int k)
{
    // Write your code here.
    deque<int> d;
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            d.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (d.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(d.front());
                if (arr[i] == d.front())
                {
                    d.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
