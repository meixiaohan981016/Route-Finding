#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

using namespace std;
int count=-1;
int count_point=-1;
	
	void Graph::addPoint(double latitude,double longtitude,int node,int count){
	//	point[count].lat=latitude;
	//	point[count].lon=longtitude;
	//	point[count].nodeId=node;
		point[count]=new Point(latitude, longtitude, node);
	}

    //添加一条从from到to,长度为len的边
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

   
    //用dijkstra算法求S到T的最短路径
    double Graph::dijkstra(int S, int T){
        for(int i = 0; i < n; ++i){
            dis[i] = -1;
            way[i]=-1;
        }
        dis[S] = 0;
        way[S] =S;
        //优先队列,每次取出离S点最近的点
        //去松弛其他顶点
        priority_queue<pair<double,int> >q;
        //将起点放入队列
        q.push(make_pair(0,S));
        while(!q.empty()){
            int u = q.top().second;
            double d = -q.top().first;
            //每次取出队首
            q.pop();
            //遍历这个点的边去判断是否可以松弛
            for(Edge* i = head[u]; i != NULL; i = i->nxt){
                int to = i->to;
				double len = i->len;
                //如果新的点还没有被访问过,或者通过u点访问更进,就用u点更新距离
                //并将这个点放入队列
                if(dis[to] == -1 || (dis[to] != -1 && dis[u] + len < dis[to]) ){
                    dis[to] = dis[u] + len;
                    way[to]=u;
                    q.push(make_pair(-dis[to],to));
                }
            }
        }
        return dis[T];
    }

