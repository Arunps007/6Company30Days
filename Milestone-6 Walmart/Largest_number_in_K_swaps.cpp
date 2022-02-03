// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    string backtrack(string& s, int k, int i) {
		if (k == 0 || s[i] == '\0') {
			return s;
		}
		string ans = s;
		for (int j = i + 1; s[j] != '\0'; j++) {
			if (s[j] > s[i]) {
				swap(s[i], s[j]);
				string newstr = backtrack(s, k - 1, i + 1);
				if (newstr > ans) {
					ans = newstr;
				}
				swap(s[i], s[j]);
			}
		}
		if (ans[i] == s[i]) {
			return backtrack(s, k, i + 1);
		}
		return ans;
	}
public:
	//Function to find the largest number after k swaps.
	string findMaximumNum(string str, int k)
	{
		return backtrack(str, k, 0);
	}
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
