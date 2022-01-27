bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> g[N];
	    for(auto i: prerequisites)
	        g[i.first].push_back(i.second);
	    vector<int> inDeg(N, 0);
	    for(int i=0; i<N; ++i)
	    {
	        for(auto it: g[i])
	            inDeg[it]++;
	    }
	    queue<int> q;
	    for(int i=0; i<N; ++i)
	    {
	        if(inDeg[i]==0)
	            q.push(i);
	    }
	    int c=0;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        c++;
	        q.pop();
	        for(auto it: g[temp])
	        {
	            inDeg[it]--;
	            if(inDeg[it]==0)
	                q.push(it);
	        }
	    }
	    if(c==N)
	        return true;
	    return false;
	}