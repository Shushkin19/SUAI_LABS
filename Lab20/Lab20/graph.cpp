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
	n++;
	g.resize(n);
	visited.resize(n);
	d.resize(n);
	l.resize(n);
	file.get();
	
	int ch;
	int vertex = 1;
	while (!file.eof()) {
		ch = file.get();
		if (ch == '\n') {
			vertex++;
		}
		else if (ch == ' ' || ch == EOF) {

		}
		else {
			g[vertex].push_back(ctoi(ch));
		}
	}


}

void graph::dfs(int v,int p) {

	visited[v] = true;
	d[v] = l[v] = ++timer;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p) {
			continue;
		}
		if (visited[to]) {
			l[v] = min(l[v], d[to]);
		}
		else {
			dfs(to, v);
			l[v] = min(l[v], l[to]);
			if (l[to] >= d[v] && p != -1){}
				//printf(" cycle point : %d \n ", v);
		}
	}
	//printf("\nvertex: %d\n", v);
	if (p == -1 && p == v){} // for root
		//printf(" cycle point : %d \n ", v);

	
	
}

void graph::vertex_list(string file) {
	fstream fl;
	fl.open(file, ios::out);
	for (int v = 1; v < n; v++) {
		visited.clear();
		visited.resize(n);
		dfs(v, -1);
		cout << "\nVertex: " << v << " vertex list => ";
		fl << v << ": ";
		for (int i = 1; i < n; i++) {
			if (visited[i] == true && i != v) {
				cout << i << " ";
				fl << " " << i;
			}
		}
		fl << endl;
		cout << endl;
	}
	fl.close();
}