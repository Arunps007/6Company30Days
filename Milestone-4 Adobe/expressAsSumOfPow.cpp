class Solution{
public:
    
    # define ll long long int
    
    ll numOfWays(int s, int x)
    {
        vector<int> a;
        for(int i = 1; i <= s; i++) {
            if(pow(i,x) > s) {
                break;
            }
            a.push_back(pow(i, x));
        }
        int n = a.size();
        vector<ll> prev(s+1);
        prev[0] = 1;
        for(int i = 1; i <= n; i++) {
            vector<ll> cur(s+1);
            for(int j = 0; j <= s; j++) {
                cur[j] = prev[j];
                if(j >= a[i-1])
                    cur[j] += prev[j-a[i-1]];
            }
            prev = cur;
        }
        return prev[s];
    }
};