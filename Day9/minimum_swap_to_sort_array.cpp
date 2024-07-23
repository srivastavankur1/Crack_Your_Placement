class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        
        // Pair each element with its index
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        
        // Sort the array by the elements' values
        sort(arr.begin(), arr.end());
        
        // Track visited elements
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; i++) {
            // If the element is already visited or in the correct position, skip it
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Find the cycle of this element
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                // Move to the index where the current element should go
                j = arr[j].second;
                cycle_size++;
            }
            
            // If there is a cycle of size > 1, then (cycle_size - 1) swaps are needed to sort the cycle
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
	}
};