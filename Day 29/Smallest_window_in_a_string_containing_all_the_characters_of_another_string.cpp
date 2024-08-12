   string smallestWindow(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        if (n < m) return "-1";  // Edge case: if s is smaller than p
        
        vector<int> patFreq(26, 0); // Frequency of characters in P
        vector<int> winFreq(26, 0); // Frequency of characters in the current window in S
        
        // Count frequency of characters in P
        for (char c : p) {
            patFreq[c - 'a']++;
        }
        
        int start = 0, minLen = INT_MAX, startIndex = -1;
        int count = 0;  // Count of characters matching between window and P
        
        for (int end = 0; end < n; end++) {
            winFreq[s[end] - 'a']++;
            
            // If current character matches one in P
            if (patFreq[s[end] - 'a'] != 0 && winFreq[s[end] - 'a'] <= patFreq[s[end] - 'a']) {
                count++;
            }
            
            // When we have a valid window
            if (count == m) {
                // Try to minimize the window
                while (winFreq[s[start] - 'a'] > patFreq[s[start] - 'a'] || patFreq[s[start] - 'a'] == 0) {
                    if (winFreq[s[start] - 'a'] > patFreq[s[start] - 'a']) {
                        winFreq[s[start] - 'a']--;
                    }
                    start++;
                }
                
                int lenWindow = end - start + 1;
                if (minLen > lenWindow) {
                    minLen = lenWindow;
                    startIndex = start;
                }
            }
        }
        
        if (startIndex == -1) return "-1";
        
        return s.substr(startIndex, minLen);
    }