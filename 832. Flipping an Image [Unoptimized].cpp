class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for(int i=0; i<A.size(); i++){
            vector<int> tmp;
            for(int j=A[i].size()-1; j>=0; j--){
                if(A[i][j]==1)
                    A[i][j]=0;
                else
                    A[i][j]=1;
                
                tmp.push_back(A[i][j]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
