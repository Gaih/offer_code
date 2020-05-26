#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool findNumberIn2DArray(vector<vector<int>>& , int ); 
TreeNode* build(vector<int>& ,int ,int , vector<int>& ,int ,int,map<int, int> ) ;
TreeNode* buildTree(vector<int>& , vector<int>& ) ;
