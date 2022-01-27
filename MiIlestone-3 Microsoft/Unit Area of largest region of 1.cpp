int n;
    int m;
    
    void bfs(int i,int j,int & count,vector<vector<int>>&A){
    
        if(i<0 || j<0 || i>=n || j>=m || A[i][j]==0){
            return ;
        }
        A[i][j]=0;
        count++;
        bfs(i+1,j,count,A);
        bfs(i,j+1,count,A);
        bfs(i-1,j,count,A);
        bfs(i,j-1,count,A);
        bfs(i+1,j+1,count,A);
        bfs(i+1,j-1,count,A);
        bfs(i-1,j+1,count,A);
        bfs(i-1,j-1,count,A);
    }

    int findMaxArea(vector<vector<int>>& A) {
        // Code here
        n=A.size();
        m=A[0].size();
        vector<int>X;
        
        int count;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(A[i][j]==1){
	                count=0;
	                bfs(i,j,count,A);
	                X.push_back(count);
	            }
	        }
	    }
	    sort(X.begin(),X.end(),greater<int>());
	    
	   return X[0];
    }