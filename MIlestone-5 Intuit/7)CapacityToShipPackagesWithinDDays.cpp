#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> arr , int m , int mid){
        int dayCount = 1 , wt = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(wt + arr[i] <= mid)
                wt += arr[i];
            else{
                dayCount++;
                if(dayCount>m || arr[i]>mid)
                    return false;
                wt = arr[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0 , sum = 0;
        for(int i = 0 ; i < weights.size() ; i++)
            sum += weights[i];
        int e = sum ; int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(weights , days , mid)){
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};