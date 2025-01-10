#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define INF 1000000

// Structure for an edge
typedef struct {
    int src, dest;
    double weight;
} Edge;

// Structure for a graph
typedef struct {
    int vertices, edges;
    Edge edge[MAX];
} Graph;

// Structure for subsets (for union-find)
typedef struct {
    int parent;
    int rank;
} Subset;

// Function prototypes
void initializeGraph(Graph* graph, int vertices, int edges);
void addEdge(Graph* graph, int src, int dest, double weight);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskalMST(Graph* graph);

int main() {
    int vertices = 4;  // Number of documents (nodes)
    int edges = 6;     // Number of edges (similarity scores)
    
    Graph graph;
    initializeGraph(&graph, vertices, edges);

    // Similarity scores (example values)
    addEdge(&graph, 0, 1, 0.8);
    addEdge(&graph, 0, 2, 0.6);
    addEdge(&graph, 0, 3, 0.7);
    addEdge(&graph, 1, 2, 0.9);
    addEdge(&graph, 1, 3, 0.4);
    addEdge(&graph, 2, 3, 0.5);

    printf("Original Graph Edges with Weights:\n");
    for (int i = 0; i < graph.edges; i++) {
        printf("Edge (%d, %d): %.2lf\n", graph.edge[i].src, graph.edge[i].dest, graph.edge[i].weight);
    }

    // Apply Kruskal's algorithm
    printf("\nMinimum Spanning Tree (MST):\n");
    kruskalMST(&graph);

    return 0;
}

// Initialize graph
void initializeGraph(Graph* graph, int vertices, int edges) {
    graph->vertices = vertices;
    graph->edges = edges;
}

// Add edge to graph
void addEdge(Graph* graph, int src, int dest, double weight) {
    static int index = 0;  // Keep track of the current edge index
    graph->edge[index].src = src;
    graph->edge[index].dest = dest;
    graph->edge[index].weight = weight;
    index++;
}

// Find function for union-find (with path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function for union-find
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return (edgeA->weight > edgeB->weight) - (edgeA->weight < edgeB->weight);
}

// Kruskal's algorithm for MST
void kruskalMST(Graph* graph) {
    int vertices = graph->vertices;
    Edge result[MAX];  // To store the resulting MST
    int e = 0;         // Index for result[]
    int i = 0;         // Index for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(vertices * sizeof(Subset));
    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges in MST will be vertices - 1
    while (e < vertices - 1 && i < graph->edges) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle.
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result
    for (i = 0; i < e; i++) {
        printf("Edge (%d, %d): %.2lf\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}
