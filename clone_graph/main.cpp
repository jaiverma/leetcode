#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

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
    Node* cloneGraph(Node* node) {
        std::queue<Node*> q;
        std::unordered_map<int,bool> visited;
        std::unordered_map<int,Node*> constructed;

        if (node == nullptr)
            return nullptr;

        q.push(node);
        visited[node->val] = true;
        Node *newGraph = new Node(node->val);
        constructed[node->val] = newGraph;
        Node *cur = newGraph;

        while (!q.empty()) {
            Node *v = q.front();
            q.pop();
            if (constructed.find(v->val) != constructed.end())
                cur = constructed[v->val];
            else {
                cur = new Node(v->val);
                constructed[v->val] = cur;
            }

            for (Node *neighbor : v->neighbors) {
                if (visited.find(neighbor->val) == visited.end()) {
                    q.push(neighbor);
                    visited[neighbor->val] = true;
                    if (constructed.find(neighbor->val) != constructed.end())
                        cur->neighbors.push_back(constructed[neighbor->val]);
                    else {
                        constructed[neighbor->val] = new Node(neighbor->val);
                        cur->neighbors.push_back(constructed[neighbor->val]);
                    }
                }
                else {
                    cur->neighbors.push_back(constructed[neighbor->val]);
                }
            }
        }
        return newGraph;
    }
};

int main() {
    auto s = Solution();
}
