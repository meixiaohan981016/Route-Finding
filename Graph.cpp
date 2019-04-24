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

    //���һ����from��to,����Ϊlen�ı�
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

   
    //��dijkstra�㷨��S��T�����·��
    double Graph::dijkstra(int S, int T){
        for(int i = 0; i < n; ++i){
            dis[i] = -1;
            way[i]=-1;
        }
        dis[S] = 0;
        way[S] =S;
        //���ȶ���,ÿ��ȡ����S������ĵ�
        //ȥ�ɳ���������
        priority_queue<pair<double,int> >q;
        //�����������
        q.push(make_pair(0,S));
        while(!q.empty()){
            int u = q.top().second;
            double d = -q.top().first;
            //ÿ��ȡ������
            q.pop();
            //���������ı�ȥ�ж��Ƿ�����ɳ�
            for(Edge* i = head[u]; i != NULL; i = i->nxt){
                int to = i->to;
				double len = i->len;
                //����µĵ㻹û�б����ʹ�,����ͨ��u����ʸ���,����u����¾���
                //���������������
                if(dis[to] == -1 || (dis[to] != -1 && dis[u] + len < dis[to]) ){
                    dis[to] = dis[u] + len;
                    way[to]=u;
                    q.push(make_pair(-dis[to],to));
                }
            }
        }
        return dis[T];
    }

