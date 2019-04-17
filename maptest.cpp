#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000000
typedef struct CELL *LIST;

struct CELL{
	int nodeName;
	int childNodeName;
	float nodeLabel;
	LIST next;
};

typedef struct graphic{
	float dist;
	int sourceNodeName;
	LIST successors;
	int toPot;
}GRAPH[MAX];

typedef int POT[MAX+1];

void addList(LIST list, int arrayLabel,int id, float length){
	if(list->nodeName!= NULL)
		addList(list->next,arrayLabel,id,length);
	else
	{
		list->nodeName=arrayLabel;
		list->childNodeName=id;
		list->nodeLabel=length;
		list->next=NULL;
	}	
}

//*********************************************************************
void swap(int a, int b, GRAPH G, POT P)
{
	int/*NODE*/ temp;
	
	temp=P[b];
	P[b]=P[a];
	P[a]=temp;
	G[P[a]].toPot = a;
	G[P[b]].toPot = b;
}

float priority(int/*potnode*/ a, GRAPH G, POT P)
{
	return G[P[a]].dist;
}

void bubbleUp(int/*potnode*/ a, GRAPH G, POT P)
{
	if((a>1) && (priority(a,G,P)<priority(a/2,G,P)))
	{
		swap(a,a/2,G,P);
		bubbleUp(a/2,G,P);
	}
}

void bubbleDown(int/*potnode*/ a, GRAPH G, POT P, int last)
{
	int/*(POTNODE)*/ child;
	
	child = 2*a;
	if (child<last && priority(child+1, G, P)<priority(child,G,P))
		child++;
	if(child<=last && priority(a,G,P)>priority(child,G,P)){
		swap(a,child ,G,P);
		bubbleDown(child,G,P,last);
	}
}

void initialize(GRAPH G,POT P, int *pLast)
{
	int i;
	for(i=0;i<MAX;i++){
		G[i].dist =10000000;
		G[i].toPot =i+1;
		P[i+1]=i;
	}
	
	G[0].dist=0;
	//G[v].dist=0;
	(*pLast)=MAX;
}
//*********************************************************************
void Dijkstra(GRAPH G, POT P, int *pLast)
{
	//int/*NODE*/ u, v; 
	int u, v;
	LIST ps; 
 	initialize(G, P, pLast);
  	while ((*pLast) > 1)
	{
  		v = P[1];
 		swap(1, *pLast, G, P);
  		--(*pLast);
 		bubbleDown(1, G, P, *pLast);
 		ps = G[v].successors;
 		while (ps != NULL) 
		{
			u = ps->nodeName;
 			if (G[u].dist > G[v].dist + ps->nodeLabel) 
			{
 				G[u].dist = G[v].dist + ps->nodeLabel;
 				bubbleUp(G[u].toPot, G, P);
			}
 			ps = ps->next;
		}
	}
}

main(){
	FILE *fp;
	GRAPH graph;
	
	int find=0,count=1;
	int *pLast;
	int node_one_id,node_two_id,length;
	int first_point, second_point;
	char tag[20],pathId[20],node_one[5],node_two[5],way[20],tag_length[7];
	
	int nodeIdValue, lat,lon;
	char nodeId[3],tag_lat[4],tag_lon[4];
	char c[10000];
	
	POT P;
	printf("Input the source points to get the best path:");
	scanf("%d",&first_point);
	printf("Input the end points to get the best path:");
	scanf("%d",&second_point);
	
	
	fp = fopen("map.txt" ,"r");
	
	while(fgets(c,10000,fp))
	{
		sscanf(c,"%s %s %5c %d %5c %d %s %7c %d",tag,pathId,node_one,&node_one_id);
		if(tag=="<link")
		{
			graph[count].sourceNodeName=node_one_id;
			if (first_point==node_one_id)
				graph[0].sourceNodeName=node_one_id;
		}
		count++;
	}
	*pLast=count;
	
	while(fgets(c,10000,fp))
	{
		sscanf(c, "%s", tag) ;
		if(tag=="<link")
		{
			sscanf(c,"%s %s %5c %d %5c %d %s %7c %d",tag,pathId,node_one,&node_one_id,node_two,&node_two_id,way,tag_length,&length);
			for(int i=0;i<=count;i++)
			{
				if(node_one_id==graph[i].sourceNodeName)
				{
					for(int j=0;j<=count;j++)
						if(node_two_id==graph[j].sourceNodeName)
							addList(graph[i].successors,j,node_two_id,length);
				}
			}
		}
		
		else if( tag=="<node" )
		{
			sscanf(c,"%s %3c %d %4c %d %4c %d",tag,nodeId,&nodeIdValue,tag_lat,&lat,tag_lon,&lon);
		}	
	}
	fclose(fp);
	
	//scanf("Input two points to get the best path: %d,%d ",&first_point,&second_point);
	Dijkstra(graph, P, pLast);
	}
	

