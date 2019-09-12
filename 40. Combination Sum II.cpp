class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> elements;
        helper(candidates, target, res, elements, 0);
        return res;
    }
private:
    void helper(vector<int>& candidates, int target,
                vector<vector<int>>& res, vector<int>& elements, int begin){
        if(!target){
            res.push_back(elements);
            return;
        }
        
        for(int i=begin; i<candidates.size() && candidates[i]<=target; i++){
            // example: [1 1 2]
            // example: [1 2 2 3]
            // keep possible to have 1,1,... with the recursion = OK
            // only if the iterator of the loop is after the starting point
            if(i>begin && candidates[i]==candidates[i-1]) continue; //not i++
            elements.push_back(candidates[i]);
            helper(candidates, target-candidates[i], res, elements, i+1);
            elements.pop_back();
        }
    }
};
