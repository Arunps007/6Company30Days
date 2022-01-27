// Find Missing And Repeating 
// Name: Arun Pratap Singh
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        static int ans[2];
        for (int i = 0; i < n; i++) 
            if (arr[abs(arr[i]) - 1] > 0)
             arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else ans[0]=abs(arr[i]);
        for (int i = 0; i <n; i++) 
        if (arr[i] > 0)
            ans[1]=(i + 1);
            
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}