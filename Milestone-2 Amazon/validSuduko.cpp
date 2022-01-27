class Solution{
public:
    bool checkRectangle(vector<vector<int>> &board,
                               int x1, int y1, int x2, int y2) {
        vector<int> cnt(10);
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if(board[i][j]) {
                    if(cnt[board[i][j]]) 
                        return false;
                    cnt[board[i][j]] = 1;
                }
            }
        }
        return true;
    }
    
    int isValid(vector<vector<int>> mat){
        for(int i = 0; i < 9; i++) {
            if( !checkRectangle(mat, i, 0, i, 8)||
                !checkRectangle(mat, 0, i, 8, i)) {
                return false;
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int x1 = 3*i, y1 = 3*j, x2 = x1 + 2, y2 = y1+2;
                if(!checkRectangle(mat, x1, y1, x2, y2)) {
                    return false;
                }
            }
        }
        return true;
    }
};
