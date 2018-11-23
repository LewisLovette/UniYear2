#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

class Node{
    public:
        int value;
        bool visited = false;
        vector<Node*> edges;
        vector<int> weight; //position of edge gives weight here

    Node(int value){
        this->value = value;
    }
};

/*
class Edge{
    public:
        
        Edge(Node* newEdge){
            
        }
};
*/

class Graph{
    public:
        int numOfNodes = 0;
        vector<Node*> nodes;

        Graph(){

        }

        void addNode();
        void addEdge(int, int, int);    //node1, node2, weight
        void printGraph();
        void depthFS(int);
        void breadthFS(int);
        void isPath(int, int);
        void isConnected(int);
        void Dijkstra(int, int);

};

void Graph::addNode(){
    Node* temp = new Node(numOfNodes);  //num of nodes is the value, easy to keep track of
    nodes.push_back(temp);
    numOfNodes++;
}

void Graph::addEdge(int node1, int node2, int weight){
            int size = nodes.size();
            if(node1 > size-1 or node2 > size-1){
                if(node1 > node2){
                    for(int i = size-1; i < node1; i++) addNode();
                }
                else{
                    for(int i = size-1; i < node2; i++) addNode();
                }
            }
            //adding to edge vector
            nodes[node1]->edges.push_back(nodes[node2]); //pushing to the list within the node
            nodes[node2]->edges.push_back(nodes[node1]); //as undirected have to do for both nodes

            //adding weight to same position
            nodes[node1]->weight.push_back(weight); //pushing to the list within the node
            nodes[node2]->weight.push_back(weight); //as undirected have to do for both nodes

        }

void Graph::printGraph(){
            int count, size;
            
            for(int i = 0; i < nodes.size(); i++){
                size = nodes[i]->edges.size();
                cout << nodes[i]->value << " connects to : ";
                for(int j = 0; j < size; j++){
                    cout << nodes[i]->edges[j]->value << " ";
                }
                cout << endl;
            }
        }

