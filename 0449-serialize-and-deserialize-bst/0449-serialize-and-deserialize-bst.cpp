/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, string& s) {

        if (!root) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        encode(root->left, s);
        encode(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;

        encode(root, s);

        return s;
    }

    TreeNode* decode(stringstream& ss) {

        string token;

        getline(ss, token, ',');

        if (token == "N") {
            return nullptr;
        }

        TreeNode* root =
            new TreeNode(stoi(token));

        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return decode(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;