#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    int n = s.size();
    
    for (int i = 0; i < n; ) {
        // skip spaces
        while (i < n && s[i] == ' ') i++;

        // read a word
        int start = i;
        while (i < n && s[i] != ' ') i++;

        if (start < i) {
            words.push_back(s.substr(start, i - start));
        }
    }

    // reverse the words order
    reverse(words.begin(), words.end());

    // join with single spaces
    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }

    return result;
}

int main() {
    cout << reverseWords("  the   sky  is  blue  ") << "\n";
    return 0;
}
