#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class Tree
{
public:
    TreeNode root;

    Tree() : root(-1)
    {
    }

    void fill_with_permutation(vector<int> values)
    {
        fill_with_permutation(&root, values);
    }

    void print(int depth, bool with_repetition = false)
    {
        vector<int> path;
        for (auto child : root.children)
        {
            print(depth-1, child, path, with_repetition);
        }
    }

private:
    void print(int depth, TreeNode *node, vector<int> path, bool with_repetition = false)
    {
        if (depth == 0)
        {
            path.push_back(node->val);
            for (auto val : path)
            {
                cout << val << " ";
            }
            cout << endl;
            return;
        }

        vector<int> new_path = path;
        new_path.push_back(node->val);
        for (auto child : node->children)
        {
            if (with_repetition)
                if (child->val < node->val)
                {
                    continue;
                }
            print(depth - 1, child, new_path, with_repetition);
        }
    }

    void fill_with_permutation(TreeNode *node, vector<int> values)
    {
        if (values.empty())
        {
            return;
        }

        for (int i = 0; i < values.size(); i++)
        {
            TreeNode *child = new TreeNode(values[i]);
            vector<int> new_values = values;
            new_values.erase(new_values.begin() + i);
            fill_with_permutation(child, new_values);
            node->children.push_back(child);
        }
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 4, 5, 6};
    Tree tree;
    tree.fill_with_permutation(values);

    tree.print(values.size());
    return 0;
}
