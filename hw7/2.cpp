#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildBST(vector<int>& a, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = (left + right) / 2;

    Node* root = new Node(a[mid]);

    root->left = buildBST(a, left, mid - 1);
    root->right = buildBST(a, mid + 1, right);

    return root;
}

void printByLevel(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    bool firstLevel = true;

    while (!q.empty()) {
        int sz = q.size();

        if (!firstLevel) {
            cout << "| ";
        }
        firstLevel = false;

        for (int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();

            cout << cur->val << " ";

            if (cur->left != nullptr) {
                q.push(cur->left);
            }

            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* root = buildBST(a, 0, n - 1);

    printByLevel(root);

    return 0;
}