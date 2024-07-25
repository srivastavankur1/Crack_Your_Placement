class Solution {
public:

    int countsnums(vector<int> &arr, int pages){
        int students=1;
        long long pagesStudents=0;
        for(int i=0;i<arr.size();i++){
            if(pagesStudents + arr[i]<= pages){
                pagesStudents += arr[i];
            }
            else{
                students +=1;
                pagesStudents = arr[i];
            }
        }
        return students;
    }

    int findnums(vector<int>& arr, int n, int m) {
        if(m>n) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int students = countsnums(arr,mid);
            if(students>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }


    int splitArray(vector<int>& a, int k) {
        return findnums(a,a.size(),k);
    }
};