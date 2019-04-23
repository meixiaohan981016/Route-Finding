#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "readData.h"
#include "writePoint.h"
#include "writeLine.h"
#include "writeBestRoute.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i,a,b;
	
	Graph g;
	g.Graph(10000);
	readData(g);
	
	for(i=0;i<=count;i++)
	{
		if (-1887796224==source[i])
			a=i;
		if (274252695==source[i])
			b=i;				
	}
	
	writeMapPoint(g);
	writeMapLine(g);

	
   cout << "from source[a] to source[b] " << g.dijkstra(a,b)<<endl;
	writeShortestLine(a,b,g);
   
   printf("from 0 to 5 shortest path is %i -> ", source[b]);
   int k=b;
   do {
	     if(g.way[k]!=a)
	     //print shortest way
		printf("%i ->",source[g.way[k]]); 
		  k=g.way[k];
	  }while(k != a);
	  printf("%i",source[a]);
	
	
     //print souce point
	
	return 0;
}
