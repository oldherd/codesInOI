#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    for(int i = 1; i <= t; ++i) {
        cin >> s;
        char ch = s[s.length() - 1];
        if(ch == 'o') {
            cout << "FILIPINO" << '\n';
        } else if(ch == 'u') {
            cout << "JAPANESE" << '\n';
        } else {
            cout << "KOREAN" << '\n';
        }
    }
    return 0;
}
