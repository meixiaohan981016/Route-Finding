#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h" 


/*Test github 2*/ 
//Node *makeNode( double x, double y, int level );
//void makeChildren( Node *parent );


// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

//add children to all leaf nodes

void growTree( Node *grownode ) {
	int i=0;
	if ( grownode->child[0]==NULL)
		makeChildren(grownode);
	else
	{
		for (i=0;i<4;i++)
			growTree( grownode->child[i] );
	}
	return;
}


