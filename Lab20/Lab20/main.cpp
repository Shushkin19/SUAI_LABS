#include"graph.h"

int main() {

	graph g;
	g.initialize_graph("graph1.txt");
	g.dfs(0);
	return 0;
}