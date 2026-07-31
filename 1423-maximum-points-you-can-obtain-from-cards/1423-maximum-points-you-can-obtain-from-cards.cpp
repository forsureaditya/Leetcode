class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int msum = INT_MIN;
        int sum = 0;
        for(int l=n-k;l<n;l++) sum+=cardPoints[l];
        msum = max(msum,sum);
        for(int i=n-k+1;i<n;i++){
            int j = (i+k-1)%n;
                sum+=cardPoints[j];
                sum-=cardPoints[i-1];
                msum = max(msum,sum);
        }
         sum = 0;
         for(int l = 0;l<k;l++) sum+=cardPoints[l];
         msum = max(msum,sum);
        return msum;
    }
};