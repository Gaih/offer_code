#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cstddef>


using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL){}

};
bool findNumberIn2DArray(vector<vector<int>>& , int ); 
TreeNode* buildN(vector<int>&,int,int,vector<int>&,int,int,map<int, int>&);
TreeNode* buildTree(vector<int>&, vector<int>&) ;
bool findNumberIn3DArray(vector<vector<int>>& matrix, int target) ;
string replaceSpace(string );
vector<int> reversePrint(ListNode* );
ListNode* revertListNode(ListNode *);
int minArray(vector<int>&);
int findMin(vector<int> numbers);
int sum(int , int) ;
int move(int m, int n, int k, int & s, map<string, int>& maps, int mt, int nt) ;
int movingCount(int m, int n, int k) ;
bool dfs(vector<vector<char>> & board, int m, int n, string word, int index) ;
