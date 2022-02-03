class Solution {
public:
    bool winnerOfGame(string colors) {
        int c1 = 0, c2 = 0;
        bool extra = false;
        for(int i=1;colors[i]!='\0';i++){
            if(colors[i]==colors[i-1]){
                if(!extra){
                    extra = true;
                } else {
                    if(colors[i]=='A') c1++;
                    else c2++;
                }
            } else {
                extra = false;
            }
        }
        return c1>c2;
    }
};
