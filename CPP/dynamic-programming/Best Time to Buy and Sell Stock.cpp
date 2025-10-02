class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp = 0;
        int mini = prices[0];
        for (int i = 0; i < n; i++) {
            int curProfit = prices[i] - mini;
            maxp = max(maxp, curProfit);
            mini = min(mini, prices[i]);
        }
        return maxp;
    }
};