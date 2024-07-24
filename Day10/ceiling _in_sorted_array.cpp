#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int x){
    int n= arr.size();
    int low=0, high=n-1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;

}