class Solution {
public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    map<char, int> cnt;
	    for(int i = 0; i < n; i++) {
	        cnt[nuts[i]]++;
	    }
	    int i = 0;
	    for(auto p: cnt) {
	        for(int j = 0; j < p.second; j++) {
	            nuts[i] = p.first;
	            bolts[i] = p.first;
	            i++;
	        }
	    }
	}

};