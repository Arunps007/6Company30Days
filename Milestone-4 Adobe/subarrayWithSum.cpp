class Solution{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l = 0, r = 0;
        long long sum = 0;
        while(r < n) {
            // cout << l << " " << r << " " << sum << endl;
            if(sum < s) {
                sum += arr[r];
                r++;
            }
            else if(sum > s) {
                sum -= arr[l];
                l++;
            }
            else {
                return {l+1, r};
            }
        }
        while(sum > s) {
            sum -= arr[l];
            l++;
        }
        if(sum == s)
            return {l+1, n};
        else 
            return {-1};
    }
};