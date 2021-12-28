#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define EMPTY_TREE_VAL (-9999)
class Codec {
private:

    //用先序遍历序列化
    string serializeString;
    void serializeProcess(TreeNode* root) {
        if (root == nullptr) {
            serializeString += " ^ ";  //^表示空树
            return;
        }
        
        serializeString += " ";
        serializeString += to_string(root->val);
        serializeString += " ";

        serializeProcess(root->left);
        serializeProcess(root->right);
    }

    //  1321  2  ^  ^  3  4  ^  ^  5  ^  ^  
    //解析序列化后的string
    vector<int> parseMsg(string& str) {

        vector<int> result;
        for (int i = 0; i < str.size(); i++) {
            
            char c = str[i];
            switch (c)
            {
                case ' ': {
                    continue;
                }
                case '^': {
                    result.push_back(EMPTY_TREE_VAL);
                    break;
                }
                default: {
                    string numStr;
                    int j;
                    for (j = i; str[j] != ' '; j++) {
                        numStr.push_back(str[j]);
                    }
                    i = j;
                    result.push_back(atoi(numStr.c_str()));
                    break;
                }
            }
        }

        return result;
    }

    //用先序遍历反序列化
    int index = 0;
    TreeNode* deserializeProcess(vector<int> &result) {
        int val = result[index++];
        if (val == EMPTY_TREE_VAL) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(val);
        node->left = deserializeProcess(result);
        node->right = deserializeProcess(result);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serializeString += " ";
        serializeProcess(root);
        serializeString += " ";

        return serializeString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int> result = parseMsg(data);
        this->index = 0;
        return deserializeProcess(result);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    Codec codec;
    codec.deserialize("  1321  2  ^  ^  3  4  ^  ^  5  ^  ^  ");
}
