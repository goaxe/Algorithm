/*=============================================================================
#     FileName: 133-CloneGraph.cpp
#         Desc: AC, 80ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-30 09:06:14
#      Version: 0.0.1
#   LastChange: 2015-08-30 09:06:14
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if (!node) {
                return NULL;
            }
            unordered_map<int, UndirectedGraphNode *> nodeMap;
            queue<UndirectedGraphNode *> nodeQueue;
            nodeQueue.push(node);
            while (!nodeQueue.empty()) {
                UndirectedGraphNode *node = nodeQueue.front();
                nodeQueue.pop();
                if (!nodeMap.count(node->label)) {
                    nodeMap.insert(pair<int, UndirectedGraphNode *>(node->label, new UndirectedGraphNode(node->label)));
                    for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it ++) {
                    if ((*it)->label != node->label) {
                        nodeQueue.push(*it);
                    }
                }
                }

            }
            nodeQueue.push(node);
            while (!nodeQueue.empty()) {
                UndirectedGraphNode *node = nodeQueue.front();
                nodeQueue.pop();
                if (nodeMap[node->label]->neighbors.empty()) {
                    for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it ++) {
                        nodeMap[node->label]->neighbors.push_back(nodeMap[(*it)->label]);
                        nodeQueue.push(*it);
                    }
                }
            }
            return nodeMap[node->label];
        }
};

int main() {
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);

    Solution solution;
    solution.cloneGraph(node);
}
