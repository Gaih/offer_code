#include "offer_code.h"
#include <algorithm>
#include <string>
#include <vector>

//数组中重复的数字
int findRepeatNumber(vector<int> &nums) {

    map<int, int> sum;
    for (int i = 0; i < nums.size(); i++) {
        if (sum.find(nums[i]) == sum.end()) {
            sum[nums[i]] == 1;
        } else {
            return nums[i];
        }
    }
    return 0;
}

//二维数组中的查找
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) {
        return false;
    }

    int height = matrix.size();
    int lenght = matrix[0].size();

    int i = 0;
    int m = lenght - 1;
    while (m >= 0 && i < height) {
        if (target == matrix[i][m]) {
            return true;
        } else if (target > matrix[i][m]) {
            i++;
        } else if (target < matrix[i][m]) {
            m--;
        }
    }
    return false;
}

//替换空格
string replaceSpace(string s) {
    int l1 = s.size();
    for (int i = 0; i < l1; i++) {
        if (s[i] == ' ') {
            s += "00";
        }
    }
    int l2 = s.size();
    if (l2 <= l1) {
        return s;
    }
    l2--;
    for (int i = l1 - 1; i >= 0; i--) {
        char t = s[i];
        if (t == ' ') {
            s[l2--] = '0';
            s[l2--] = '2';
            s[l2--] = '%';
        } else {
            s[l2--] = t;
        }
    }
    return s;
}

//从尾到头打印链表
vector<int> reversePrint(ListNode *head) {
    vector<int> num;
    stack<ListNode *> sNode;
    while (head != NULL) {
        sNode.push(head);
        head = head->next;
    }
    while (!sNode.empty()) {
        ListNode *t = sNode.top();
        num.push_back(t->val);
        sNode.pop();
    }
    return num;
}

//反转链表
ListNode *revertListNode(ListNode *head) {

    ListNode *revert = NULL;
    ListNode *node = head;
    while (node->next != NULL) {
        ListNode *temp = node->next;
        node->next = revert;
        revert = node;
        node = temp;
    }
    return revert;
}

//重建二叉树
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    map<int, int> indexMap;
    int size = inorder.size();
    for (int i = 0; i < size; i++) {
        indexMap[inorder[i]] = i;
    }
    return buildN(preorder, 0, size, inorder, 0, size, indexMap);
}

TreeNode *buildN(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir, map<int, int> &indexMap) {
    cout << pl << ":" << pr << "-" << il << ":" << ir << endl;
    if (pl == pr) {
        return NULL;
    }
    int root = preorder[pl];
    TreeNode *tree = new TreeNode(root);
    tree->left = NULL;
    tree->right = NULL;
    int index = indexMap[root];
    int num = index - il;
    tree->left = buildN(preorder, pl + 1, pl + num + 1, inorder, il, index, indexMap);
    tree->right = buildN(preorder, pl + num + 1, pr, inorder, index + 1, ir, indexMap);
    return tree;
}
//用两个栈实现队列

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {
    }

    void appendTail(int value) {
        stack1.push(value);
    }
    int deleteHead() {
        if (stack2.size() > 0) {
            int t = stack2.top();
            stack2.pop();
            return t;
        } else {
            while (stack1.size() > 0) {
                int t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
            if (!stack2.empty()) {
                int t = stack2.top();
                stack2.pop();
                return t;
            }
            return -1;
        }
    }
};
//斐波那契数列
int fib(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    int t1 = 0;
    int t2 = 1;
    for (int i = 2; i <= n; i++) {
        int t = t2;
        t2 = (t1 + t2) % 1000000007;
        t1 = t;
    }
    return t2;
}
//旋转数组的最小数字
int minArray(vector<int> &numbers) {
    int start = 0;
    int end = numbers.size() - 1;
    int mid = (end + start) / 2;
    while (start < end) {
        if (numbers[start] < numbers[end]) {
            return numbers[start];
        }
        if (end - start == 1) {
            mid = end;
            break;
        }

        if (numbers[mid] == numbers[start] && numbers[start] == numbers[end]) {
            return findMin(numbers);
        }
        if (numbers[mid] >= numbers[start]) {
            start = mid;
        } else if (numbers[mid] <= numbers[end]) {
            end = mid;
        }
        mid = (end + start) / 2;
    }
    return numbers[mid];
}

int findMin(vector<int> numbers) {
    int num = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < num) {
            num = numbers[i];
        }
    }
    return num;
}

//矩阵中的路径
bool exist(vector<vector<char>> &board, string word) {
    bool r = false;
    for (int m = 0; m < board.size(); m++) {
        for (int n = 0; n < board[0].size(); n++) {
            r = r || dfs(board, m, n, word, 0);
        }
    }
    return r;
}

