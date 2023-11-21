 void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
            col0=0;
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=1;j--)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
            }
            if(col0==0)
            matrix[i][0]=0;
        }
    }

//TC:O(N*M) SC:O(1)[We are using only 1 element col0]
//Problem: https://leetcode.com/problems/set-matrix-zeroes/description/
