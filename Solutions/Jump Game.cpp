class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size(), i, nearestReachable = n - 1;

		for (i = n - 2; i >= 0; i--) {
			if (i + nums[i] >= nearestReachable)
				nearestReachable = i;
		}

		return nearestReachable == 0;
	}
};