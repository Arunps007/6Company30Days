// Total Decoding Messages
// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#
//Name: Pinaki Das
// https://leetcode.com/problems/decode-ways/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int CountWays(string str){
		    int mod =1e9+7;
		    int n = str.length();
		    if (str[0] == '0') return 0;
		    if(n==0 || n==1) return 1;
		    
		    int dp[n+1] ={0};
		    dp[0]=dp[1]=1; //base
		    for(int i=2; i<=n; i++){
		        if(str[i-1]!='0')
		            dp[i]+=dp[i-1]%mod;
		      if(str[i-2]!='0')
		      if(((str[i-2]-'0')*10 + (str[i-1]-'0'))<=26)
		        dp[i]+=dp[i-2]%mod;
		    }
		    return dp[n]%mod;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}