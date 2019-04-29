#ifndef graph_H
#define graph_H

#define MaxPointEdge 3000

//the number of points
extern int count_point;

//the number of points which has an edge
extern int count;

#define N 20000

struct Graph
{
	//n represents the number of the start points and the array index is from 0 to n-1
	 int n;
	
	//adjacency list to store the edges
	 struct Edge{
	 	int to;
	 	double len;
	 	Edge* nxt;
	 	Edge(int to, double len, Edge* nxt):to(to),len(len),nxt(nxt){} 
	   };
	
	//the head of adjacency list, where its array index represents a start point
	 //Edge* head[N];
	 Edge *head[N];
	
	 double dis[N];
	 
	 //record the points which the best route was gone through
	 int way[N];
	
	//a structure to store the points
	 struct Point{
	 	double lat,lon;
	 	int nodeId;
	 	Point(double lat, double lon,int nodeId):lat(lat),lon(lon),nodeId(nodeId){}
	 };
	 Point *point[N];	 
	 
	 //function declaration
	 void addPoint(double latitude, double longtitude, int node, int count);
	 void addEdge(int from, int to, double len);
	 Graph(int _n);
	 void init(int _n);
	 double dijkstra(int S, int T); 
};

#endif
