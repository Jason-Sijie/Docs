#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(i = n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                int min = i-1;
                for(int j = i; j<n; j++){
                    if(j == i)
                        min = j;
                    if(nums[j] > nums[i-1] && nums[j] < nums[min])
                        min = j;
                }
                int temp = nums[i-1];
                nums[i-1] = nums[min];
                nums[min] = temp;
                sort(nums.begin()+i, nums.end());
                break;
            }
        }
        if(i == 0){
            sort(nums.begin(), nums.end());
        }
    }
};

int main()
{
    Solution S;
    vector<int> nums = {3, 2, 1};
    S.nextPermutation(nums);
    for(int ele : nums)
        cout << ele << endl;
}