bool dfs(vector<vector<char>> &board, int m, int n, string word, int index) {

    if (m >= board.size() || m < 0 || n >= board[0].size() || n < 0) {
        return false;
    }
    if (board[m][n] == word[index]) {
        if (index == (word.size() - 1)) {
            return true;
        }
        char t = board[m][n];
        board[m][n] = 'x';
        bool r = dfs(board, m, n + 1, word, index + 1) || dfs(board, m, n - 1, word, index + 1) || dfs(board, m + 1, n, word, index + 1) || dfs(board, m - 1, n, word, index + 1);

        board[m][n] = t;
        return r;
    }
    return false;
}

//机器人运动范围
int movingCount(int m, int n, int k) {
    int s = 0;
    map<string, int> maps;
    move(0, 0, k, s, maps, m - 1, n - 1);
    return s;
}

int move(int m, int n, int k, int &s, map<string, int> &maps, int mt, int nt) {
    string t = to_string(m) + "-" + to_string(n);
    if (maps.find(t) != maps.end()) {
        return s;
    }
    if (m > mt || n > nt) {
        return s;
    }
    if (sum(m, n) <= k) {
        s++;
        maps[t] = 1;
        move(m, n + 1, k, s, maps, mt, nt);
        move(m + 1, n, k, s, maps, mt, nt);
    }

    return s;
}

int sum(int m, int n) {
    int s = 0;
    s += (m / 10);
    s += (m % 10);
    s += (n / 10);
    s += (n % 10);
    return s;
}

//剪绳子
int cuttingRope(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - i] * i);
        }
    }
    return dp[n];
}
//二进制中1的个数
int hammingWeight(uint32_t n) {
    int num = 0;
    while (n != 0) {
        num += n & 1;
        n >>= 1;
    }
    return num;
}
//数组的整数次方
double myPow(double x, int n) {
    if (n == 1) {
        return x;
    }
    double sum = 1;
    long b = n;
    if (b < 0) {
        b = -b;
        x = 1 / x;
    }
    while (b > 0) {
        if (b & 1) {
            sum *= x;
        }
        b /= 2;
        x *= x;
    }
    return sum;
}
//打印从1到最大的n位数
vector<int> printNumbers(int n) {
    int sum = 1;
    for (int i = 0; i < n; i++) {
        sum *= 10;
    }
    vector<int> s;
    for (int i = 1; i < sum; i++) {
        s.push_back(i);
    }
    return s;
}
//删除链表的节点
ListNode *deleteNode(ListNode *head, int val) {
    ListNode *final = new ListNode(0);
    ListNode *newhead = final;
    while (head != NULL) {
        if (head->val == val) {
            head = head->next;
            continue;
        }
        ListNode *t = new ListNode(0);
        t->val = head->val;
        t->next = NULL;
        newhead->next = t;
        newhead = newhead->next;

        head = head->next;
    }
    return final->next;
}
//正则表达式匹配
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < n; i++) {
        if (p[i] == '*') {
            dp[0][i + 1] = dp[0][i - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[j] == '.' || s[i] == p[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (p[j] == '*') {
                if (s[i] != p[j - 1] && p[j - 1] != '.') {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i][j - 1] || dp[i + 1][j - 1];
                }
            } else {
                dp[i + 1][j + 1] = false;
            }
        }
    }
    return dp[m][n];
}
//调整数组顺序使奇数位于前面
vector<int> exchange(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    exchange(nums, start, end);
    return nums;
}

void exchange(vector<int>& nums, int start, int end) {
    if(start >= end) {
        return;
    }
    while (nums[start] % 2 != 0 && start < end) {
        start++;
    }
    while(nums[end] % 2 == 0 && end > start) {
        end--;
    }
    if (start < end) {
        swap(nums[start], nums[end]);
        exchange(nums, start + 1, end - 1);
    }
}
//链表倒数第k个节点
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode * first = head;
    ListNode * sec = head;
    int n = 0;
    while(first != NULL) {
        first = first->next;
        if (n >= k) {
            sec = sec->next;

        }
        n++;

    }
    return sec;
}
//表示数值的字符串
bool isNumber(char *s) {
    const char *p = s.data();
    bool bIsNumber = false;
    while (' ' == *p) {
        p++;
    }
    if ('-' == *p || '+' == *p) {
        p++;
    }
    while (isdigit(*p)) {
        bIsNumber = true;
        p++;
    }
    if ('.' == *p) {
        p++;
    }
    while (isdigit(*p)) {
        bIsNumber = true;
        p++;
    }
    if (bIsNumber && 'e' == *p) {
        p++;
        bIsNumber = false;
        if ('+' == *p || '-' == *p) {
            p++;
        }
        while (isdigit(*p)) {
            p++;
            bIsNumber = true;
        }
    }
    while (' ' == *p) {
        p++;
    }
    return '\0' == *p && bIsNumber;
}
//合并排序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}
//树的子结构
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == NULL || B == NULL) {
        return false;

    }
    bool c = false;
    while(A != NULL) {
        if (A->val == B->val) {
            c = judge(A, B);

        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B) || c;

    }
    return false;


}
bool judge(TreeNode* A, TreeNode * B) {
    if (B == NULL) {
        return true;

    }
    if (A == NULL || A->val != B->val) {
        return false;

    }
    return judge(A->left, B->left) && judge(A->right, B->right);

}
//全排列
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    map<int, int>track;
    backtrack(nums, track, temp, res);
    return res;
}
void backtrack(vector<int> & nums, map<int, int>&track, vector<int>& temp, vector<vector<int>>& res) {
    if (temp.size() == nums.size()) {
        res.push_back(temp);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if (track.find(nums[i]) != track.end()) {
            continue;
        }
        temp.push_back(nums[i]);
        track[nums[i]] = 1;
        backtrack(nums, track, temp, res);
        temp.pop_back();
        track.erase(nums[i]);
    }
}
//8皇后
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    trackback(board, res, 0);
    return res;


}

