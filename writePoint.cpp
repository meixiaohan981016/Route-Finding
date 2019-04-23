#include "stdio.h"
#include "stdlib.h"
#include "writePoint.h"
#include "Graph.h" 
	
	// write out the tree to file 'quad.out'
	void writeMapPoint(Graph g) {
	
	  FILE *fp = fopen("mapPoint.out","w");
	
	  writePoint(fp, g);
	
	  fclose(fp);
	}
	
	// recursively visit the leaf nodes
	
	void writePoint( FILE *fp, Graph g) {
	
	  int i;
	
		for ( i=0; i<count_point; ++i ) {
	      printOutPoint( fp, g.point[i]->lat,g.point[i]->lon);
	    }
	  }
	
	// write out the (x,y) corners of the node
	
	void printOutPoint( FILE *fp, double lat, double lon ) {
	  double x = lon;
	  double y = lat;
	 
	  fprintf(fp, " %g %g\n\n",x,y);
	}
	


