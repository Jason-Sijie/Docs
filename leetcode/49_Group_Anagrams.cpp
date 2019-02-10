#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<set<char>, vector<string>> M;
        vector<vector<string>> res;
        for(int i = 0; i<strs.size(); i++){
            string cur_str = strs[i];
            set<char> cur_set;
            for(int k = 0; k<cur_str.length(); k++){
                cur_set.insert(cur_str[k]);
            }
            if(M.find(cur_set) == M.end()){
                // new set
                vector<string> group;
                group.push_back(cur_str);
                M.insert(make_pair(cur_set, group));
            }
            else{
                auto ite = M.find(cur_set);
                ite->second.push_back(cur_str);
            }
        }

        for(auto ite = M.begin(); ite != M.end(); ite++){
            res.push_back(ite->second);
        }
        return res;
    }
};