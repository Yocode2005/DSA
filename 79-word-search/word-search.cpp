class Solution {
public:
int row,col,n;
    bool dfs(int i, int j, vector<vector<char>> & board, string & word,int idx){
        if(idx == n){
            return true;
        }
        if(i<0 || i>= row|| j<0 || j >= col || board[i][j] != word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(i+1,j,board,word,idx+1) ||
                    dfs(i-1,j,board,word,idx+1) ||
                    dfs(i,j+1,board,word,idx+1) ||
                    dfs(i,j-1,board,word,idx+1);
                    board[i][j] = temp;
                    return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = word.length();
         row = board.size();
         col = board[0].size();
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};