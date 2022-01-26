// Number following a pattern 
//Name: Pinaki Das
// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length(), x=0;
        string str;
        for(int i=0; i<n; i++){
            if(S[i]=='I')
                str+=to_string(++x);
            else {
                int count=0;
                while(i<n &&S[i]=='D'){
                    i++;
                    count++;
                }
                count++;
                for(int j=count+x; j>x; j--)
                    str+=to_string(j);
                x+=count;
            }
        }
        if(S[n-1]=='I') str+=to_string(++x);
        return str;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 