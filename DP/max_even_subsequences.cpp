#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const long long NEG_INF = -4e18;

    long long even = NEG_INF;
    long long odd  = NEG_INF;
    long long maxsum = NEG_INF;

    for (int i = 0; i < n; i++) {
        long long x = a[i];
        long long new_even = NEG_INF;
        long long new_odd  = NEG_INF;

        if (x % 2 == 0) {
            // chẵn
            new_even = x;
            if (even != NEG_INF)
                new_even = max(new_even, even + x);

            if (odd != NEG_INF)
                new_odd = odd + x;
        } else {
            // lẻ
            if (odd != NEG_INF)
                new_even = odd + x;

            new_odd = x;
            if (even != NEG_INF)
                new_odd = max(new_odd, even + x);   
        }

        even = new_even;
        odd  = new_odd;

        maxsum = max(maxsum, even);
    }

    if (maxsum == NEG_INF)
        cout << "NOT_FOUND";
    else
        cout << maxsum;
}
