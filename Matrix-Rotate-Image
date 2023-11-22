   void rotate(vector<vector<int>>& matrix) {
               //Transpose
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            swap(matrix[i][j],matrix[j][i]);
        }

             //Reverse each Row
        for(int i=0;i<matrix.size();i++)
        reverse(matrix[i].begin(),matrix[i].end());
    }

//Rotate Image by 90 degree = transpose of the matix + reverse of matrix

//TC:O(N^2) SC:O(1)
//Problem: https://leetcode.com/problems/rotate-image/