void Graph::depthFS(int start){
    vector<int> toVisit;
    bool visited[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visited[i] = false;   //setting visisted to false

    toVisit.push_back(start);

    cout << "Depth First Search: ";
    while(!toVisit.empty()){
        //cout << "while loop test" << endl;
        start = toVisit.back();
        toVisit.pop_back();
        
        if(!visited[start]){    //if false then we haven't visited
            cout << start << " ";   //cout as this is the order we visited
            visited[start] = true;  //so set it to true
        }

        for(int i = 0; i < nodes[start]->edges.size(); i++){
            //cout << "size test" << endl;
            //if the edge to the current node isn't visited then go then add to 'toVisit'
            if(!visited[nodes[start]->edges[i]->value]) toVisit.push_back(nodes[start]->edges[i]->value);
        }
    }
    cout << endl;
}

void Graph::breadthFS(int start){
    queue<int> toVisit;
    bool visited[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visited[i] = false;   //setting visisted to false

    toVisit.push(start);

    cout << "Breadth First Search: ";
    while(!toVisit.empty()){
        //cout << "while loop test" << endl;
        start = toVisit.front();
        toVisit.pop();
        
        if(!visited[start]){    //if false then we haven't visited
            cout << start << " ";   //cout as this is the order we visited
            visited[start] = true;  //so set it to true
        }

        for(int i = 0; i < nodes[start]->edges.size(); i++){
            //cout << "size test" << endl;
            //if the edge to the current node isn't visited then go then add to 'toVisit'
            if(!visited[nodes[start]->edges[i]->value]) toVisit.push(nodes[start]->edges[i]->value);
        }
    }
    cout << endl;
}

void Graph::isPath(int start, int end){
    int startCopy = start;
    queue<int> toVisit;
    bool visited[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visited[i] = false;   //setting visisted to false

    //keep track of the position we visited from - index is node, value is from.
    int visitedFrom[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visitedFrom[i] = -1;  //set to -1 means we haven't visited from anywhere

    toVisit.push(start);

    while(!toVisit.empty()){
        start = toVisit.front();
        toVisit.pop();
        
        if(!visited[start]){    //if false then we haven't visited
            visited[start] = true;  //so set it to true
        }

        for(int i = 0; i < nodes[start]->edges.size(); i++){
            //cout << "size test" << endl;
            //if the edge to the current node isn't visited then add to 'toVisit'
            if(!visited[nodes[start]->edges[i]->value]){
                toVisit.push(nodes[start]->edges[i]->value);
                //add start to the new edges - to keep track of where the search came from
                visitedFrom[nodes[start]->edges[i]->value] = start;
            }
        }

        if(start == end) break;
    }
    
    //Printing the path if there is one
    cout << "Is Path from " << startCopy << " to " << end << " ? ";
    if(visitedFrom[end] != -1){
        cout << "YES: " << end << " "; //printing 

        for(int i = end; visitedFrom[end] != -1; i++){
            cout << visitedFrom[end] << " ";
            end = visitedFrom[end];
        }
    }
    else{
        cout << "NO";
    }
    cout << endl;
}

void Graph::isConnected(int start){
    int startCopy = start;
    queue<int> toVisit;
    bool visited[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visited[i] = false;   //setting visisted to false

    //keep track of the position we visited from - index is node, value is from.
    int visitedFrom[nodes.size()];
    for(int i = 0; i < nodes.size(); i++) visitedFrom[i] = -1;  //set to -1 means we haven't visited from anywhere

    toVisit.push(start);

    while(!toVisit.empty()){
        start = toVisit.front();
        toVisit.pop();
        
        if(!visited[start]){    //if false then we haven't visited
            visited[start] = true;  //so set it to true
        }

        for(int i = 0; i < nodes[start]->edges.size(); i++){
            //cout << "size test" << endl;
            //if the edge to the current node isn't visited then add to 'toVisit'
            if(!visited[nodes[start]->edges[i]->value]){
                toVisit.push(nodes[start]->edges[i]->value);
                //add start to the new edges - to keep track of where the search came from
                visitedFrom[nodes[start]->edges[i]->value] = start;
            }
        }

    }
    
    //Printing the path if there is one
    cout << "Is the graph Strongly Connected? ";
    for(int i = 0; i < nodes.size(); i++){
        if(visitedFrom[i] == -1 and i != startCopy){
            cout << "NO";
            break;
        }
        if(i == nodes.size()-1){
            cout << "YES";
        }
    }
    cout << endl;
}

void Graph::Dijkstra(int start, int end){
    int smallestDist, track, alt, endCopy = end;
    Node* currentNode;
    vector<int> dist;
    int previous[nodes.size()];
    bool distVisited[nodes.size()];

    //cout << "Test 1" << endl;

    for(int i = 0; i < nodes.size(); i++){
        dist.push_back(INT_MAX);  //set all distances to infinity.
        distVisited[i] = false;
    }
    dist[start] = 0;    //as the node from itself to itself is 0
    
    vector<Node*> queue = nodes;    //copy of nodes
    
    //cout << "Test 1.5" << endl;

    while(!queue.empty()){
        //cout << "Test 2" << endl;
        smallestDist = INT_MAX;   //set to front so we can search for the smallest node
        /*
        for(int i = 0; i < queue.size(); i++) cout << dist[queue[i]->value] << " ";
        cout << endl;
        */
        for(int i = 0; i < queue.size(); i++){
            if(dist[queue[i]->value] < smallestDist and distVisited[queue[i]->value] != true){ //find smallest distance from correlating node
                smallestDist = dist[queue[i]->value];
                track = i;
                //track = queue[i]->value;
            }
        }

        currentNode = queue[track];
        /*
        cout << "Track: " << track << endl;
        cout << "Current Node: " << currentNode->value << endl;
        */
        distVisited[currentNode->value] = true;  //keeping track of nodes we've visited
        /*
        cout << "Queue: ";
        for(int i = 0; i < queue.size(); i++) cout << queue[i]->value << " ";
        cout << endl;

        cout << "DistList: ";
        for(int i = 0; i < nodes.size(); i++) cout << dist[i] << " ";
        cout << endl;
        */
        queue.erase(queue.begin()+track);

        //cout << "Test 2.5" << endl;

        for(int i = 0; i < currentNode->edges.size(); i++){ //stepping through neighbour nodes
            //cout << "Test 3" << endl;
            alt = dist[currentNode->value] + currentNode->weight[i];

            if(alt < dist[currentNode->edges[i]->value]){   //if alt is less than the position of the neighbour.
                dist[currentNode->edges[i]->value] = alt;
                previous[currentNode->edges[i]->value] = currentNode->value;
            }
        }
    }

    //Printing path and weight
    cout << "Djisktra: " << end << " ";
    for(int i = end; previous[endCopy] != start; i++){
        cout << previous[endCopy] << " ";
        endCopy = previous[endCopy];
    }
    cout << start << endl;
    cout << "Weight = " << dist[end] << endl;

    //Printing all
    for(int i = 0; i < nodes.size(); i++){
        cout << "Node: " << i << "  Prev: " << previous[i] << "  Visited: "; 
        cout << distVisited[i] << "  Weight: " << dist[i] << endl;
    }

}



int main(){

    Graph graph;

    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();    //9 nodes

    graph.addEdge(0, 2, 10);
    graph.addEdge(0, 1, 20);
    graph.addEdge(1, 3, 10);
    graph.addEdge(2, 4, 20);
    graph.addEdge(4, 6, 20);
    graph.addEdge(3, 5, 30);
    graph.addEdge(3, 7, 30);
    graph.addEdge(7, 8, 20);
    graph.addEdge(5, 6, 0);
    graph.addEdge(5, 8, 10);
    graph.addEdge(6, 8, 20);

    //testing isConnected();
    //graph.addEdge(5, 4);  //makes the graph strongly connected

    graph.printGraph();

    graph.depthFS(0);
    graph.breadthFS(0);
    
    graph.isPath(0, 3);
    graph.isConnected(0);
    
    //graph.Dijkstra(4, 8);

    int temp, temp2;
    while(true){
        cin >> temp;
        cin >> temp2;
        graph.Dijkstra(temp, temp2);
        cout << endl;
    }
    

    return 0;
}