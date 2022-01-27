int solve(Node * root,int x, int & val){
    if(root==NULL)return 0;
    int a=solve(root->left,x,val) + solve(root->right,x,val) + root->data;
    if(a==x)val++;
    
    
    return a;
    
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int val=0;
	int a= solve(root,X,val);
	return val;
}