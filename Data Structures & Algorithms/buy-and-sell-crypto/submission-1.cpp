class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //BRUTE FORCE SOLUTION
        int profit= 0;
        for(int i =0 ; i<prices.size() ;i++ ){
            for(int j=i+1;j<prices.size() ;j++){
                profit = std::max(profit,prices[j]-prices[i]);
            }
        }
        return profit;
    }
};
