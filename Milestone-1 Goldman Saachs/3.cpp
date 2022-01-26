//Count the subarrays having product less than k
//Name: Pinaki Das
//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod=1;
        int j=0, ans=0;
        for(int i=0; i<n; i++){
            prod *= a[i];
            while(prod>=k)
                prod /= a[j++];
            if(prod<k) ans += i + 1 - j;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}