#include "stdlib.h"
#include "Graph.h" 
#include "stdio.h"
#include "plot.h"
#include "readData.h"

	// create a mapPoint.out file to plot Points in data input files
	void writeMapPoint(Graph::Point *point[]) {
	
	  FILE *fp = fopen("mapPoint.out","w");
	
	  writePoint(fp,point);
	
	  fclose(fp);
	}
	
	// plot points in data input files
	void writePoint( FILE *fp, Graph::Point *point[] ) {
	
	  	int i;
	
		for ( i = 0; i<count_point; ++i ) {
		  	if(point[i] != NULL)
	      		printOutPoint( fp, point[i]->lat,point[i]->lon);
	    }
	}
	
	// plot one point
	void printOutPoint( FILE *fp, double lat, double lon ) {
	  double x = lon;
	  double y = lat;
	 
	  fprintf(fp, " %g %g\n\n",x,y);
	}
	
	//create a mapLine.out file and plot all the lines in the data input file
	void writeMapLine(Graph::Edge * head[], Graph::Point *point[]) {
		
		int i;
	
	  	FILE *fp = fopen("mapLine.out","w");
	
		for(i=0;i<count;i++)
	  		writeLine(fp,head[i],i,point);
			
	  		
	 	fclose(fp);
	}
	
	// plot lines with the same start point
	void writeLine( FILE *fp, Graph::Edge* edge ,int label, Graph::Point *point[]) { 	
	
		if(edge->nxt == NULL)  	
      		printOutLine( fp, point[label]->lat, point[label]->lon, point[edge->to]->lat, point[edge->to]->lon);
      	else{
			printOutLine( fp, point[label]->lat, point[label]->lon, point[edge->to]->lat, point[edge->to]->lon);
      		writeLine(fp,edge->nxt,label,point);
		}
    }
	  
	// plot one line
	void printOutLine( FILE *fp, double latFrom, double lonFrom,double latTo,double lonTo ) {
		fprintf(fp, " %g %g\n",lonFrom,latFrom);
	  	fprintf(fp, " %g %g\n\n",lonTo,latTo);
	}
	
	//Plot shortest line	
	int writeShortestLine(int from, int to, Graph::Point *point[], int way[]) {
	
	  	FILE *fp = fopen("mapShortestLine.out","w");
	  	int k=to;
   		int l;
	  	
	  	if( point[to]!=NULL || point[way[k]]!=NULL )
	  		printOutLine(fp, point[to]->lat, point[to]->lon, point[way[k]]->lat, point[way[k]]->lon );
   		else{
   			errhandle(errno);
   			return 1;
		}	
   			
   		do {
   			
	     	if(way[k]!=from){
	    		l=way[k];
	    		printOutLine(fp, point[way[k]]->lat, point[way[k]]->lon, point[way[l]]->lat, point[way[l]]->lon ); 
			}
			
		  	k=way[k];		  	
	  	}
		while(k != from);
	  		
	  	printOutLine(fp, point[way[k]]->lat, point[way[k]]->lon, point[from]->lat, point[from]->lon );
		  	
	  	fclose(fp);
	}
	
