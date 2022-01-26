//Given an array of strings, return all groups of strings that are anagrams.
//Name: Pinaki Das
//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#


#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>map;
        for(auto it: string_list){
            string temp = it;
            sort(temp.begin(),temp.end());
            map[temp].push_back(it);
        }
        
        for(auto it: map)
            ans.push_back(it.second);
            
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}