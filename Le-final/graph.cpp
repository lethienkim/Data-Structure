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

Graph::Graph() {}

Graph::~Graph() {}

void Graph::addVertex(int id, int data) {
    if (vertices.find(id) == vertices.end()) {
        vertices[id] = GraphVertex(id, data);
        std::cout << "Vertex with ID " << id << " has added." << std::endl;
    } else {
        std::cout << "Vertex with ID " << id << " already exists." << std::endl;
    }
}

void Graph::addEdge(int src, int dest) {
    if (src == dest) {
        std::cout << "A vertex " << src << " cannot connect to itself." << std::endl;
        return;
    }

    for (int neighbor : adjacencyList[src]) {
        if (neighbor == dest) {
            std::cout << "Edge between " << src << " and " << dest << " already exists." << std::endl;
            return;
        }
    }
    
    adjacencyList[src].push_back(dest);
    adjacencyList[dest].push_back(src);
}

void Graph::deleteEdge(int src, int dest) {
    // Check if both src and dest vertices exist
    if (vertices.find(src) == vertices.end() || vertices.find(dest) == vertices.end()) {
        std::cout << "One or both of the vertices" << src<< "and" << dest<< """ do not exist." << std::endl;
        return;
    }

    auto& neighbors = adjacencyList[src];
    auto it = std::find(neighbors.begin(), neighbors.end(), dest);
    if (it != neighbors.end()) {
        neighbors.erase(it);
        std::cout << "Edge between " << src << " and " << dest << " has just erased." << std::endl;
    } else {
        std::cout << "Edge between " << src << " and " << dest << " does not exist." << std::endl;
    }

    auto& destNeighbors = adjacencyList[dest];
    it = std::find(destNeighbors.begin(), destNeighbors.end(), src);
    if (it != destNeighbors.end()) {
        destNeighbors.erase(it);
    }
}

void Graph::deleteVertex(int id) {
    // Check if the vertex exists
    if (vertices.find(id) == vertices.end()) {
        std::cout << "Vertex with ID " << id << " does not exist." << std::endl;
        return;
    }

    // Remove the vertex from the vertices map
    vertices.erase(id);

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
}

int Graph::getCount() {
    return vertices.size();
}

void Graph::clearList() {
    vertices.clear();
    adjacencyList.clear();
}

void Graph::insertVertex(int id, int data) {
    // Check if the vertex already exists
    if (vertices.find(id) != vertices.end()) {
        std::cout << "Vertex with ID " << id << " already exists." << std::endl;
        return;
    }

    // Add the vertex to the vertices map
    vertices[id] = GraphVertex(id, data);
}

void Graph::insertEdge(int src, int dest) {
    // Check if both src and dest vertices exist
    if (vertices.find(src) == vertices.end() || vertices.find(dest) == vertices.end()) {
        std::cout << "One or both of the vertices do not exist." << std::endl;
        return;
    }

    // Check if the edge already exists
    for (int neighbor : adjacencyList[src]) {
        if (neighbor == dest) {
            std::cout << "Edge between " << src << " and " << dest << " already exists." << std::endl;
            return;
        }
    }

    // Add the edge to the adjacency list
    adjacencyList[src].push_back(dest);
    adjacencyList[dest].push_back(src);
}


void Graph::printGraph() {
    std::cout << "\n Graph represented as an adjacency list:" << std::endl;
    for (auto& pair : adjacencyList) {
        int src = pair.first;
        std::cout << "Vertex " << src << " is connected to:";
        for (int dest : pair.second) {
            std::cout << " " << dest;
        }
        std::cout << std::endl;
    }
}