#include <bits/stdc++.h>
using namespace std;

void findMaxWater(int size, vector<int>& heights) {
    int start = 0;
    int end = size - 1;
    int maxCapacity = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    while (start < end) {
        int currentCapacity = min(heights[start], heights[end]) * (end - start);
        if (currentCapacity > maxCapacity) {
            maxCapacity = currentCapacity;
            leftIndex = start;
            rightIndex = end;
        }
        if (heights[start] < heights[end]) {
            start++;
        } else {
            end--;
        }
        
    }
    cout << leftIndex << " " << rightIndex << endl;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int size;
        cin >> size;
        vector<int> heights(size);
        for (int i = 0; i < size; i++) {
            cin >> heights[i];
        }
        findMaxWater(size, heights);
    }
    return 0;
}
