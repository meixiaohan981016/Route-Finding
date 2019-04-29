#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

using namespace std;
	int count = -1;
	int count_point = -1;	
	
	//add a point object which has a latitude and longtitude and an id
	void Graph::addPoint(double latitude,double longtitude,int node,int count){
		point[count] = new Point(latitude, longtitude, node);
	}

    //add an edge which is from 'from' to 'to' and its length is 'len'
    void Graph::addEdge(int from, int to, double len){
    	head[from] = new Edge(to,len,head[from]);
    }

    Graph::Graph(int _n = 0){
        n = _n;
        for(int i = 0; i < _n; ++i){
            head[i] = NULL;
        }
    }

    void Graph::init(int _n){
        n = _n;
        for(int i = 0; i < _n; ++i){
            head[i] = NULL;
        }
    }

   
    //dikstra algorithm to compute out the shortest route from S to T
    double Graph::dijkstra(int S, int T){
        for(int i = 0; i < n; ++i){
            dis[i] = -1;
            way[i] = -1;
        }
        
        dis[S] = 0;
        way[S] = S;
        
        //priority queue, pop out the point which is closest to S
        //relax other start point
        priority_queue<pair<double,int> >q;
        //put the start Point S into the queue
        q.push( make_pair(0,S) );
        while( !q.empty() ){
            int u = q.top().second;
            double d = -q.top().first;
            //pop out the top of the queue
            q.pop();
            //traverse the edge of this point and perform the relaxation procedure
            for(Edge* i = head[u]; i != NULL; i = i->nxt){
                int to = i->to;
				double len = i->len;
                //if the new point has not been visited, upgrade the distance
                //put this point into the queue
                if(dis[to] == -1 || (dis[to] != -1 && dis[u] + len < dis[to]) ){
                    dis[to] = dis[u] + len;
                    way[to] = u;//the way[to] stores the from point id in the best route
                    q.push( make_pair(-dis[to],to) );
                }
            }
        }
        return dis[T];
    }

