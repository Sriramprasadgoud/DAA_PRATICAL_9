#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

int main()
{
    int n, e;
    int graph[MAX][MAX];
    int visited[MAX];
    int parent[MAX];
    int key[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n >= MAX)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    if (e < 0)
    {
        cout << "Invalid number of edges!";
        return 0;
    }

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }

        graph[i][i] = 0;
        visited[i] = 0;
        key[i] = INF;
        parent[i] = -1;
    }

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            cout << "Invalid edge!";
            return 0;
        }

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start;

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n)
    {
        cout << "Invalid starting vertex!";
        return 0;
    }

    key[start] = 0;

    // Prim's Algorithm
    for (int count = 0; count < n; count++)
    {
        int min = INF;
        int u = -1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        if (u == -1)
        {
            cout << "Graph is disconnected. MST cannot be formed.\n";
            return 0;
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            cout << parent[i] << " - " << i
                 << " : " << key[i] << endl;

            totalCost += key[i];
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;

    return 0;
}
