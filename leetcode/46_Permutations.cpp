#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        bool* find = new bool[n];
        for(int i = 0; i<n; i++)
            find[i] = false;

        recur(res, nums, tmp, find);
        return res;
    }

private:
    void recur (vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, bool* find){
        int n = nums.size();
        bool res_flag = true;
        for(int i = 0; i<n; i++){
            if(find[i] == false){
                res_flag = false;
                find[i] = true;
                tmp.push_back(nums[i]);
                recur(res, nums, tmp, find);
                tmp.pop_back();
                find[i] = false;
            }
        }
        if(res_flag == true){
            vector<int> r(tmp);
            res.push_back(r);
        }
    }

};

int main(void)
{
    Solution S;
    cout << "gcc success";
    return 0;
}