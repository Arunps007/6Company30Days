class Solution {
public:

bool check_k(vector &piles, int mn, int h)
{

    int curr_H=0;
    for(int i=0;i<piles.size();i++)
    {
        
        curr_H+=(piles[i]+mn-1)/mn;        
    }
    
    if(curr_H<=h)
    {
        return true;
    }
    return false;
}


int minEatingSpeed(vector<int>& piles, int h) {
   int sum=0;
    int maxB=INT_MAX;
  
    int low=1;   
    int high=1e9;   
    int res=high;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(check_k(piles,mid,h))
        {
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    
    
    }
    return res;
}
};