class Solution {
public:
    int solution(int idx, int buy, vector<int>& prices, vector<vector<int> >& dp ){
        int n = prices.size();
        int profit = 0;
        if(idx == n) return 0; //base case
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        if(buy){
            profit = max((-prices[idx]+solution(idx+1,0,prices,dp)), (0 + solution(idx+1,1,prices,dp)));
        }
        else{
            profit = max((prices[idx]+solution(idx+1,1,prices,dp)), (0+solution(idx+1,0,prices,dp)));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solution(0,1,prices,dp);
    }
};