class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adjList[n];
        vector<int> ind(n, 0);
        vector<int> ts;
        
        for(auto pre : prerequisites){
            adjList[pre[1]].push_back(pre[0]);
            ind[pre[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i) if(ind[i] == 0) q.push(i);
        
        while(!q.empty()){
            int top = q.front(); q.pop(); n--;
            ts.push_back(top);
            for(auto x : adjList[top]){
                if(--ind[x] == 0) q.push(x);
            }
        }
        
        if(n == 0) return ts;
        return vector<int>();
    }
};