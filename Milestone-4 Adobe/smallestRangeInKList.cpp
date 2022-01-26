class Solution{
    public:
    # define pi pair<int, int>
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> pointer(k);
        int right = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({arr[i][0], i});
            right = max(right, arr[i][0]);
        }
        
        int minlen = INT_MAX; pi res = {0, INT_MIN};
        
        while(1) {
            auto p = pq.top(); pq.pop();
            int left = p.first, ind = p.second;
            if(right-left < minlen) {
                minlen = right - left;
                res = {left, right};
            }
            if(pointer[ind] == n-1)
                break;
            pointer[ind]++;
            pq.push({arr[ind][pointer[ind]], ind});
            right = max(right, arr[ind][pointer[ind]]);
        }
        return res;
    }
};