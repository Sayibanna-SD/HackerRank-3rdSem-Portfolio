#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> freq;
    for (const string& s : strings) freq[s]++;   // count every string once

    vector<int> result;
    for (const string& q : queries) {
        auto it = freq.find(q);
        result.push_back(it == freq.end() ? 0 : it->second);  // 0 if never seen
    }
    return result;
}

// Local tests
int main() {
    // Test 1 (typical): expect 2 1 0
    vector<int> r1 = matchingStrings({"aba", "baba", "aba", "xzxb"}, {"aba", "xzxb", "ab"});
    cout << "Test 1:";
    for (int v : r1) cout << " " << v;
    cout << " (expected 2 1 0)\n";

    // Test 2 (edge, no matches): expect 0
    vector<int> r2 = matchingStrings({"a", "b"}, {"c"});
    cout << "Test 2:";
    for (int v : r2) cout << " " << v;
    cout << " (expected 0)\n";
    return 0;
}
