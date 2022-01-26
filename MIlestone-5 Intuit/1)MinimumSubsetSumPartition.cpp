#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int t[100][10000];
    int solve(int arr[],int k,int n){
        if(n==0 or k==0){
            t[n][k]= 0;
            return t[n][k];
        }  
        if(t[n][k]!=-1){
            return t[n][k];
        }
        if(arr[n-1]<=k){
            
        t[n][k]= max(solve(arr,k,n-1),arr[n-1]+solve(arr,k-arr[n-1],n-1));}
        else{
            t[n][k]= solve(arr,k,n-1);
        }
        return t[n][k];
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here

	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int k=sum/2;
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<k+1;j++){
	            t[i][j]=-1;
	        }
	    }
	    int ans= solve(arr,sum/2,n);
	    return sum-2*ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends