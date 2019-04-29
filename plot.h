#ifndef plot_h
#define plot_h

#include "Graph.h"

void writeMapPoint(Graph::Point *point[]);
void writePoint(FILE *fp, Graph::Point *point[] );
void printOutPoint( FILE *fp, double lat, double lon );

void writeMapLine(Graph::Edge * head[], Graph::Point *point[]);
void writeLine( FILE *fp, Graph::Edge* edge ,int label, Graph::Point *point[]);
void printOutLine( FILE *fp, double latFrom, double lonFrom,double latTo,double lonTo );

int writeShortestLine(int from, int to, Graph::Point *point[],int way[]);

#endif
