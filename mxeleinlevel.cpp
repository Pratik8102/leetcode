#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For max_element

// Define the TreeNode structure here (assuming a typical definition)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) 
    {
        std::queue<TreeNode*> pq;
        pq.push(root);
        std::vector<int> ans;
        if (root == nullptr) return ans;
        while (!pq.empty()) {
            int size = pq.size();
            std::vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                if (node->left) {
                    pq.push(node->left);
                }
                if (node->right) {
                    pq.push(node->right);
                }
                level.push_back(node->val);
            }
            int maxi = *std::max_element(level.begin(), level.end());
            ans.push_back(maxi);
        } 
        return ans;
    }
};

int main() {
    // Create a sample binary tree (you should replace this with your own tree)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solution;
    std::vector<int> result = solution.largestValues(root);

    std::cout << "Largest values in each level: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Don't forget to free memory by deleting the tree nodes if needed
    // (This is just a simple example, and proper memory management is important)
    
    return 0;
}
