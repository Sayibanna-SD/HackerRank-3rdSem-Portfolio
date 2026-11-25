#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);   // n empty sequences
    vector<int> answers;
    int lastAnswer = 0;
    for (auto& q : queries) {
        int type = q[0], x = q[1], y = q[2];
        int idx = (x ^ lastAnswer) % n;           // bitwise XOR picks the sequence
        if (type == 1) {
            arr[idx].push_back(y);                // query type 1: append y
        } else {
            lastAnswer = arr[idx][y % arr[idx].size()];  // query type 2: read value
            answers.push_back(lastAnswer);
        }
    }
    return answers;
}

// Local tests
int main() {
    // Test 1 (typical): expect 7 3
    vector<vector<int>> q1 = {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
    vector<int> r1 = dynamicArray(2, q1);
    cout << "Test 1:";
    for (int v : r1) cout << " " << v;
    cout << " (expected 7 3)\n";

    // Test 2 (edge, single sequence): expect 9
    vector<vector<int>> q2 = {{1, 0, 9}, {2, 0, 0}};
    vector<int> r2 = dynamicArray(1, q2);
    cout << "Test 2:";
    for (int v : r2) cout << " " << v;
    cout << " (expected 9)\n";
    return 0;
}
