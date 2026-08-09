class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        double mini = 0;
        int i = prices.size()-1;
        int j = discounts.size()-1;
        while(i>=0 && j>=0){
            double temp = prices[i];
            temp*=(100-discounts[j]);
            temp = temp/100;
            mini+=temp;
            i--;
            j--;
        }
        while(i>=0){
            mini+=prices[i];
            i--;
        }
        return mini;
    }
};