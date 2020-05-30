#include "offer_code.h"
#include <algorithm>
#include <vector>

//数组中重复的数字
int findRepeatNumber(vector<int>& nums) {

    map<int, int> sum;
    for(int i = 0; i < nums.size(); i++) {
        if (sum.find(nums[i]) == sum.end()) {
            sum[nums[i]] == 1;
        } else {
            return  nums[i];
        }
    }
    return 0;
}


//二维数组中的查找
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) {
        return false;

    }

    int height = matrix.size();
    int lenght = matrix[0].size();

    int i = 0;
    int m = lenght - 1;
    while (m >= 0 && i < height) {
        if(target == matrix[i][m]) {
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
    for(int i = 0; i < l1; i++) {
        if (s[i] == ' ') {
            s += "00";
        }
    }
    int l2 = s.size();
    if (l2 <= l1) {
        return s;

    }
    l2--;
    for(int i = l1 - 1; i >= 0; i--) {
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
vector<int> reversePrint(ListNode* head) {
    vector<int> num;
    stack<ListNode*> sNode;
    while (head != NULL) {
        sNode.push(head);
        head = head->next;
    }
    while(!sNode.empty()) {
        ListNode* t = sNode.top();
        num.push_back(t->val);
        sNode.pop();

    }
    return num;
}

//反转链表
ListNode* revertListNode(ListNode * head) {

    ListNode* revert = NULL;
    ListNode* node = head;
    while(node->next != NULL) {
        ListNode* temp = node->next;
        node->next = revert;
        revert = node;
        node = temp;
    }
    return revert;
}


//重建二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> indexMap;
    int size = inorder.size();
    for (int i = 0; i < size; i++) {
        indexMap[inorder[i]] = i;
    }
    return buildN(preorder, 0, size, inorder, 0, size, indexMap);
}

TreeNode* buildN(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, map<int, int>& indexMap ) {
    cout << pl << ":" << pr << "-" << il << ":" << ir << endl;
    if(pl == pr) {
        return NULL;
    }
    int root = preorder[pl];
    TreeNode* tree = new TreeNode(root);
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
    for(int i = 2; i <= n; i++) {
        int t = t2;
        t2 = (t1 + t2) % 1000000007;
        t1 = t;
    }
    return t2;
}
//旋转数组的最小数字
int minArray(vector<int>& numbers) {
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
    for(int i = 1; i < numbers.size(); i++) {
        if(numbers[i] < num) {
            num = numbers[i];
        }
    }
    return num;
}

//矩阵中的路径
bool exist(vector<vector<char>>& board, string word) {
    bool r = false;
    for(int m = 0; m < board.size(); m++) {
        for(int n = 0; n < board[0].size(); n++) {
            r = r || dfs(board, m, n, word, 0);
        }
    }
    return r;
}

bool dfs(vector<vector<char>> & board, int m, int n, string word, int index) {

    if (m >= board.size() || m < 0 || n >= board[0].size() || n < 0) {
        return false;
    }
    if (board[m][n] == word[index]) {
        if (index == (word.size() - 1)) {
            return true;
        }
        char t = board[m][n];
        board[m][n] = 'x';
        bool r = dfs(board, m, n + 1, word, index + 1)
                 || dfs(board, m, n - 1, word, index + 1)
                 || dfs(board, m + 1, n, word, index + 1)
                 || dfs(board, m - 1, n, word, index + 1);

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

int move(int m, int n, int k, int & s, map<string, int>& maps, int mt, int nt) {
    string t = to_string(m) + "-" + to_string(n);
    if(maps.find(t) != maps.end()) {
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
    return  dp[n];


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
    while(b > 0) {
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
    for(int i = 0; i < n; i++) {
        sum *= 10;

    }
    vector<int> s;
    for(int i = 1; i < sum; i++) {
        s.push_back(i);

    }
    return s;


}
