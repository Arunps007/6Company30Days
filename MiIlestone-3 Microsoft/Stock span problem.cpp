vector <int> calculateSpan(int A[], int n)
    {
       // Your code here
       stack<int>S;
       vector<int>ans;
       
       for(int i=0;i<n;i++){
            if(!S.empty() && A[i]<A[S.top()]){
                ans.push_back(i-S.top());
            }
            else{
                while(!S.empty() && A[S.top()]<=A[i]){
                    S.pop();
                }
                if(!S.empty()){
                    ans.push_back(i-S.top());
                }else{
                    ans.push_back(i+1);
                }
            }
            S.push(i);
       }
       
       
       return ans;
    }