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
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm> // For std::find

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjacencyList;
    std::unordered_map<int, GraphVertex> vertices;

public:
    Graph();
    ~Graph();
    void addVertex(int id, int data);
    void addEdge(int src, int dest);
    void deleteEdge(int src, int dest);
    void deleteVertex(int id);
    int getCount();
    void clearList();
    void insertVertex(int id, int data);
    void insertEdge(int src, int dest);
    void printGraph();
};

#endif // GRAPH_H
