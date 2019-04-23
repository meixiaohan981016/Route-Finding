#ifndef graph_H
#define graph_H

extern int count_point;
extern int count;
extern int source[3000];

#define N 20000

typedef struct graph
{
 //�ṹ��Ա���� 
 int n;

 struct Edge{
 	int to;
 	double len;
 	Edge* nxt;
 	Edge(int to, double len, Edge* nxt):to(to),len(len),nxt(nxt){} 
   };

    //�ڽӱ�ͷ
 Edge* head[N];
 double dis[N];
 int way[N];
	
 struct Point{
 	double lat,lon;
 	int nodeId;
 	Point(double lat, double lon,int nodeID):lat(lat),lon(lon),nodeId(nodeId){}
 };
 Point *point[N];
 
 
 //�ṹ��Ա�������� 
 void addPoint(double latitude, double longtitude, int node, int count);
 void addEdge(int from, int to, double len);
 Graph(int _n);
 void init(int _n);
 double dijkstra(int S, int T); 
}Graph;

#endif
