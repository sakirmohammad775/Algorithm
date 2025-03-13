#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> maxWaterContainer(const vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int max_area = 0;
    pair<int, int> best_pair = {left, right};

    while (left < right) {
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int area = height * width;

        if (area > max_area) {
            max_area = area;
            best_pair = {left, right};
        }

        // Move the pointer for the shorter line
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return best_pair;
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Number of lines (or sticks)
        vector<int> heights(n);

        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        // Find the pair of indices that can hold the most water
        pair<int, int> result = maxWaterContainer(heights);

        // Output the indices
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
/*input->
2
9
1 8 3 4 0 7 6 5 2
5
5 2 1 6 3
output-> 
1 5  
0 3

*/ 
