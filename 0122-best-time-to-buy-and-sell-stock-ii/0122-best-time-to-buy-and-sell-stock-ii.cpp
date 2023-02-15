class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int m = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++)
        {
            if(prices[i] < prices[i-1])
            {
                m = prices[i];
                continue;
            }

                profit += prices[i] - m;
                m = prices[i];
        }

        return profit;
    }
};