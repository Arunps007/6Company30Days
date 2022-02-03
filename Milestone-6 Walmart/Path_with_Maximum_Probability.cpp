class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& eds, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> edges(n);
        int i=0;
        for(const vector<int>& edge:eds){
            edges[edge[1]].push_back({edge[0], succProb[i]});
            edges[edge[0]].push_back({edge[1], succProb[i]});
            i++;
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        vector<double> probs(n, 0);
        vector<bool> vis(n, false);
        probs[start] = 1;
        while(!pq.empty()){
            auto [prob, next] = pq.top();
            pq.pop();
            if(vis[next]){
                continue;
            }
            vis[next] = true;
            for(auto [v, w]:edges[next]){
                if(probs[v]<prob*w){
                    probs[v] = prob*w;
                    pq.push({prob*w, v});
                }
            }
        }
        return probs[end];
    }
};
