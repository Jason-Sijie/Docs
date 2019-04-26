#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows == 0){
            return res;
        }
        int cols = matrix[0].size();
        if(cols == 0){
            return res;
        }
        int gap = 0;
        
        while(rows-2*gap > 0 && cols-2*gap > 0){
            for(int i = gap; i<cols-gap; i++){
                res.push_back(matrix[gap][i]);
            }
            if(gap + 1 > rows - gap - 1){
                break;
            }
            for(int i = gap+1; i<rows-gap; i++){
                res.push_back(matrix[i][cols-1-gap]);
            }
            if(gap > cols-2-gap){
                break;
            }
            for(int i = cols-2-gap; i>=gap; i--){
                res.push_back(matrix[rows-1-gap][i]);
            }
            for(int i = rows-2-gap; i>=gap+1; i--){
                res.push_back(matrix[i][gap]);
            }
            gap++;
        }
        return res;
    }
};