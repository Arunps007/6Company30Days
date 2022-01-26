#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bs1(MountainArray &nums,int l ,int r,int target){
		while(l<=r){
			int mid=(l+r)/2;
			int val=nums.get(mid);
			if(val==target)
				return mid;
			else if(val>target)
				r=mid-1;
			else
				l=mid+1;
		}
		return -1;
	}
	int bs2(MountainArray &nums,int l,int r,int target){
		 while(l<=r){
			int mid=(l+r)/2;
			int val=nums.get(mid);
			if(val==target)
				return mid;
			else if(val>target)
				l=mid+1;
			else
				r=mid-1;
		}
		return -1;
	}
	int findInMountainArray(int target, MountainArray &nums) {
			int n=nums.length();
			int peak,l=0,r=n-1;
		//finding peak element
		  while(l<=r){
			  int m=(l+r)/2;
			  int left=INT_MIN,right=INT_MIN;
			  if((m-1)>=0)
			   left=nums.get(m-1);
			  int mid=nums.get(m);
			  if((m+1)<=n-1)
			  right=nums.get(m+1);
			  if(left<mid && mid>right)
			  {
				  peak=m;
				  break;
			  }
			  else if(left<mid && mid<right){
				  l=m+1;
			  }
			  else{
				  r=m-1;
			  }
		  }
		//end
		//index in left to peak
		   int idx1=bs1(nums,0,peak,target);
		//index in right to peak
		   int idx2=bs2(nums,peak+1,n-1,target);
		if(idx1!=-1 && idx2!=-1)
			return idx1;
		else if(idx1==-1)
			return idx2;
		return idx1;
	}
};
