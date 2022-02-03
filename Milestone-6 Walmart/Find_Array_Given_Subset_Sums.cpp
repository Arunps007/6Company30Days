class Solution {
    bool sorted = false;
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        if(n==0){
            return {};
        }
        if(!sorted){
            sort(sums.begin(), sums.end());
            sorted = true;
        }
        int sz = (1<<n);
        int d = sums[sz-1]-sums[sz-2];
        unordered_map<int,int> m;
        for(int i:sums){
            m[i]++;
        }
        bool zero = false;
        vector<int> sums1, sums2;
        for(int i:sums){
            if(m[i]>0 && m[i+d]>0){
                m[i]--;
                m[i+d]--;
                if(i==0){
                    zero=true;
                }
                sums1.push_back(i);
                sums2.push_back(i+d);
            }
        }
        vector<int> ans;
        if(zero){
            ans = recoverArray(n-1, sums1);
            ans.push_back(d);
        } else {
            ans = recoverArray(n-1, sums2);
            ans.push_back(-d);
            
        }
        return ans;
    }
};
