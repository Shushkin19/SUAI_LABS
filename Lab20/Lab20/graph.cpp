#include "graph.h"
#include<fstream>
#include<iostream>


int graph::ctoi(char c) {
	return c -= '0';
}


graph::graph() {
	this->timer = 0;
	this->n = 0;
}

void graph::initialize_graph(string name) {
	fstream file;
	file.open(name);
	if (file.is_open() == 0) {
		cout << "error";
	}
	n = ctoi(file.get());
	
	g.resize(n);
	visited.resize(n);
	d.resize(n);
	l.resize(n);
	file.get();
	
	int ch;
	int vertex = 0;
	while (!file.eof()) {
		ch = file.get();
		if (ch == '\n') {
			vertex++;
		}
		else if (ch == ' ') {

		}
		else {
			g[vertex].push_back(ctoi(ch));
		}
	}


}

void graph::dfs(int v) {
	
	visited[v] = true;


	cout << v<< " ";


	for (int i = 0; i < g[v].size(); ++i)
		if (!visited[i])
			dfs(i);


	
	
}
