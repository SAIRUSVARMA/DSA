bool search(int i, int j, int n, int m, vector<vector<char>>& board, string &word, int k)
   {
       if(k==word.size())
         return true;
       if(i<0||j<0||i==n||j==m||board[i][j]!=word[k]) 
         return false;
        char c= board[i][j];
        board[i][j]='#';
        bool op1=search(i+1,j,n,m,board,word,k+1);
        bool op2=search(i,j+1,n,m,board,word,k+1);
        bool op3=search(i-1,j,n,m,board,word,k+1);
        bool op4=search(i,j-1,n,m,board,word,k+1);
        board[i][j]=c;
        return op1||op2||op3||op4;
   }



    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m= board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(search(i,j,n,m,board,word,0))
                    return true;
                }
            }
        }
        return false;
    }

//TC:O(N*M *4^k) SC:O(K)[ K is length of the word]
//TC: each node in tree has 4 node(4 possible directions)  Geometric Progression of (1+4+16+64+...K(terms)) is a* (r^k-1)/r-1= 1* (4^k-1)/3 ~=4^k
//SC: O(K) for the call stack, k is the depth of the tree or no of recursive calls until they reach the base case, all other variables just O(1)[ignored].
//Problem: 
