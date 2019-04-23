#include "stdio.h"
#include "stdlib.h"
#include "writeLine.h"
#include "Graph.h" 

	void writeMapLine(Graph g) {
		
		int i;
	
	  	FILE *fp = fopen("mapLine.out","w");
	
		for(i=0;i<count;i++)
	  	{
	  		writeLine(fp,g,i);
	  		
		}
	
	  fclose(fp);
	}
	
	// recursively visit the leaf nodes
	
	void writeLine( FILE *fp, Graph g ,int label) { 	
	
		if(edge->nxt==NULL)    	
      		printOutLine( fp, g.point[label]->lat, g.point[label]->lon, g.point[g.head[label]->to]->lat, g.point[g.head[label]->to]->lon);
      	else{
      		printOutLine( fp, g.point[label]->lat, g.point[label]->lon, g.point[g.head[label]->to]->lat, g.point[g.head[label]->to]->lon);
      		writeLine(fp,edge->nxt,label);
		  }
    }
	  
	
	// write out the (x,y) corners of the node
	
	void printOutLine( FILE *fp, double latFrom, double lonFrom,double latTo,double lonTo ) {
		fprintf(fp, " %g %g\n",lonFrom,latFrom);
	  	fprintf(fp, " %g %g\n\n",lonTo,latTo);
	}
	
