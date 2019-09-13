class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> elements;
        helper(k, n, res, elements, 1);
        return res;
    }
private:
    void helper(int k, int target, vector<vector<int>>& res, vector<int>& elements, int begin){
        // Target reached
        if(!target && elements.size()==k){
            res.push_back(elements);
            return;
        }
        int limit=10;
        for(int i=begin; i<limit && i<=target; i++){
            //if(i>begin && candidates[i]==candidates[i-1]) continue; //not i++
            if(elements.size()>k) continue;
            elements.push_back(i);
            helper(k, target-i, res, elements, i+1);
            elements.pop_back();
        }
    }
};
