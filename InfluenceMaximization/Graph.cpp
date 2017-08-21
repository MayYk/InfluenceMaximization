//
//  Graph.cpp
//  InfluenceMaximization
//
//  Created by Madhavan R.P on 8/4/17.
//  Copyright © 2017 Madhavan R.P. All rights reserved.
//

#include "Graph.hpp"
using namespace std;
void Graph::readGraph(string fileName) {
    ifstream myFile("graphs/graph_ic.inf");
    string s;
    if(myFile.is_open()) {
        myFile >> n >> m;
        for(int i =0;i<n;i++) {
            graph.push_back(vector<int>());
            visited.push_back(false);
            inDegree.push_back(0);
        }
        int from, to;
        int maxDegree = 0;
        double p = 0;
        while (myFile >> from >> to >> p) {
            graph[from].push_back(to);
            inDegree[to] = inDegree[to]+1;
            if(inDegree[to] > maxDegree) {
                maxDegree = inDegree[to];
            }
        }
        cout<<"\nMax degree is " << maxDegree;
        myFile.close();
    }
    graphTranspose = constructTranspose(graph);
    rrSets = vector<vector<int>>();
    visitMark = vector<int>(n);
    int R = 10000000;
    int totalSize = 0;
    clock_t begin = clock();
    for(int i=0;i<R;i++) {
        rrSets.push_back(vector<int>());
    }
    for(int i=0;i<R;i++) {
//        totalSize+=generateRandomRRSet(i).size();
        for(int j=0;i<4;j++) {
        }
        totalSize+=rrSets[i].size();
//        cout<<"Finished  " << i << "\n";
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout <<"\n Generated " << R << " RR sets\n";
    cout << "Elapsed time " << elapsed_secs;
    cout<< " \n Time per RR Set is " << elapsed_secs/R;
    cout<< "\n Total Size is " << totalSize;
    cout<<"\n Average size is " << (float)totalSize/(float)R;
    
}

vector<int> Graph::generateRandomRRSet(int rrSetID) {
    int randomVertex = rand() % n;
    vector<int> randomSet = rrSets[rrSetID];
    queue<int> empty;
    swap(q, empty);
    q.push(randomVertex);
    int nVisitMark = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(visited[u]) continue;
//        float p =(float)1/float(inDegree[u]);
        visited[u] = true;
        randomSet.push_back(u);
        visitMark.push_back(u);
        nVisitMark++;
        vector<int> edgesIn = graphTranspose[u];
        for(int i=0;i<edgesIn.size();i++) {
            int v = edgesIn[i];
            if(visited[v]) continue;
            int inD = inDegree[u];
            int coin = rand() % inD;
            if(coin==0) {
                q.push(v);
            }
        }
    }
    for(int i:visitMark) {
        visited[i] = false;
    }
    visitMark.clear();
    return randomSet;
    
}

vector<vector<int>> Graph::constructTranspose(vector<vector<int>> someGraph) {
    vector<vector<int>> transposedGraph = vector<vector<int>>();
    for(int i=0;i<someGraph.size();i++) {
        transposedGraph.push_back(vector<int>());
    }
    for(int i=0; i<someGraph.size();i++) {
        for(int v:someGraph[i]) {
            transposedGraph[v].push_back(i);
        }
    }
    return transposedGraph;
}
