/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *root, Node *copy, vector<Node*> &visited) {
        visited[copy->val] = copy;
        
        for(Node *node: root->neighbors) {
            if(!visited[node->val]) {
                Node *newNode = new Node(node->val);
                (copy->neighbors).push_back(newNode);
                dfs(node, newNode, visited);
            } else {
                (copy->neighbors).push_back(visited[node->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        vector<Node*> visited(101, NULL);
        Node* copy = new Node(node->val);
        dfs(node, copy, visited);
    
        return copy;
    }
};