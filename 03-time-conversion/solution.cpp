#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    string rest = s.substr(2, 6);       // ":MM:SS"
    bool isPM = (s[8] == 'P');

    if (hour == 12) hour = 0;           // 12 AM becomes 00, and 12 PM becomes 12 below
    if (isPM) hour += 12;

    string h = (hour < 10 ? "0" : "") + to_string(hour);
    return h + rest;
}

// Local tests
int main() {
    // Test 1 (typical): expect 19:05:45
    cout << "Test 1: " << timeConversion("07:05:45PM") << " (expected 19:05:45)\n";

    // Test 2 (edge, midnight): expect 00:40:22
    cout << "Test 2: " << timeConversion("12:40:22AM") << " (expected 00:40:22)\n";

    // Test 3 (edge, noon): expect 12:00:00
    cout << "Test 3: " << timeConversion("12:00:00PM") << " (expected 12:00:00)\n";
    return 0;
}
