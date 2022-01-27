   int subsetsum(int arr[] , int n , int range)
    {
        bool dp[n+1][range+1];
        
        //initialisation
        int i,j,k;
        for(i=0;i<=range;i++)
        {
            dp[0][i] = false;
        }
        for(i=0;i<=n;i++)
        {
            dp[i][0] = true;
        }
        
        //fill the table
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=range;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int> vec;
        for(i=0;i<=range/2;i++)
        {
            // cout<<dp[n][i]<<" ";
            if(dp[n][i] == true)
            {
                vec.push_back(i);
            }
        }
        // cout<<endl;
        int mn = INT_MAX;
        for(i=0;i<vec.size();i++)
        {
            mn = min(mn,range-(2*vec[i]));
        }
        return mn;
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    int i ,j, k;
	    for(int i = 0; i < n ; i++)
	    {
	        sum += arr[i];
	    }
	    int answer = subsetsum(arr,n,sum);
	    return answer;
	} 