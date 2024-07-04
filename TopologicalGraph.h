#pragma once
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class TopologicalGraph {
private:
	int num_of_node;
	vector<vector<int>>adjs;
	vector<bool>visited;
	vector<int>order;

public:
	TopologicalGraph(int, vector<vector<int>>&);
	void add_edge(vector<int>& edge);
	void topological_sort_util(int);
	vector<int>topological_sort();
	void print_order(vector<int>&);
};