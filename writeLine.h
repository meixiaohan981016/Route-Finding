#ifndef write_line_h
#define write_line_h

	void writeMapLine(Graph *g ) ;
	void writeLine( FILE *fp, Graph *g ,int label);
	void printOutLine( FILE *fp, double latFrom, double lonFrom,double latTo,double lonTo );
#endif