void trackback(vector<string>& board, vector<vector<string>>& res, int row) {
    if(row >= board.size()) {
        res.push_back(board);
        return;
    }

    int n = board[0].size();
    for(int col = 0; col < n; col++) {
        if (isValid(board, row, col)) {
            continue;
        }
        board[row][col] = 'Q';
        trackback(board, res, row + 1);
        board[row][col] = '.';
    }

}

bool isValid(vector<string> board, int row, int col) {
    int length = board.size();
    int width = board[0].size();
    for(int i = 0; i < width; i++) {
        if (board[i][col] == 'Q') {
            return true;
        }
    }
    int rows = row;
    int cols = col;
    while(rows > 0 && cols > 0) {
        rows--;
        cols--;
        if (board[rows][cols] == 'Q') {
            return true;
        }

    }
    while(row > 0 && col < width - 1) {
        row--;
        col++;
        if (board[row][col] == 'Q') {
            return true;
        }

    }
    return false;
}
//二叉树的镜像
TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;

    }
    TreeNode* cp = new TreeNode(0);
    cp->val = root->val;
    cp->left = mirrorTree(root->right);
    cp->right = mirrorTree(root->left);
    return cp;
}
//顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> nums;
    if (matrix.size() == 0) {
        return nums;
    }
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int down = matrix.size() - 1;
    while(true) {
        if(left > right && top > down) {
            break;
        }
        if(left > right) {
            break;
        }
        for(int i = left; i <= right; i++) {
            nums.push_back(matrix[top][i]);
        }
        top++;
        if (top > down) {
            break;
        }
        for(int i = top; i <= down; i++) {
            nums.push_back(matrix[i][right]);
        }
        right--;

        if(right < left) {
            break;
        }
        for(int i = right; i >= left; i--) {
            nums.push_back(matrix[down][i]);
        }
        down--;
        if (down < top) {
            break;
        }
        for(int i = down; i >= top; i--) {
            nums.push_back(matrix[i][left]);
        }
        left++;
    }
    return nums;
}

//暴力法 最长回文字串
string longestPalindrome(string s) {
    if (s.size() == 1) {
        return s;
    }
    int length = s.size() - 1;
    int left = 0;
    int right = length;
    int maxleft = 0;
    int max = 0;
    for(int i = left; i <= length; i++) {
        for(int j = right; j >= 0; j--) {
            if (left >= right) {
                break;
            }
            int t = 0;
            equal(s, i, j, t);
            // cout<<"i:"<<i<<"j:"<<j<<"t:"<<t<<endl;
            if(t > max) {
                maxleft = i;
                max = t;
            }
        }
    }
    // cout<<maxleft<<endl;
    // cout<<maxright<<endl;
    if (max == 1) {
        return s.substr(0, 1);
    }
    return s.substr(maxleft, max);

}

void equal(string s, int left, int right, int& max) {
    if (left > right) {
        return;
    }
    if (left == right) {
        max++;
        return;
    }

    if (s[left] == s[right]) {
        max += 2;
        equal(s, left + 1, right - 1, max);
        return;
    }
    max = 1;
    return ;
}
//动态规划
string longestPalindrome(string s) {
    if (s.size() == 1) {
        return s;

    }
    int n = s.size();
    int left = 0;
    int maxleft = 0;
    int max = 1;

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;

    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                if (i - j < 3) {
                    dp[i][j] = 1;

                } else {
                    dp[i][j] = dp[i - 1][j + 1];
                }
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] == 1 && i - j + 1 > max) {
                max = i - j + 1;
                left = j;
            }
        }
    }
    return s.substr(left, max);
}

