class Solution {
  public:
    const int INF = 1e9 + 5;
    int lis(vector<int> a) {
        int n = a.size();
        vector<int> len;
        for(int i = 0; i < n; i++) {
            auto lb = lower_bound(len.begin(), len.end(), a[i]);
            if(lb != len.end()) {
                *lb = min(*lb, a[i]);
            }
            else {
                len.push_back(a[i]);
            }
        }
        return len.size();
    }
    int minInsAndDel(int a[], int b[], int n, int m) {
        unordered_set<int> b_set;
        for(int i = 0; i < m; i++) 
            b_set.insert(b[i]);
        vector<int> a_updated;
        int steps = 0;
        for(int i = 0; i < n; i++) {
            if(b_set.find(a[i]) != b_set.end()) {
                a_updated.push_back(a[i]);
            }
            else {
                steps++;
            }
        }
        int lis_size = lis(a_updated);
        return steps + (a_updated.size() - lis_size) + (m-lis_size);
    }
};