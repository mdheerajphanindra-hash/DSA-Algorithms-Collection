#include <iostream>
#include <climits>
using namespace std;

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    return maxVal(maxVal(a, b), c);
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArray(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    return max3(
        maxSubArray(arr, low, mid),
        maxSubArray(arr, mid + 1, high),
        maxCrossingSum(arr, low, mid, high)
    );
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_sum = maxSubArray(arr, 0, n - 1);

    cout << max_sum;

    return 0;
}
