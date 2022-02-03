class Solution {
    const int mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        long long ans = 0, sum = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({e[i], s[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = n-1;
        for(;i>=n-k;i--){
            sum += v[i].second;
            ans = max(ans, sum*v[i].first);
            pq.push(v[i].second);
        }
        while(i>=0){
            if(pq.top()>=v[i].second){
                i--;
                continue;
            }
            sum -= pq.top() - v[i].second;
            pq.pop();
            pq.push(v[i].second);
            ans = max(ans, sum*v[i].first);
            i--;
        }
        return ans%mod;
    }
};
