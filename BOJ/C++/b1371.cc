#include <bits/stdc++.h>
using namespace std;

int freq[26]; // Only 26 letters in the English alphabet

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char c;
    while (cin >> noskipws >> c) { // Read including whitespace
        if (islower(c)) {         // Check if the character is a lowercase letter
            ++freq[c - 'a'];      // Increment only if it's a lowercase letter
        }
    }

    int mx = -1;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > mx) {
            mx = freq[i];         // Find the maximum frequency
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (freq[i] == mx) {
            cout << char(i + 'a'); // Output all characters with the maximum frequency
        }
    }

    cout << endl; // Ensure to end output with a newline for clarity and completeness
}
