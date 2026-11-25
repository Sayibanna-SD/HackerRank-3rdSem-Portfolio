#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int primary = 0, secondary = 0;
    for (int i = 0; i < n; i++) {
        primary += arr[i][i];            // top-left to bottom-right
        secondary += arr[i][n - 1 - i];  // top-right to bottom-left
    }
    return abs(primary - secondary);
}

// Local tests
int main() {
    // Test 1 (typical): expect 15
    vector<vector<int>> a = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
    cout << "Test 1: " << diagonalDifference(a) << " (expected 15)\n";

    // Test 2 (edge, 1x1 matrix): expect 0
    vector<vector<int>> b = {{7}};
    cout << "Test 2: " << diagonalDifference(b) << " (expected 0)\n";
    return 0;
}
