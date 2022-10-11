#pragma once
#include"edgenode.h"
#include<vector>
#include<string>

using namespace std;

class graph
{
	int n;
	vector<vector<int>> g;
	vector<bool> visited;
	vector<int> d, l;
	int timer;


	int ctoi(char c);
public:
	graph();
	void initialize_graph(string name);
	void dfs(int v);

};

