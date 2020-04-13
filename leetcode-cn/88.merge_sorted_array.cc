#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = 0, right = 0;
    vector<int> original;
    for (int i = 0; i < m; i++) {
        original.push_back(nums[i])
    }
    int p = 0;
    while (left < m && right < n) {
        if (original[left] < nums2[right]) {
            nums1[p++] = original[left++];
        } else {
            nums1[p++] = nums2[right++]
        }
    }
    while (left < m) {
        nums1[p++] = original[left++];
    }
    while (right < n) {
        nums1[p++] = nums2[right++];
    }
}