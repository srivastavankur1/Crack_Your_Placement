vector<int> search(string pattern, string text) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    vector<int> result;
    
    // Step 1: Preprocess the pattern to create LPS array
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    // Step 2: Search pattern in the text using the LPS array
    i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j + 1);  // Pattern found at index (i - j + 1) (1-based index)
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}