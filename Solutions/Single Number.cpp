class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int run_xor = 0;

		for (int i = 0; i < nums.size(); i++)
			run_xor ^= nums[i];

		return run_xor;
	}
};