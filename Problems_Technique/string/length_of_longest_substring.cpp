#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> freq(256, 0);  // har character ki frequency rakhne ke liye
    int l = 0;                 // left pointer
    int maxLen = 0;            // result

    for (int r = 0; r < s.size(); r++) {
        char c = s[r];
        freq[c]++;             // right character add karo window me

        // agar repeat mil gaya toh left pointer move karo
        while (freq[c] > 1) {
            freq[s[l]]--;
            l++;
        }

        // window size update
        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;     // 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;    // 3
}
