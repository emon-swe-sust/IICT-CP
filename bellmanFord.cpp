#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

void printArr(int dist[], int n, int parent[])
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("Node %d, Distance %d, Parent %d\n", i, dist[i], parent[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	int parent[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int from = graph->edge[j].src;
			int to = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
                dist[to] = dist[from] + weight;
				parent[to]=from;
            }
		}
	}

	for (int i = 0; i < E; i++) {
		int from = graph->edge[i].src;
		int to = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[from] != INT_MAX
			&& dist[from] + weight < dist[to]) {
			printf("Graph contains negative weight cycle");
			return;
		}
	}

	printArr(dist, V, parent);

	return;
}

int main()
{
	int V = 7;
	int E = 10;

    struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 6;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 5;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 4;
	graph->edge[3].weight = -1;

	graph->edge[4].src = 2;
	graph->edge[4].dest = 1;
	graph->edge[4].weight = -2;

	graph->edge[5].src = 2;
	graph->edge[5].dest = 4;
	graph->edge[5].weight = 1;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 2;
	graph->edge[6].weight = -2;

	graph->edge[7].src = 3;
	graph->edge[7].dest = 5;
	graph->edge[7].weight = -1;

	graph->edge[8].src = 4;
	graph->edge[8].dest = 6;
	graph->edge[8].weight = 3;

	graph->edge[9].src = 5;
	graph->edge[9].dest = 6;
	graph->edge[9].weight = 3;

	BellmanFord(graph, 0);

	return 0;
}
