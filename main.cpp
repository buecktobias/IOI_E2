#include <iostream>
#include <vector>
// Number of vertices in the graph
using namespace std;

unsigned long minDistance(vector<unsigned short> dist, const bool sptSet[])
{
    // Initialize min value
    unsigned long min = INT32_MAX, min_index = 0;

    for (unsigned long v = 0; v < dist.size(); v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
vector<unsigned short> dijkstra(vector<vector<unsigned short>> graph, int src)
{
    int amountOfVertices = graph.size();
    vector<unsigned short> dist(amountOfVertices); // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[amountOfVertices]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < amountOfVertices; i++) {
        dist[i] = INT16_MAX;
        sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < amountOfVertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        unsigned long u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < amountOfVertices; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT16_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    return dist;
}

// driver program to test above function
int main()
{
    // input
    int amountOfTestCases;
    cin >> amountOfTestCases;
    for(int testCase= 0; testCase < amountOfTestCases;testCase++){
        int amountOfVertices;
        int amountOfEdges;
        int amountOfDestinations;
        cin >> amountOfVertices;
        cin >> amountOfEdges;
        cin >> amountOfDestinations;
        vector< vector<unsigned short> > adjacencyMatrix;
        adjacencyMatrix.resize(amountOfVertices , vector<unsigned short>(amountOfVertices ,INT16_MAX) );
        //edges
        for(int edgeCounter=0; edgeCounter < amountOfEdges; edgeCounter++){
            int vertex1;
            int vertex2;
            int cost;
            cin >> vertex1;
            cin >> vertex2;
            cin >> cost;
            vertex1--;
            vertex2--;
            adjacencyMatrix[vertex1][vertex2]= cost;
            adjacencyMatrix[vertex2][vertex1] = cost;
        }
        vector<int> destinations(amountOfDestinations);


        for(int i= 0; i < amountOfDestinations;i++){
            int destination;
            cin >> destination;
            destination--;
            destinations[i] = destination;
        }

        vector<unsigned short> distances = dijkstra(adjacencyMatrix, 0);


        vector<int> best_destinations;
        int shortest_distance=INT32_MAX;
        for(int destination : destinations){
            int distance = distances[destination];
            if(distance < shortest_distance){
                best_destinations.clear();
                best_destinations.push_back(destination);
                shortest_distance = distance;
            }else if(distance == shortest_distance){
                best_destinations.push_back(destination);
            }
        }

        cout << "Case #" << testCase+1 << ": " << shortest_distance << " ";
        for(int destination:best_destinations) cout << destination + 1 << " ";
        cout << endl;
    }
    return 0;
}
