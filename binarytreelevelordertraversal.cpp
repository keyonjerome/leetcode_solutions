using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderTraversal {
public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode*> q;
    TreeNode* current;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for(int i = 0; i < levelSize; i++) {
            current = q.front();
            q.pop();
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
            currentLevel.push_back(current->val);
        }
        result.push_back(currentLevel);
    }
    // TODO: Write your code here
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
