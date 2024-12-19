#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		unordered_map<int, int> mp;
		for(int i = 0; i < nums.size(); i++)
		{
			int j;
			for(j = i+1; j < nums.size(); j++)
			{
				if(nums[j] % 2 == nums[j-1] % 2)
				{
					break;
				}
			}
			mp[i] = j;
		}
		
		vector<bool> res(queries.size(), false);

		for(int i = 0; i < queries.size(); i++)
		{
			int start = queries[i][0];
			int end = queries[i][1];
			if(mp[start] > end)
			{
				res[i] = true;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums = {4,3,1,6};
	vector<vector<int>> queries = {{0, 2}, {2,3}};

	vector<bool> res = s.isArraySpecial(nums, queries);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
