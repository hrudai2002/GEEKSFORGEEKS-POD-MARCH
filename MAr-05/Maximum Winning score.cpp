https://practice.geeksforgeeks.org/problems/4ead9c3991a3822f578309e2232bc5415ac35cb9/1#

long long findMaxScore(Node* root)
    {
        if(root) {
            return root->data * max(findMaxScore(root->left), findMaxScore(root->right));
        }
        return 1;
    }
};
