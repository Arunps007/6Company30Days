// Squares in N*N Chessboard
// Name: Pinaki Das
// https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        return N*(N+1)*(2*N+1)/6;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}