#include <bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int alice = 0, bob = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) alice++;      // Alice scores a point
        else if (a[i] < b[i]) bob++;   // Bob scores a point
        // equal values give no point
    }
    return {alice, bob};
}

// Local tests
int main() {
    // Test 1 (typical): expect 1 1
    vector<int> r1 = compareTriplets({5, 6, 7}, {3, 6, 10});
    cout << "Test 1: " << r1[0] << " " << r1[1] << " (expected 1 1)\n";

    // Test 2 (edge, all equal): expect 0 0
    vector<int> r2 = compareTriplets({4, 4, 4}, {4, 4, 4});
    cout << "Test 2: " << r2[0] << " " << r2[1] << " (expected 0 0)\n";
    return 0;
}
