
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. 
Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.

Examples :

Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20.
so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 







class Solution {
  public:
  
  static bool cmp(pair<double,Item>a,pair<double,Item>b){
      return a.first>b.first;//to sort in descending order
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,Item>>v;
        
        for(int i=0;i<n;i++){
            double perUnitValue=(1.0*arr[i].value)/arr[i].weight;
            pair<double,Item>p=make_pair(perUnitValue,arr[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        double totalValue=0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight>w){
                //toh main sirf fraction le skta hu
                totalValue+=w*v[i].first;
                w=0;
            }
            else{
                totalValue+=v[i].second.value;
                w=w-v[i].second.weight;
            }
        }
        return totalValue;
    }
};

O(n) and O(n)

or can use this


// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<double>>v;
        
        for(int i=0;i<val.size();i++){
            double value=(double)val[i]/(double)wt[i];
            
            v.push_back({value,val[i],wt[i]});
        }
        
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a[0]>b[0];
        });
        
        double value=0;
        
        for(int i=0;i<v.size();i++){
            if(v[i][2]<=capacity){
                value+=(v[i][1]);
                capacity-=v[i][2];
            }
            else if(v[i][2]>capacity){
                value+=(capacity*v[i][0]);
                break;
            }
        }
        
        return value;
    }
};

