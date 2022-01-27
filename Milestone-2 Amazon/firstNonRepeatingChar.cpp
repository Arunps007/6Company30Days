class Solutin {
public:	
    string FirstNonRepeating(string a){
        vector<int> ind(26, -1);
        string res;
        int n = a.length();
        for(int i = 0; i < n; i++) {
            if(ind[a[i]-'a'] >= 0)
                ind[a[i]-'a'] = -2;     
            else if(ind[a[i]-'a'] == -1)
                ind[a[i]-'a'] = i;           		      
            int minInd = n, minIndChar = '#';
            for(int j = 0; j < 26; j++) {
                if(ind[j] >= 0 && ind[j] < minInd) {
                    minInd = ind[j];
                    minIndChar = 'a' + j;
                }
            }
            res += minIndChar;
        }
        return res;
    }
};