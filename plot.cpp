#include "stdlib.h"
#include "Graph.h" 
#include "stdio.h"
#include "plot.h"



	// Plot Point
	void writeMapPoint(Graph::Point *point[]) {
	
	  FILE *fp = fopen("mapPoint.out","w");
	
	  writePoint(fp,point);
	
	  fclose(fp);
	}
	
	// recursively visit the leaf nodes
	
	void writePoint( FILE *fp, Graph::Point *point[] ) {
	
	  int i;
	
		for ( i=0; i<count_point; ++i ) {
		  if(point[i]!=NULL)
	      printOutPoint( fp, point[i]->lat,point[i]->lon);
	    }
	  }
	
	// write out the (x,y) corners of the node
	
	void printOutPoint( FILE *fp, double lat, double lon ) {
	  double x = lon;
	  double y = lat;
	 
	  fprintf(fp, " %g %g\n\n",x,y);
	}
	
	//Plot line
	
		void writeMapLine(Graph::Edge * head[], Graph::Point *point[]) {
		
		int i;
	
	  	FILE *fp = fopen("mapLine.out","w");
	
		for(i=0;i<count;i++)
	  	{ 
	  		writeLine(fp,head[i],i,point);
	  		
		}
	
	  fclose(fp);
	}
	
	// recursively visit the leaf nodes
	
	void writeLine( FILE *fp, Graph::Edge* edge ,int label, Graph::Point *point[]) { 	
	
		if(edge->nxt==NULL) 
		    
			//if(point[label]!=NULL || point[edge->to]!=NULL)   	
      		printOutLine( fp, point[label]->lat, point[label]->lon, point[edge->to]->lat, point[edge->to]->lon);
      	else{
      		//if(point[label]!=NULL || point[edge->to]!=NULL)
			
			printOutLine( fp, point[label]->lat, point[label]->lon, point[edge->to]->lat, point[edge->to]->lon);
      		writeLine(fp,edge->nxt,label,point);
		  }
    }
	  
	
	// write out the (x,y) corners of the node
	
	void printOutLine( FILE *fp, double latFrom, double lonFrom,double latTo,double lonTo ) {
		fprintf(fp, " %g %g\n",lonFrom,latFrom);
	  	fprintf(fp, " %g %g\n\n",lonTo,latTo);
	}
	
	//Plot shortest line
	
	void writeShortestLine(int from, int to, Graph::Point *point[], int way[]) {
	
	  	FILE *fp = fopen("mapShortestLine.out","w");
	  	int k=to;
   		int l;
	  
	  	printOutLine(fp, point[to]->lat, point[to]->lon, point[way[k]]->lat, point[way[k]]->lon );
   		
   		do {
	     	if(way[k]!=from)
	    	{
	    		l=way[k];
	    		printOutLine(fp, point[way[k]]->lat, point[way[k]]->lon,point[way[l]]->lat, point[way[l]]->lon ); 
			}
		  	k=way[k];
		  	
	  		}while(k != from);
	  		
	  	printOutLine(fp, point[way[k]]->lat, point[way[k]]->lon, point[from]->lat, point[from]->lon );
		  	
	  	fclose(fp);
	}
	
