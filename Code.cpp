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


//二维数组中的查找
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.size()==0){
		return false;

	}

	int height = matrix.size();
	int lenght = matrix[0].size();

	int i = 0;
	int m = lenght-1;
	while (m>=0 && i<height) {
		if(target == matrix[i][m]){
			return true;

		}else if (target>matrix[i][m]) {
			i++;

		}else if (target < matrix[i][m]) {
			m--;

		}

	}
	return false;
}

//替换空格
string replaceSpace(string s) {
	int l1 = s.size();
	for(int i=0;i<l1;i++){
		if (s[i] == ' '){
			s+="00";
		}
	}
	int l2 = s.size();
	if (l2<=l1){
		return s;

	}
	l2--;
	for(int i=l1-1;i>=0;i--){
		char t = s[i];
		if (t == ' '){
			s[l2--]= '0';
			s[l2--]= '2';
			s[l2--]= '%';

		}else{
			s[l2--]= t;

		}

	}
	return s;
}

