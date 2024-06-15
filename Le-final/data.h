/* ******************************************
 * File:   data.h
 * Author: Thienkim Le
 *
 * This file defines the GraphVertex struct, which represents a vertex in a graph.
 * Each vertex has an integer ID and associated data.
 ********************************************/

#ifndef DATA_H
#define DATA_H

struct GraphVertex {
    int id;
    int data;

    GraphVertex() : id(-1), data(0) {}
    GraphVertex(int _id, int _data) : id(_id), data(_data) {}
};

#endif // DATA_H