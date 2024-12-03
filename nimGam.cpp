#include <bits/stdc++.h>
using namespace std;

bool can_win(int n) {
    if (n == 0 || n == 1) return false;

    if (!can_win(n - 2) || !can_win(n - 3) || !can_win(n - 5)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    if (can_win(n)) {
        cout << "Win" << endl;
    } else {
        cout << "Lose" << endl;
    }

    return 0;
}
