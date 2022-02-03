class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<int> cnt(101, 0);
        for(string& s : nums){
            cnt[s.length()]++;
        }
        int i=100;
        while(k>cnt[i]){
            k -= cnt[i];
            i--;
        }
        priority_queue<string, vector<string>, greater<string>> pq;
        for(string& s : nums){
            if(s.length() == i){
                if(pq.size()<k){
                    pq.push(s);
                    continue;
                }
                if(pq.top()<s){
                    pq.pop();
                    pq.push(s);
                }
            }
        }
        return pq.top();
    }
};
