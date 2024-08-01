    int celebrity(vector<vector<int>>& M, int n) {
        int candidate = 0;

        // Find the potential celebrity.
        for (int i = 1; i < n; i++) {
            if (M[candidate][i] == 1) {
                // Candidate knows i, hence candidate cannot be a celebrity.
                candidate = i;
            }
        }

        // Verify the potential celebrity.
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1; // No celebrity found
                }
            }
        }
        
        return candidate; // Celebrity found
    }