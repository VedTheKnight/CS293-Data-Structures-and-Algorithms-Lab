#include "graph.cpp"


void shortest_walk(Graph g,vector<int>&stations, vector<int>& path)
{
    //for each node in stations we will execute bfs on that node. use this information to get the path from ith station to i+1th station
    for(int i=0; i< stations.size()-1; i++){
        unordered_map<int, int> parents;
        bfs(g,stations[i],parents);       
        //now that parents has the required path we push it into out result vector
        int j=stations[i+1];
        vector<int> temp;
        while(j!=stations[i]){
            j = parents[j];
            temp.push_back(j);
        }
        //now we copy this into the path
        for(int i = temp.size()-1; i>=0; i--){
            path.push_back(temp[i]);
        }
    }
    path.push_back(stations[stations.size()-1]);
    return;
}
