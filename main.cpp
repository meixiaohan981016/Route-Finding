#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "readData.h"
#include "plot.h"
#include "interface.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	int num;	
	
	if(argc == 2)
		num = atoi(argv[1]);

	else{
		printf("No parameter or too many paramerters!");
		exit(1);
	}
	
	Graph g(num);
	
	int ret = readData(&g);
	
	if(ret == 1){
		printf("\nFail to read map data, please check after application exit");
		exit(1);
	}
	
	else if(ret == 2){
		printf("\nThe file is not completely read! Please give a bigger parameter for number of points!");
		exit(2);
	}	
		
	while(userInput(&g) == 1)
		printf("re-enter correct source and end points id in map:");			
	
	writeMapPoint(g.point);
	
	writeMapLine(g.head,g.point);

	printf("\n------------------------\n");
   	cout << "from " << g.point[start]->nodeId << " to " << g.point[end]->nodeId << " " << "shortest distance is" << " " <<g.dijkstra(start,end) <<endl;
   	printf("------------------------\n");
   	
	if(writeShortestLine(start,end,g.point,g.way) ==1){
		printf("The shortest path is wrong! Exit application!");
		exit(1);
	};
	
	displayBestRoute(g.way, &g);	

	
	return 0;
}
