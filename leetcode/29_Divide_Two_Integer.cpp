#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_neg = false;
        long res = dividend;
        if(res * divisor < 0){
            is_neg = true;
        }
        res = (res < 0)? -res : res;
        divisor = (divisor < 0)? -divisor: divisor;
        for(int i = 0; i<=32; i++){
            int tmp = res >> 32;
            if(tmp - divisor < 0){
                // undo
                res = res << 1;
            }
            else{
                // divide
                res = res - ((long)divisor << 32);
                res = res << 1;
                res += 1;
            }
        }
        unsigned int result = (unsigned int)res;
        if(is_neg){
            if(result > pow(2, 31)){
                return pow(2, 31) -1;
            }
            else{
                return -result;
            }
        }
        else{
            if(result >= pow(2, 31)){
                return pow(2, 31) - 1;
            }
            else{
                return result;
            }
        }
    }
};

int main()
{
    Solution S;
    cout << S.divide(-2147483648, -1);
}