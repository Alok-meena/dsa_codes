You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.




CONCEPT yhi hai ki ager hmne ith day pe sell kiya to i-1 pe buy kiya hoga to maxprofit and mini rkh liye and jst update both 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int maxprofit = 0;
        int minprice = prices[0];
        
        for (int i = 1; i < n; i++) {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice=min(minprice,prices[i]);
        }
        
        return maxprofit;
    }
};

t.c:-O(n) and s.c:-O(1)
