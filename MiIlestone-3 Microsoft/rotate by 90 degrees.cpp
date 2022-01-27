void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
     int n=A.size();
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(A[i][j],A[j][i]);
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(A[j][i],A[n-1-j][i]);
        }
    }
}