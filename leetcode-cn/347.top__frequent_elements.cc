#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> nums_times;
    for (int i = 0; i < nums.size(); i++) {
        nums_times[nums[i]]++;
    }
    vector<pair<int, int>> sorted_nums(nums_times.begin(), nums_times.end());
    std::sort(sorted_nums.begin(), sorted_nums.end(), [](const pair<int, int>& l, const pair<int, int>& r){
        return l.second > r.second;
    });
    vector<int> vec_topK;
    for(int i=0;i<k;++i){
        vec_topK.push_back(sorted_nums[i].first);
    }
    return vec_topK;
}

int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    vector<int> result = topKFrequent(nums, 2);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}