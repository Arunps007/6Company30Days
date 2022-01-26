// Find the position of M-th item 
//Name: Pinaki Das
// https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        K+=M-1;
        return K%N ? K%N : N;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}