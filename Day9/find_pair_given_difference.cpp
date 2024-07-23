class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_set<int> seen;
        
        for (int i = 0; i < n; ++i) {
            // Check if there exists an element in the set such that the absolute difference with arr[i] is x
            if (seen.count(arr[i] + x) || seen.count(arr[i] - x)) {
                return 1; // Pair found
            }
            // Add the current element to the set
            seen.insert(arr[i]);
        }
        
        return -1;
    }
};