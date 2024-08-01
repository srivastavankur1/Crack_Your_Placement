class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> prevSmaller(n), nextSmaller(n), result(n + 1, 0);
        stack<int> s;
        
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
                // Clear the stack to reuse for the next smaller elements
        while (!s.empty()) s.pop();
                // Finding next smaller elements
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
                // Calculate the maximum of minimums for each window size
        for (int i = 0; i < n; ++i) {
            int len = nextSmaller[i] - prevSmaller[i] - 1;
            result[len] = max(result[len], arr[i]);
        }
                // Fill the gaps to ensure each position has the maximum possible value
        for (int i = n - 1; i >= 1; --i) {
            result[i] = max(result[i], result[i + 1]);
        }
        
        // Result vector from 1 to n (1-based index)
        vector<int> ans(result.begin() + 1, result.end());
        return ans;
    }