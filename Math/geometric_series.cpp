#include <iostream>
#include <cmath>
using namespace std;

int geometricSeries(int a, int r, int n) {
    if (r == 1)
        return a * n;
    return (a * (pow(r, n) - 1)) / (r - 1);
}

int main() {
    int a, r, n;
    cin >> a >> r >> n;

    cout << geometricSeries(a, r, n);

    return 0;
}
