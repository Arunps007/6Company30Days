vector<vector<int> > fourSum(vector<int> &arr, int K) {
     
     sort(arr.begin(), arr.end());
     vector<vector<int>>ans;
     map<vector<int> , int> mp;
     int n= arr.size();
     for(int i=0;i<n-3;i++)
     {
         for(int j=i+1;j<n-2;j++)
         {
             int k = j+1, l= n-1;
             while(k<l)
             {
                 int sum = arr[i]+arr[j]+arr[k]+arr[l];
                 if(sum==K)
                 {
                    if( mp[{arr[i],arr[j],arr[k],arr[l]}]!=1)
                    {
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                        mp[{arr[i],arr[j],arr[k],arr[l]}]=1;
                    }
                    
                 }
                 
                 if(sum>K)
                 l--;
                 else
                 k++;
             }
         }
     }
     return ans;
     
    }