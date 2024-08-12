int solveWordWrap(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    vector<int> cost(n, 0);
    
    // Compute cost for all subarrays starting from the end
    for (int i = n - 1; i >= 0; --i) {
        int currLength = -1; // -1 because no space is needed before the first word
        dp[i] = INT_MAX;
        for (int j = i; j < n; ++j) {
            currLength += (nums[j] + 1); // Adding word length and a space
            
            if (currLength > k) break; // If this exceeds the line width, no point in checking further
            
            // If it's the last line
            if (j == n - 1) {
                cost[j] = 0;
            } else {
                cost[j] = (k - currLength) * (k - currLength);
            }
            
            if (j == n - 1) {
                dp[i] = 0;
            } else {
                dp[i] = min(dp[i], cost[j] + dp[j + 1]);
            }
        }
    }
    
    return dp[0];
}