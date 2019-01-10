#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, i = 0;
        int last_number = 0;
        while(i < nums.size()){
            if(i==0){
                last_number = nums[i++];
                count++;
            }
            else if(last_number == nums[i]){
                nums.erase(nums.begin()+i);
            }
            else{
                count++;
                last_number = nums[i++];
            }  
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1, 2, 2, 2, 4};
    Solution S;
    cout << S.removeDuplicates(nums) << endl;
    for(int element: nums)
        cout << element << endl;
}