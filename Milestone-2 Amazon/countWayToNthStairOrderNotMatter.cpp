class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        int maxTwoSteps = m/2;
        return maxTwoSteps + 1;
    }
};