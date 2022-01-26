// Array Pair Sum Divisibility Problem 
// Name: Pinaki Das
// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n&1) return false;
        
        unordered_map<int, int>m;
        for(auto it: nums)
            m[(it%k + k)%k]++; 
        for(auto it:nums)
        {
            int rem=(it%k + k)%k;
            if(!rem) {                       
                if(m[rem] & 1) return false;
            }
            else if(m[rem] != m[k - rem]) return false;   
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}