class Solution{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        list<int> window;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            while(!window.empty() && arr[window.back()] <= arr[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if(window.front() == i-k)
                window.pop_front();
            if(i >= k-1)
                res.push_back(arr[window.front()]);
        }
        return res;
    }
};