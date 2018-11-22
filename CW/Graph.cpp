#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

class Node{
    public:
        int value;
        bool visited = false;
        vector<Node*> edges;
    
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

        void addNode(){
            Node* temp = new Node(numOfNodes);  //num of nodes is the value, easy to keep track of
            nodes.push_back(temp);
            numOfNodes++;
        }

        void addEdge(int node1, int node2){
            int size = nodes.size();
            if(node1 > size-1 or node2 > size-1){
                if(node1 > node2){
                    for(int i = size-1; i < node1; i++) addNode();
                }
                else{
                    for(int i = size-1; i < node2; i++) addNode();
                }
            }
            nodes[node1]->edges.push_back(nodes[node2]); //pushing to the list within the node
            nodes[node2]->edges.push_back(nodes[node1]); //as undirected have to do for both nodes
        }

        void printGraph(){
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

        void depthFS(int);
        void breadthFS(int);
        void isPath(int, int);
};

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
            //if the edge to the current node isn't visited then add to 'toVisit'
            if(!visited[nodes[start]->edges[i]->value]) toVisit.push(nodes[start]->edges[i]->value);
        }
    }
    cout << endl;
}

int main(){

    Graph graph;

    graph.addNode();
    graph.addNode();
    graph.addNode();
    graph.addNode();

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);

    graph.printGraph();

    graph.depthFS(0);
    graph.breadthFS(0);
    //graph.breadthFS(2);

    return 0;
}