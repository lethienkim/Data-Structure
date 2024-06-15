/* ******************************************
 * File:   graph.h
 * Author: Thienkim Le
 *
 * This file defines the Graph class, which represents a graph data structure.
 * The graph is implemented using an adjacency list representation.
********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"

#include <vector>
#include <iostream>
#include <unordered_map>	
#include <algorithm> // For std::find

class Graph {
private:
	// Adjacency list representation of the graph
    std::unordered_map<int, std::vector<int>> adjacencyList;
    std::unordered_map<int, GraphVertex> vertices;
    int count; // Declaration of count variable
    int num;

public:
	/**********************
     * Constructors/Destructor
    **********************/
    Graph();
    ~Graph();

    /**********************
     * Getters/Accessors
    **********************/
	int getCount();
	int getNum();

    /**********************
     * Setters/Mutators
    **********************/
    void addVertex(int, int);
    void addEdge(int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);

	void clearList();
    void printGraph();
};

#endif // GRAPH_H
