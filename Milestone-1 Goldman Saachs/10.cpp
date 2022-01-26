// Find max 10 numbers in a list having 10M entries.
// Name: Pinaki Das
// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        int i;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(i=0;i<k;i++)
            pq.push(arr[i]);
        for(;i<n;i++)
        {
            if(arr[i]>pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int>v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.begin(),v.end(),greater<int>());
        return v;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

/*	For 10 in 10M entries

    priority_queue <int, vector <int>, greater <int>> pq;
    
    int i, x;
    for (i=0; i < 10; i ++) {
        cin >> x;
        pq.push(x);
    }

    for (; i < 10000000; i ++) {
        cin >> x;
        if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
*/