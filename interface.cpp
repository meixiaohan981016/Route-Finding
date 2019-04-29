#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h" 

int start,end;

int userInput( Graph *g){
	
	//the real id of two provided points
	int source_point, end_point;
	
	int i = 0, find_start = 0, find_end = 0;
	
	//Input two points to compute out the best route
	printf("-->Input the source point: e.g.1967770416\n");
	scanf("%d",&source_point);
	printf("-->Input the end point:e.g.2027774317\n");
	scanf("%d",&end_point);
	
	//find the array index of two provided points
	for(i=0;i<=count;i++){
		if (source_point == g->point[i]->nodeId){		
			start = i;
			find_start = 1;
		}
		
		if (end_point == g->point[i]->nodeId){
			end = i;
			find_end = 1;	
		}				
	}
	
	if( find_start == 0 ){
		printf("Your start point id is wrong!\n");
		return 1;
	}
	
	else if( find_end == 0 ){
		printf("Your end point id is wrong!\n");
		return 1;
	}
	
	else
		return 0;
}

void displayBestRoute(int way[], Graph *g){
	
	printf("from %d to %d shortest path is %i -> ", g->point[end]->nodeId, g->point[start]->nodeId, g->point[end]->nodeId);
   	int k=end;
   	do {
	    if(way[k]!=start)
	     //print shortest way
			printf("%i ->",g->point[way[k]]->nodeId); 
		k=way[k];
	  	}
	while(k != start);
	printf("%i",g->point[start]->nodeId);
	

}
