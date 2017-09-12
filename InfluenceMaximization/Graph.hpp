//
//  Graph.hpp
//  InfluenceMaximization
//
//  Created by Madhavan R.P on 8/4/17.
//  Copyright © 2017 Madhavan R.P. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <ctime>
#include <deque>
#include <string.h>
using namespace std;

class Graph {
public:
    int n, m;
    vector<vector<int> > graph;
    vector<vector<int> > graphTranspose;
    vector<vector<int>> rrSets;
    vector<bool> labels;
    vector<int> nonTargets;
    deque<int> q;
    vector<int> inDegree;
    vector<bool> visited;
    vector<int> visitMark;
    void readGraph(string fileName);
    void readLabels(string fileName);
    vector<vector<int> > constructTranspose(vector<vector<int> > aGraph);
    void generateRandomRRSets(int R, bool label);
    vector<int> generateRandomRRSet(int randomVertex, int rrSetID);
    void clearRandomRRSets();
    vector<vector<int>> getRandomRRSets();
};

#endif /* Graph_hpp */



