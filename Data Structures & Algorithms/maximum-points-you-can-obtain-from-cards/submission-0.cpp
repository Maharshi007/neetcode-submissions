class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, rightIdx = cardPoints.size() - 1;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        int maxi = leftSum;
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIdx];
            rightIdx--;
            maxi = max(maxi, leftSum + rightSum);
        }
        return maxi;
    }
};