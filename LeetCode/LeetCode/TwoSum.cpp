#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		for(int ii=0;ii<nums.size();ii++)
			for (int jj = ii; jj < nums.size(); jj++)
			{
				if (nums[ii] + nums[jj] == target)
				{
					ans.push_back(ii);
					ans.push_back(jj);
				}
			}
		return ans;
	}
};