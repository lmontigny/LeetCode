// 118. Pascal's Triangle
/*
Matrix 
1
11
121
1331

i=row number
j=column number

Algorithm:
Create vector
Add one on the left
v_i(j)=v_i-1(j)+v_i-1(j-1)
Add one on the right
Add this vector to the 2D matrix

*/




class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        
        if(numRows != 0){
            vector<int> tmp{1};
            matrix.push_back(tmp);
        }
        
        for(int i=1; i<numRows; i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1; j<i; j++){
                v.push_back(matrix[i-1][j] + matrix[i-1][j-1]);
            }
            v.push_back(1);
            matrix.push_back(v);
        }
        
        return matrix;
    }
};
