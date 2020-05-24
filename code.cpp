#include "offer_code.h"



//数组中重复的数字
int findRepeatNumber(vector<int>& nums) {

	map<int, int> sum;
	for(int i=0;i<nums.size();i++){
		if (sum.find(nums[i]) == sum.end()){
			sum[nums[i]] == 1;
		}else{
			return  nums[i];
		}
	}
	return 0;


}
