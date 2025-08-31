#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; ++i) {
        if (nums[i] > temp.back()) {
            temp.push_back(nums[i]); // extend LIS
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i]; // replace to maintain smallest possible tail
        }
    }

    cout << temp.size() << endl;
}
