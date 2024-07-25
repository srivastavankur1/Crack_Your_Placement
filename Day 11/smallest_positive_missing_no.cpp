class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Step 1: Place each number in its correct index.
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 2: Find the smallest missing positive number.
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers from 1 to N are present, return N + 1.
        return n + 1;
    } 
};
