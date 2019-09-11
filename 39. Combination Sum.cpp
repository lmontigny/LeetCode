// backtracking
// help of the discussion

/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        
        for(int i=0; i<candidates.size(); i++){
            if(candidates[i]==target)
                res.push_back(vector<int> {candidates[i]});
            
            if((candidates[i]%target)==0 && candidates[i]!=target){
                int repeat=candidates[i]/target;
                res.push_back(vector<int> (candidates[i], repeat));
            }
        }
        
        return res;        
    }
};
*/

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        // !! target >= candidates[i] where target is the updated target not the orignal target !!
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            cout << "target " << target << " delta " << target-candidates[i] << " candidates[i] " << candidates[i] << " combination ";
            print(combination);
            cout << endl;
            
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
