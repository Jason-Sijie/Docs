#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
// #include <functional>
using namespace std;

int main()
{
    // priority_queue<int, vector<string>, less<string>> pq;

    // pq.push("Jason");
    // pq.push("Yu");
    // pq.push("Sijie");

    // for(int i = 0; i<3; i++){
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }

    vector<int> V = {1, 2, 3, 4, 5};
    sort(V.begin(), V.end(), [](int x, int y){return x < y;});
    for(int i = 0; i<5; i++){
        cout << V[i] << endl;
    }

    return 0;

}

