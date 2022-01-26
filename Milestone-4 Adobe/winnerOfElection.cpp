class Solution {
public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string, int> freq;
        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
            
        int maxVotes = 0;
        vector<string> res;
        for(auto f: freq) {
            string name = f.first;
            int count = f.second;
            if(count > maxVotes) {
                maxVotes = count;
                res = {name, to_string(count)};
            }
        }
        return res;
    }
};