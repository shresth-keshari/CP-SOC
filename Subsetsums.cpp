#include <vector>
#include <iostream>

using namespace std;

void calculateSubsetSums(vector<int>& arr, int n, int index, int current_sum, vector<int>& result) {
    if (index == n) {
        result.push_back(current_sum);
        return;
    }

    // Include the current element in the subset
    calculateSubsetSums(arr, n, index + 1, current_sum + arr[index], result);

    // Exclude the current element from the subset
    calculateSubsetSums(arr, n, index + 1, current_sum, result);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> result;
    calculateSubsetSums(arr, n, 0, 0, result);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<int> sums = subsetSums(arr, n);

    for (int sum : sums) {
        cout << sum << " ";
    }

    return 0;
}
