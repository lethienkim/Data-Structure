/* ******************************************
 * File:   main.cpp
 * Author: Thienkim Le
 *
 * This file contains the main function for the program.
 * It seeds the random number generator, creates a graph object,
 * adds vertices and edges to the graph, performs various operations
 * to test the functionality of the graph, and prints the graph at different stages.
 ********************************************/


#include "main.h"
#include "graph.h"

int main() {
    srand(time(0));
    Graph graph;
	
	// Print the graph
	std::cout << "\n Randomly generate the graph: \n" << std::endl;
    
    // Add vertices
    for (int i = 0; i < BUFFERSIZE; ++i) {
        int vertexId = rand() % MAXID + 1;
        int vertexData = rand() % BASE;
        graph.addVertex(vertexId, vertexData);
    }

    // Add edges
    for (int i = 0; i < BUFFERSIZE * 2; ++i) {
        int src = rand() % MAXID + 1;
        int dest = rand() % MAXID + 1;
        graph.addEdge(src, dest);
    }

    // Print the graph
    graph.printGraph();
    // Get the count of vertices
    int count = graph.getCount();
    std::cout << "Number of vertices: " << count << std::endl;

    // Delete an edge
    int srcToDelete = rand() % MAXID + 1;
    int destToDelete = rand() % MAXID + 1;
    graph.deleteEdge(srcToDelete, destToDelete);

    // Delete a vertex
    int vertexToDelete = rand() % MAXID + 1;
    graph.deleteVertex(vertexToDelete);

    
    
    // Clear the graph
    graph.clearList();

    // Insert a vertex
    int vertexIdToInsert = rand() % MAXID + 1;
    int vertexDataToInsert = rand() % BASE;
    graph.insertVertex(vertexIdToInsert, vertexDataToInsert);

    // Insert an edge
    int srcToInsert = rand() % MAXID + 1;
    int destToInsert = rand() % MAXID + 1;
    graph.insertEdge(srcToInsert, destToInsert);

    

    return 0;
}
