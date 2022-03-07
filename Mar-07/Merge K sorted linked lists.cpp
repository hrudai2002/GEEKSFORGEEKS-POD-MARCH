https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

Node * mergeKLists(Node *arr[], int K)
    {
          vector<int> ans;
          for(int i = 0; i < K; ++i) {
              Node* temp = arr[i];
              while(temp != NULL) {
                  ans.push_back(temp->data);
                  temp = temp->next;
              }
          }
          sort(ans.begin(), ans.end());
          Node* root = new Node(ans[0]);
          Node* node = root;
          for(int i = 1; i < ans.size(); ++i) {
              Node* temp = new Node(ans[i]);
              node->next = temp;
              node = temp;
              
          }
          return root;
    }
