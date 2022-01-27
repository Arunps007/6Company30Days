// Decode the string
// Name: Arun Pratap Singh
// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
// https://leetcode.com/problems/decode-string/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; 
                string t = decodeString(s, i);
                i++; 
                
                while (n--)
                    res += t;
            }
        }
        
        return res;
    }
    string decodedString(string s){
        int i = 0;
        return decodeString(s, i);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}