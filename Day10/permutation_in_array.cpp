class Solution{
    Public:
    bool isPossible(long long a[], long long b[], int n, long long k){
        sort(a, a+n);

        //sort b in descending order
        sort(b,b+n, greater<long long>());

        for(int i=0; i<n;i++){
            if(a[i]+b[j]<k){
                return false;
            }
        }
        return true;
    }
};