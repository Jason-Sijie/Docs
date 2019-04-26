#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_LENGTH 110

class Solution {
public:
    string multiply(string num1, string num2) {
        string res("0");
        if(num1.length() == 0 || num2.length() == 0){
            return res;
        }
        else if((num1.length() == 1 && num1[0] == '0') || (num2.length() == 1 && num2[0] == '0')){
            return res;
        }

        int idx2 = num2.length() - 1;
        while(idx2 >= 0){
            int n = num2[idx2] - '0';
            int carry = 0, idx1 = num1.length()-1;
            string sum;
            while(idx1 >= 0){
                int tmp = n * (num1[idx1] - '0');
                int cur_num = (tmp + carry) % 10;
                carry = (tmp + carry) / 10;
                sum.insert(0, 1, ('0' + cur_num));
                idx1 --;
            }
            if(carry != 0){
                sum.insert(0, 1, ('0' + carry));
            }

            for(int j = 0; j<num2.length()-1-idx2; j++){
                sum.push_back('0');
            }

            res = AddString(res, sum);
            idx2--;
        }

        return res;
    }
private:
    string AddString(string num1, string num2){
        int cur_num = 0, carry = 0;
        string res;
        
        while(num1.length() && num2.length()){
            int a = num1.back() - '0';
            int b = num2.back() - '0';
            num1.pop_back();
            num2.pop_back();

            int tmp = a + b;
            cur_num = (tmp + carry)%10;
            res.insert(0, 1,  '0'+cur_num);
            carry = (tmp+carry)/10;
        }
        while(num1.length()){
            int a = num1.back();
            num1.pop_back();

            cur_num = (a + carry)%10;
            res.insert(0, 1, '0'+cur_num);
            carry = (a+carry)/10;
        }
        while(num2.length()){
            int b = num2.back();
            num2.pop_back();

            cur_num = (b + carry)%10;
            res.insert(0, 1, '0'+cur_num);
            carry = (b+carry)/10;
        }
        if(carry != 0){
            res.insert(0, 1, '0'+carry);
        }
        
        return res;
    }

};

int main(){
    Solution S;
    cout << S.multiply("2", "3");
}