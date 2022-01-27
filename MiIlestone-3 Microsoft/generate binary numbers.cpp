string conv(int n){
    
    string ans;
    
    while(n>0){
        int rem=n%2;
        
        if(rem==1){
            ans+="1";    
        }else{
            ans+="0";
        }
        n=n/2;    
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}


vector<string> generate(int N)
{
	// Your code here
	vector<string>ans;
	
	
	for(int i=1;i<=N;i++){
	    string temp=conv(i);
	    
	    ans.push_back(temp);    
	}
	return ans;
}