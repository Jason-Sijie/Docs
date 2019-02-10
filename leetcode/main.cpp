#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> s = {1, 2, 3};
    if(s.find(4) == s.end())
        cout << "does not find";
    return 0;
}