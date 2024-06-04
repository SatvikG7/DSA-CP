#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int max_sum = nums[0];
    int sum = nums[0];
    for(int i=1; i<nums.size(); i++){
        sum = max(nums[i], sum+nums[i]);
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;
  return 0;
}