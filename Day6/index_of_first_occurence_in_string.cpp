class Solution {
public:
    int strStr(string haystack, string needle) {
        int m= haystack.size();
        int n = needle.size();

        if(m==0){
            return 0;
        }
        if(m<n){
            return -1;
        }
        for (int i = 0; i < m - n + 1; i++)
        if (haystack.substr(i, n) == needle)
            return i;

        return -1;
    }
};