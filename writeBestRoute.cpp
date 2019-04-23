#include "stdio.h"
#include "stdlib.h"
#include "writeBestRoute.h"
#include "writeLine.h"
#include "Graph.h" 

	void writeShortestLine(int from, int to, Graph g) {
	
	  	FILE *fp = fopen("mapShortestLine.out","w");
	  	int k=to;
   		int l;
	  
	  	printOutLine(fp, g.point[to]->lat, g.point[to]->lon, g.point[g.way[k]]->lat, g.point[g.way[k]]->lon );
   		
   		do {
	     	if(g.way[k]!=from)
	    	{
	    		l=g.way[k];
	    		printOutLine(fp, g.point[g.way[k]]->lat, g.point[g.way[k]]->lon, g.point[g.way[l]]->lat, g.point[g.way[l]]->lon ); 
			}
		  	k=g.way[k];
		  	
	  		}while(k != from);
	  		
	  	printOutLine(fp, g.point[g.way[k]]->lat, g.point[g.way[k]]->lon, g.point[from]->lat, g.point[from]->lon );
		  	
	  	fclose(fp);
	}
