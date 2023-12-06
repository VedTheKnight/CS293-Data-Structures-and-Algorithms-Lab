#include<unordered_map>
#include<vector>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

// Implement a node struct if you feel 


// Implement the graph class
class Graph
{
  public:
        int vertices;                 //these are public variables for our graph
        vector<pair<int,int>> edges_public;
        Graph(int no_of_vertices, vector<pair<int,int>> edges){
          //this is the constructor 
          vertices = no_of_vertices;
          edges_public = edges;
          return;
        };
};


void bfs(Graph g, int source,unordered_map<int, int>& parent)
{ 
  //we want to maintain a queue 
  queue<int> Q;
  //keep track of visited elements
  vector<int> visited;
  visited.push_back(source);
  //push the source onto the queue
  Q.push(source);
  parent.insert(make_pair(source,-1));

  vector<pair<int,int>> edges = g.edges_public; //get the edge set

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    //we now need to process v so we first get the list of neighbours of v
    vector<int> neighbours;
    for(int i=0; i < edges.size(); i++){
      if(edges[i].first==v){
        neighbours.push_back(edges[i].second); //find v and push its neighbour into the vector
      }
      if(edges[i].second==v){ //if it is written in the second part 
        neighbours.push_back(edges[i].first);
      }
    }

    for(int i=0; i< neighbours.size(); i++){
      int flag = 0; //to denote visited or not
      for(int j = 0; j<visited.size(); j++){ // checks if this neighbouring node is already visited
        if(neighbours[i]==visited[j]){        // if yes then sets the flag to 1 and goes to the next neighbour
          flag = 1;
          break;
        }
      }
      // now if not visited i.e. flag is 0
      if(flag == 0){
        parent.insert(make_pair(neighbours[i],v));  //we add the pair to the map
        visited.push_back(neighbours[i]); //we add the node to set of visited nodes
        Q.push(neighbours[i]); //we add it to the queue for processing
      } 
    }
  }
  return;
};

