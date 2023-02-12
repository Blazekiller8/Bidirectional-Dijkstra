// Bidirectional Dijkstra's Algorithm
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001;

// Adjacency List Representation
vector<int> adj[MAX];

// Add Edge to the graph
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// Remove Edge from the graph
void removeEdge(int u, int v) {
  adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
  adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

// Dijkstra's shortest path algorithm
void dijkstra(int src) {
  priority_queue< int, vector<int>, greater<int> > pq;
  vector<int> dist(MAX, INT_MAX);
  pq.push(src);
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        pq.push(v);
      }
    }
  }

  cout << "Vertex Distance from Source" << endl;
  for (int i = 0; i < MAX; i++)
    cout << i << " \t\t " << dist[i] << endl;
}

// Print Inorder, Preorder and Postorder traversal of the graph
void inorder(int u) {
  if (adj[u].empty())
    return;
  for (int i = 0; i < adj[u].size(); i++) {
    inorder(adj[u][i]);
    cout << adj[u][i] << " ";
  }
}

void preorder(int u) {
  if (adj[u].empty())
    return;
  cout << u << " ";
  for (int i = 0; i < adj[u].size(); i++)
    preorder(adj[u][i]);
}

void postorder(int u) {
  if (adj[u].empty())
    return;
  for (int i = 0; i < adj[u].size(); i++)
    postorder(adj[u][i]);
  cout << u << " ";
}

// Get Max and Min element of the graph
int maxElement(int u) {
  int max = INT_MIN;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    max = max > cur ? max : cur;
    max = max > maxElement(cur) ? max : maxElement(cur);
  }
  return max;
}

int minElement(int u) {
  int min = INT_MAX;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    min = min < cur ? min : cur;
    min = min < minElement(cur) ? min : minElement(cur);
  }
  return min;
}

// Get Successor and Predecessor of a node
int successor(int u) {
  int suc = INT_MAX;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    suc = suc < cur ? suc : cur;
  }
  return suc;
}

int predecessor(int u) {
  int pre = INT_MIN;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    pre = pre > cur ? pre : cur;
  }
  return pre;
}

// Print the graph
void printGraph() {
  for (int i = 0; i < MAX; i++) {
    cout << i << " --> ";
    for (int j = 0; j < adj[i].size(); j++)
      cout << adj[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int n, u, v;
  cout << "Enter number of edges: ";
  cin >> n;
  cout << "Enter edges (u v): ";
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    addEdge(u, v);
  }

  cout << "Graph after adding edges: " << endl;
  printGraph();

  cout << "Enter edge to remove (u v): ";
  cin >> u >> v;
  removeEdge(u, v);

  cout << "Graph after removing edge: " << endl;
  printGraph();

  cout << "Inorder traversal of the graph: ";
  inorder(0);
  cout << endl;

  cout << "Preorder traversal of the graph: ";
  preorder(0);
  cout << endl;

  cout << "Postorder traversal of the graph: ";
  postorder(0);
  cout << endl;

  cout << "Max element of the graph: " << maxElement(0) << endl;
  cout << "Min element of the graph: " << minElement(0) << endl;

  cout << "Enter node for finding Successor: ";
  cin >> u;
  cout << "Successor of " << u << " is " << successor(u) << endl;

  cout << "Enter node for finding Predecessor: ";
  cin >> u;
  cout << "Predecessor of " << u << " is " << predecessor(u) << endl;

  cout << "Enter source node for Dijkstra: ";
  cin >> u;
  dijkstra(u);

  return 0;
}
