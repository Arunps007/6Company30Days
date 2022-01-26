class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int arrSum = 0;
        for(int i = 0; i < n; i++)
            arrSum += arr[i];
        if(arrSum&1)
            return 0;
        arrSum /= 2;
        vector<int> prev(arrSum+1);
        prev[0] = 1;
        for(int i = 1; i <= n; i++) {
            vector<int> cur(arrSum+1);
            for(int j = 0; j <= arrSum; j++) {
                cur[j] = prev[j];
                if(j >= arr[i-1]) {
                    cur[j] |= prev[j-arr[i-1]];
                }
            }
            prev = cur;
        }
        return prev[arrSum];
    }
};