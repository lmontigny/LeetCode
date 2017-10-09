// 383. Ransom Note
// 'abbcc'
// map [a,b,c]->[1,2,2]
// check if the value of the map[a,b,c]<0, return false (some letter are then missing)


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(int i=0; i<magazine.size(); i++){
            ++map[magazine[i]];
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(--map[ransomNote[i]]<0) return false;
        }
        return true;
        
    }
};
