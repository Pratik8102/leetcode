#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        std::queue<TreeNode*> pq;
        int cnt = 0;

        if (root == nullptr) {
            return cnt;
        }

        pq.push(root);

        while (!pq.empty()) {
            int size = pq.size();
            std::vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                level.push_back(node->val);

                if (node->left) pq.push(node->left);
                if (node->right) pq.push(node->right);
            }

            std::unordered_map<int, int> mp;

            for (int i = 0; i < level.size(); i++) {
                mp[level[i]] = i;
            }

            std::sort(level.begin(), level.end());
            int i = 0;

            while (i < level.size()) {
                if (mp[level[i]] != i) {
                    std::swap(level[i], level[mp[level[i]]]);
                    cnt++;
                } else {
                    i++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    // Create a sample binary tree (you should replace this with your own tree)
    TreeNode* root = new TreeNode(3, new TreeNode(5), new TreeNode(4));
    root->left->left = new TreeNode(1);

    Solution solution;
    int result = solution.minimumOperations(root);

    std::cout << "Minimum operations: " << result << std::endl;

    // Proper memory management is important, so delete the tree nodes.
    // (This is just a simple example; make sure to free memory in your actual code.)

    return 0;
}
