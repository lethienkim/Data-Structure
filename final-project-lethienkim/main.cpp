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


int main() {
    srand(time(0));
    Graph graph;
	
	/***********************
	* Main function to nitializes a Graph object 
	* generates a random graph
 	* Prints the generated graph.
 	**********************/
 	std::cout <<"-------------------------"<< std::endl;	
	std::cout << "   Generate the graph"<< std::endl;	
	std::cout <<"-------------------------"<< std::endl;	
    
    std::vector<int> vertexList;
    
    // Add vertices to the graph
    std::cout <<"\n Randomly add the verteices:"<< std::endl;
	for (int i = 0; i < MINID; ++i) {
	    int vertexId = rand() %MINID + 1; 	// Generate a random vertex ID
	    int vertexData = rand() % MINID; 	// Generate random vertex data
	    vertexList.push_back(vertexId); 	// Add vertex ID to the list
	    graph.addVertex(vertexId, vertexData); // Add vertex to the graph
	}
	std::cout <<"\n    - - - - - - - - -"<< std::endl;	
	// Add edges to the graph
	std::cout <<"\n Randomly add the edges:"<< std::endl;
	for (int i = 0; i <MINID * 2; ++i) {
	    int src = vertexList[rand() % vertexList.size()]; // Select random source vertex
	    int dest = vertexList[rand() % vertexList.size()]; // Select random destination vertex
	    graph.addEdge(src, dest); 	// Add edge between source and destination vertices
	}

	std::cout <<"    - - - - - - - - -"<< std::endl;
	std::cout << " Graph represented as an adjacency list:\n" << std::endl;

	std::cout << " Number of vertices: " << graph.getCount() << std::endl;
	std::cout << " Number of edges: " << graph.getNum()<< std::endl;
    std::cout <<" "<<std::endl;
	graph.printGraph(); // Print the graph
    
	std::cout <<"\n---------------------------"<< std::endl;			
	std::cout <<"Randomly modify the graph"<< std::endl;
	std::cout <<"---------------------------"<< std::endl;	
		
	// Perform vertex insertion
	std::cout << " Insert a vertex: "<<  std::endl;
	int vertexIdToInsert = rand() % MINID + 1;	// Generate a random vertex ID and data
	int vertexDataToInsert = rand() % MINID;
	vertexList.push_back(vertexIdToInsert);	// Add the new vertex to the list
	graph.addVertex(vertexIdToInsert, vertexDataToInsert);	// Insert the new vertex into the graph
				
	// Perform vertex deletion
	std::cout << " Delete a vertex: " << std::endl;
	int vertexToDelete = vertexList[rand() % vertexList.size()];	// Select a random vertex to delete
	graph.deleteVertex(vertexToDelete);
	
	// Perform edge insertion
	std::cout << " Insert an edge: "<< std::endl;
	int srcToInsert = vertexList[rand() % vertexList.size()];	// Select random source and destination vertices
	int destToInsert = vertexList[rand() % vertexList.size()];
	graph.addEdge(srcToInsert, destToInsert);		// Add an edge between the selected vertices
	
	// Perform edge deletion
	std::cout << " Delete an edge: "<< std::endl;
	int srcToDelete = vertexList[rand() % vertexList.size()];	// Select random source and destination vertices
	int destToDelete = vertexList[rand() % vertexList.size()];
	graph.deleteEdge(srcToDelete, destToDelete);	// Remove the edge between the selected vertices

	std::cout <<"    - - - - - - - - -"<< std::endl;	
	// Print the graph
	std::cout << " Graph after modified: \n" << std::endl;
	std::cout << " Number of vertices: " <<graph.getCount() << std::endl; 
	std::cout << " Number of edges: " << graph.getNum()<< std::endl;
	std::cout <<" "<<std::endl;	
    graph.printGraph();
    	
	std::cout <<"--------------------------------------------------"<< std::endl;	
	std::cout <<" Add more the Verteices and Edges to exist graph"<< std::endl;
	std::cout <<"--------------------------------------------------"<< std::endl;	
	
	// Add vertices to the graph
	std::cout <<"\n Randomly add more vertices:"<< std::endl;
	for (int i = 0; i < MAXID; ++i) {
	    int vertexId = rand() % MAXID + 1; // Generate a random vertex ID
	    int vertexData = rand() % MAXID; // Generate random vertex data
	    vertexList.push_back(vertexId); // Add vertex ID to the list
	    graph.addVertex(vertexId, vertexData); // Add vertex to the graph
	}
	
	std::cout <<"    - - - - - - - - -"<< std::endl;   	
	// Add edges to the graph
	std::cout <<" Randomly add more the edges:\n"<< std::endl;
	for (int i = 0; i < MAXID * 2; ++i) {
	    int src = vertexList[rand() % vertexList.size()]; // Select random source vertex
	    int dest = vertexList[rand() % vertexList.size()]; // Select random destination vertex
	    graph.addEdge(src, dest); // Add edge between source and destination vertices
	}

	std::cout <<"    - - - - - - - - -"<< std::endl;
	// Print the graph
	std::cout << " Print the extending graph:\n" << std::endl;
    graph.printGraph();
		
	// Clear the graph
	std::cout << "\n Clear the graph." << std::endl;
    graph.clearList();

	// Print the graph
	std::cout << "\n Graph is empty now" << std::endl;
    graph.printGraph();
    std::cout <<"------------------------------------------------------------------"<< std::endl;
	std::cout <<"  That was such a great semester. Thank you for everthing."<< std::endl;	
    std::cout <<"------------------------------------------------------------------"<< std::endl;
    return 0;
}