//栈的压入弹出序列
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> mStack;
    int n = 0;
    for(int i = 0; i < popped.size(); i++) {
        mStack.push(pushed[i]);
        while (!mStack.empty() && mStack.top() == popped[n]) {
            mStack.pop();
            n++;
        }

    }
    return n == popped.size();
}
//从上到下打印二叉树
vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode * t = q.front();
        res.push_back(t->val);
        q.pop();
        if (t->left != NULL) {
            q.push(t->left);
        }
        if (t->right != NULL) {
            q.push(t->right);
        }
    }
    return res;
}
//从上到下打印二叉树2
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;

    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vector<int> r;
        for(int i = 0; i < n; i++) {
            TreeNode * t = q.front();
            r.push_back(t->val);
            q.pop();
            if (t->left != NULL) {
                q.push(t->left);

            }
            if (t->right != NULL) {
                q.push(t->right);

            }

        }
        res.push_back(r);


    }
    return res;
}
//从上到下打印二叉树3
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;

    }
    int m = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vector<int> r;
        for(int i = 0; i < n; i++) {
            TreeNode * t = q.front();
            r.push_back(t->val);
            q.pop();
            if (t->left != NULL) {
                q.push(t->left);

            }
            if (t->right != NULL) {
                q.push(t->right);

            }

        }
        if (m % 2 == 1) {
            reverse(r);

        }
        res.push_back(r);
        m++;
    }
    return res;
}

void reverse(vector<int>& a) {
    int temp = 0;
    int n = a.size();
    for (int i = 0; i < n / 2; ++i) {
        temp = a[n - i - 1];
        a[n - i - 1] = a[i];
        a[i] = temp;
    }
}
//二叉搜索树的后序遍历
bool verifyPostorder(vector<int>& postorder) {
    return idBack(postorder, 0, postorder.size() - 1);
}
bool idBack(vector<int>&pos, int i, int j) {
    if (i >= j) {
        return true;
    }
    int p = i;
    while(pos[p] < pos[j]) {
        p++;

    }
    int m = p;
    while(pos[p] > pos[j]) {
        p++;

    }
    return p == j && idBack(pos, i, m - 1) && idBack(pos, m, j - 1);
}
//z型字变换
string convert(string s, int numRows) {
    if (numRows == 1 || numRows == 0) {
        return s;

    }
    int size = s.size() - 1;
    vector<string> res(numRows, "");
    int c = 0;
    int flag = true;
    for(int i = 0; i <= size; i++) {
        res[c] += (s[i]);
        if (flag) {
            c++;

        } else {
            c--;

        }
        if (c == numRows - 1 || c == 0) {
            flag = !flag;

        }


    }
    string sRevert;
    for(int i = 0; i < res.size(); i++) {
        sRevert += res[i];

    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    int target = 0;
    vector<vector<int>> res;
    vector<int> numList(0);
    compare(root, target, sum, numList, res);
    return res;


}

void compare(TreeNode* tree, int target, int sum, vector<int> numList, vector<vector<int>>& res) {
    if (tree != NULL) {
        target += tree->val;
        numList.push_back(tree->val);
        if (target == sum) {
            if (tree->left == NULL && tree->right == NULL) {
                res.push_back(numList);
                return;

            }


        }
        compare(tree->left, target, sum, numList, res);
        compare(tree->right, target, sum, numList, res);
        return;

    }

}
//复杂链表的复制
Node* copyRandomList(Node* head) {
    if (head == NULL) {
        return NULL;

    }
    unordered_map<Node*, Node*> um;
    Node* t = head;
    while(t != NULL) {
        um[t] = new Node(t->val);
        t = t->next;

    }
    t = head;
    while(t != NULL) {
        if (t->next) {
            um[t]->next = um[t->next];

        }
        if (t->random) {
            um[t]->random = um[t->random];

        }
        t = t->next;

    }
    return um[head];


}
Node* treeToDoublyList(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* cur = nullptr;
    Node* head = nullptr;
    dfs(root, cur, head);
    head->left = cur;
    cur->right = head;
    return head;
}
//中序遍历
void dfs(Node* root, Node*& cur, Node*& head) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, cur, head);
    if (cur == NULL) {
        head = root;
        cur = root;
    } else {
        cur->right = root;
        root->left = cur;
        cur = root;
    }
    dfs(cur->right, cur, head);
}

//连续子数组的最大和
int maxSubArray(vector<int>& nums) {
    vector<int> sums(nums.size(), 0);
    sums[0] = nums[0];
    int res = sums[0];
    for(int i = 1; i < nums.size(); i++) {
        sums[i] = nums[i] + max(sums[i - 1], 0);
        res = max(sums[i], res);

    }
    return res;


}
