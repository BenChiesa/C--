#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> result;
    
    for(int i=0; i<n; i++){
        if(nums[i] == target) result.push_back(i);
    }

    return result;
}

int main(){
    vector<int> nums = {3, 1, 2, 3, 4, 3};
    int target = 3;

    vector<int> result = targetIndices(nums, target);

    cout << "Target indices after sorting: ";
    for(int index : result){
        cout << index << " ";
    }
    cout << endl;

    return 0;
}