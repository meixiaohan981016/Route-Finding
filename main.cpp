#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "readData.h"
#include "plot.h"
#include "interface.h"
//#include "writeLine.h"
//#include "writeBestRoute.h"

using namespace std;

int source[3000];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Graph g(10000);
	
	readData(&g);
	
	user();
	
	writeMapPoint(g.point);
	writeMapLine(g.head,g.point);

   	cout << "from" << start <<"to"<< end << g.dijkstra(start,end) <<endl;
	writeShortestLine(start,end,g.point,g.way);
  
   printf("from %d to %d shortest path is %i -> ", start,end,source[end]);
   int k=end;
   do {
	     if(g.way[k]!=start)
	     //print shortest way
		printf("%i ->",source[g.way[k]]); 
		  k=g.way[k];
	  }while(k != start);
	  printf("%i",source[start]);
	
	
     //print souce point
	
	return 0;
}
