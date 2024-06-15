/* ******************************************
 * File:   graph.cpp
 * Author: Thienkim Le
 *
 * The Graph class represents an undirected graph using an adjacency list data structure.
 * It provides methods to add vertices and edges, delete vertices and edges,
 * get the count of vertices, clear the graph, insert vertices and edges,
 * and print the graph in the form of an adjacency list.
 ********************************************/


#include "graph.h"

Graph::Graph() {
	/**********************
     * Constructor for the Graph class.
    **********************/
	count = 0;
}

Graph::~Graph() {
	/**********************
     * Destructor for the Graph class.
	**********************/
}

void Graph::addVertex(int id, int data) {
	/*******************************
	 * This function adds a vertex to the graph.
	 * If the vertex with the given ID does not already exist in the graph,
	 * it creates a new vertex with the provided ID and data, and adds it to the adjacency list.
	 * If the vertex already exists, it prints a message indicating that the vertex already exists.
	 * After adding a new vertex, it increments the count of vertices in the graph.
	 * @param id: The ID of the vertex to be added.
	 * @param data: The data associated with the vertex.
	 *******************************/
    if (adjacencyList.find(id) == adjacencyList.end()) {
        adjacencyList[id] = std::vector<int>();
        std::cout << "Vertex " << id << " has added." << std::endl;
        count++;
    } else {
        std::cout << "Vertex " << id << " already exists." << std::endl;
    }
}

void Graph::addEdge(int src, int dest) {
	/*********************************************
	 * Adds an edge between two vertices in the graph.
	 * Checks if the source and destination vertices are the same.
	 * If an edge between the vertices already exists, prints a message and returns.
	 * Otherwise, adds the edge to the adjacency list for both vertices and prints a confirmation message.
	 * @param src: The ID of the source vertex.
	 * @param dest: The ID of the destination vertex.
	 *********************************************/
    if (src == dest) {
        std::cout << "A vertex " << src << " cannot connect to itself." << std::endl;
    } else {
        bool srcExists = false;
        bool destExists = false;
        
        // Check if source vertex exists
        if (adjacencyList.find(src) != adjacencyList.end()) {
            srcExists = true;
        } else {
            std::cout << "Source vertex " << src << " does not exist." << std::endl;
        }
        
        // Check if destination vertex exists
        if (adjacencyList.find(dest) != adjacencyList.end()) {
            destExists = true;
        } else {
            std::cout << "Destination vertex " << dest << " does not exist." << std::endl;
        }
        
        // If both vertices exist, add the edge
        if (srcExists && destExists) {
            // Check if the edge already exists
            for (int neighbor : adjacencyList[src]) {
                if (neighbor == dest) {
                    std::cout << "Edge " << src << "-" << dest << " already exists." << std::endl;
                    return;
                }
            }
            
            // Add the edge
            adjacencyList[src].push_back(dest);
            adjacencyList[dest].push_back(src);
            std::cout << "Edge " << src << "-"<< dest << " has added." << std::endl;
            num++;
        }
    }
}

void Graph::deleteVertex(int id) {
	/**************************************************************
	 * This function deletes the vertex with the given ID from the graph.
	 * If the vertex does not exist, it prints an error message and returns.
	 * It removes all edges associated with the vertex and then removes the vertex's entry from the adjacency list.
	 * 
	 * @param id: The ID of the vertex to delete.
	 **************************************************************/
    if (adjacencyList.find(id) == adjacencyList.end()) {
        std::cout << "Vertex " << id << " does not exist." << std::endl;
        return;
    }

    // Remove all edges associated with the vertex
    for (auto& pair : adjacencyList) {
        auto& neighbors = pair.second;
        auto it = std::find(neighbors.begin(), neighbors.end(), id);
        if (it != neighbors.end()) {
            neighbors.erase(it);
        }
    }

    // Remove the vertex's entry in the adjacency list
    adjacencyList.erase(id);
    std::cout << "Vertex " << id<<" has removed." << std::endl;
    count--;
}

void Graph::deleteEdge(int src, int dest) {
	/*****************************************
 	* Deletes the edge between two vertices in the graph.
 	* Checks if both source and destination vertices exist.
 	* If the edge exists, it is removed from the adjacency list of both vertices.
 	* If the edge does not exist, an appropriate message is printed.
 	* @param src: The source vertex.
 	* @param dest: The destination vertex.
 	*****************************************/
    // Check if both src and dest vertices exist
    if (adjacencyList.find(src) == adjacencyList.end() ||adjacencyList.find(dest) == adjacencyList.end()) {
        std::cout << "Edge " << src<< "-" << dest<< " do not exist." << std::endl;
        return;
    }

    auto& neighbors = adjacencyList[src];
    auto it = std::find(neighbors.begin(), neighbors.end(), dest);
    if (it != neighbors.end()) {
        neighbors.erase(it);
        num--;
        std::cout << "Edge " << src << "-" << dest << " has erased." << std::endl;
    } else {
        std::cout << "Edge " << src <<"-" << dest << " does not exist." << std::endl;
    }

    auto& destNeighbors = adjacencyList[dest];
    it = std::find(destNeighbors.begin(), destNeighbors.end(), src);
    if (it != destNeighbors.end()) {
        destNeighbors.erase(it);
        num--;
    }
}

void Graph::printGraph() {
	/*****************************************
 	* Prints the adjacency list representation of the graph.
 	* For each vertex, prints the vertex ID and its adjacent vertices.
	*****************************************/
    for (auto& pair : adjacencyList) {
        int src = pair.first;
        std::cout << "Vertex " << src << " -->:";
        for (int dest : pair.second) {
            std::cout << " " << dest;
        }
        std::cout << std::endl;
    }
}

int Graph::getCount() {
	/**************************
 	* Get the count of vertices in the graph.
 	* Returns the number of vertices currently present in the graph.
 	* @return The count of vertices.
 	**************************/
    return count;
}

int Graph::getNum() {
	/**************************
 	* Get the count of edges in the graph.
 	* Returns the number of edges currently present in the graph.
 	* @return The count of edges.
 	**************************/
    return num;
}
void Graph::clearList() {
	/**********************
 	* Clears the adjacency list of the graph.
	* Removes all vertices and edges from the graph by clearing the adjacency list.
 	**********************/
    adjacencyList.clear();
    
}

