#ifndef user_interface_H
#define user_interface_H

//the array index of the two points which is given by users stored in source
extern int start, end;

//function declaration
int userInput(Graph *g);
void displayBestRoute(int way[],Graph *g);

#endif
