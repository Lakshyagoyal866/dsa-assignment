#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v; 
    int weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<int> parent;


int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]); 
}

void unionSets(int i, int j) {
    int root_i = findSet(i);
    int root_j = findSet(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}


void kruskalMST(int numNodes, vector<Edge>& edges) {
    parent.resize(numNodes);
    iota(parent.begin(), parent.end(), 0); 

    
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> mstEdges;
    int mstWeight = 0;
    int edgesCount = 0;

    cout << "Edges selected for MST (Kruskal's):\n";

    for (const auto& edge : edges) {
        if (findSet(edge.u) != findSet(edge.v)) {
            mstEdges.push_back(edge);
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v); 
            edgesCount++;
            
            cout << "Edge: " << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";

       
            if (edgesCount == numNodes - 1) {
                break;
            }
        }
    }

    cout << "\nTotal MST Weight: " << mstWeight << "\n";
}

int main() {

    int numNodes = 6; 
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2},
        {2, 3, 3}, {2, 5, 2}, {2, 4, 4},
        {3, 4, 3}, {5, 4, 3}
    };

    kruskalMST(numNodes, edges);

    return 0;
}