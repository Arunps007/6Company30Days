//Run Length Encoding 
//Name: Pinaki Das
//https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
   string ans;
    int i=0;
    while(i<src.length()){
        int count = 1;
        while(src[i+1]==src[i] && i!= src.length()-1){
            count++;
            i++;
        }
        ans += src[i];
        ans += count+'0';
        i++;
    }
    return ans;
}