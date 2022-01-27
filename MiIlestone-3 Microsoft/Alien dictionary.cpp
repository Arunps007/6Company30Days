class Solution{
    public:
    void recur(string dict[],int start,int end,vector<int> adj[],int level){
        int i=start;
        while(i<=end && level>=dict[i].size())
        i++;
        start=i;
        if(start>=end)
        return ;
        char prev=dict[start][level];
        int pr=start;
        for(i=start;i<=end;i++){
            char curr=dict[i][level];
            if(curr!=prev){
                adj[prev-'a'].push_back((curr-'a'));
                prev=curr;
                recur(dict,pr,i-1,adj,level+1);
                pr=i;
            }
        }
        recur(dict,pr,end,adj,level+1);
        
    }
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        recur(dict,0,n-1,adj,0);
        int in[k]={0};
        for(int i=0;i<k;i++)
        for(int j=0;j<adj[i].size();j++)
         in[adj[i][j]]++;
        string ret;
        queue<int> q;
        for(int i=0;i<k;i++)
        if(in[i]==0)
        q.push(i);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ret.push_back(('a'+v));
            for(int i=0;i<adj[v].size();i++){
                in[adj[v][i]]--;
                if(in[adj[v][i]]==0)
                q.push(adj[v][i]);
            }
            
        }
        return ret;
    }
};