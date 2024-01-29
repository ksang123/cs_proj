#include <stdio.h>
#include <math.h>
#include "leetcode.h"

int main(void) {
    char* str = "abc abc bc";
    printf("\"%s\": %d",str, lengthOfLongestSubstring(str));
    return 0;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
}
