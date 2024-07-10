class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
//Solution 2 :

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> store(26, 0);
            string curr = strs[i];
            for (int j = 0; j < curr.length(); j++) {
                store[curr[j] - 'a']++;
            }
            string temp = "";
            for (int k = 0; k < 26; k++) {
                while (store[k] != 0) {
                    temp.push_back('a' + k);
                    store[k]--;
                }
            }
            mp[temp].push_back(curr);
        }
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
