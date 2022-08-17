class Solution {
public:
    
    string getKey(string s){
        int frq[26] = {0};
        for(int i=0;i<s.size();i++){
            frq[s[i]-'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++){
            key += to_string(frq[i]+'a');
        }
        return key;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string key = getKey(strs[i]);
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};