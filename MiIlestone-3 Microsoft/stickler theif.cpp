int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++){
            dp[i]=0;
        }
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        
        return dp[n-1];
    }