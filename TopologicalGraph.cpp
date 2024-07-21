#include"TopologicalGraph.h"

TopologicalGraph::TopologicalGraph(int n, vector<vector<int>>&edges)
{
	this->num_of_node = n;
	this->adjs.resize(n);
	this->visited.resize(n);
	for (auto & edge:edges) {
		this->add_edge(edge);
	}
}

void TopologicalGraph::add_edge(vector<int>& edge)
{
	this->adjs[edge[0]].push_back(edge[1]);
}

void TopologicalGraph::topological_sort_util(int node)
{
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int adj : adjs[node]) {
		topological_sort_util(adj);
	}
	order.push_back(node);
}

vector<int> TopologicalGraph::topological_sort()
{
	for (int i = 0; i < this->num_of_node; i++) {
		if (!visited[i]) {
			topological_sort_util(i);
		}
	}
	vector<int>new_order;
	while (!order.empty()) {
		new_order.push_back(order.back());
		order.pop_back();
	}
	return new_order;
}

void TopologicalGraph::print_order(vector<int>&new_order)
{
	for (int node: new_order) {
		cout << node << "\t";
	}
	cout << endl;
}


