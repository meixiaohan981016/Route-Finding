#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h" 

int start,end;

void user(){

	int source_point,end_point;
	int i=0;
	
	printf("-->Input the source point:\n");
	scanf("%d",&source_point);
	printf("-->Input the end point:\n");
	scanf("%d",&end_point);
	
	for(i=0;i<=count;i++)
	{
		if (source_point==source[i])
			start=i;
		if (end_point==source[i])
			end=i;				
	}
}
