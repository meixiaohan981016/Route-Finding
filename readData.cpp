#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h"
#include "error.h"

int errhandle(int errum){
	fprintf(stderr,"%s \n",strerror(errum));
	return 0;
}

int readData( Graph *g){
	FILE *fp;
	int i=0,finda=0,findb=0,label=0,find_node=0;
	
	int a,b;
	int node_one_id,node_two_id;
	int first_point, second_point;
	char tag[6],pathId[20],node_one[5],node_two[5],way[20],tag_length[7];
	
	//tag
	char cmp1[6] = "<link";
	char cmp2[6] = "<node";
	
	int nodeIdValue;
	double lat,lon,length;
	char nodeId[3],tag_lat[4],tag_lon[4];
	
	//store data in one line
	char line[10000];
	
	fp = fopen("Final_Map.map" ,"r");
	if(fp==NULL){
		errhandle(errno);
		return 1;
	}	
	
	while(fgets(line,10000,fp)){
		sscanf(line, "%5c", tag);
		tag[5] = '\0';
		
		//compare the tag with cmp1
		if(strcmp(tag,cmp1) == 0)
		{
			sscanf(line,"%s %s %5c %d %5c %d %s %7c %lf",tag,pathId,node_one,&node_one_id,node_two,&node_two_id,way,tag_length,&length);
			
			//judge whehter the edge's two points has already been stored, where variable finda and finb =1 represents stored and 0 represents not stored
			for(i=0;i<=count;i++){
				
				if (node_one_id == g->point[i]->nodeId){
					a = i;
					finda = 1;
				}
				
				if (node_two_id == g->point[i]->nodeId){
					b = i;	
					findb = 1;
				}	
			}
			
			//if two points are stored, add this edge
			if((finda+findb) == 2){
				g->addEdge(a,b,length);
				g->addEdge(b,a,length);
			}	
			
			//if the first point is not stored, firstly store this point, then add this edge
			else if(finda == 0 && findb==1){
				g->addPoint(0,0,node_one_id,count+1);
				//point[count+1]->nodeId=node_one_id;
				g->addEdge(count+1,b,length);
				g->addEdge(b,count+1,length);
				count++;
			}
			
			//if the second point is not stored, firstly store this point, then add this edge
			else if(findb== 0 && finda == 1){
				g->addPoint(0,0,node_two_id,count+1);
				g->addEdge(a,count+1,length);
				g->addEdge(count+1,a,length);
				count++;
			}	
			
			//if two points are not stored, firstly store two points, then add this edge
			else if(findb == 0 && finda == 0){
				g->addPoint(0,0,node_one_id,count+1);
				g->addPoint(0,0,node_two_id,count+2);
				g->addEdge(count+1,count+2,length);
				g->addEdge(count+2,count+1,length);
				count += 2;
			}		
			
			if(count > g->n){
				printf("The number of points is beyond maximum!");
				return 2;
			} 
			
			finda = 0;
			findb = 0;
			count_point = count;	
		}
		
		//compare tag with cmp2
		else if( strcmp(tag,cmp2) == 0 ){
			sscanf(line,"%s %3c %d %4c %lf %4c %lf",tag,nodeId,&nodeIdValue,tag_lat,&lat,tag_lon,&lon);
			
			//compare the node id with the id in source[], if find, the array index should be the same
			for(i=0;i<=count;i++){
				if(nodeIdValue == g->point[i]->nodeId){
					label = i;
					find_node = 1;
					break;					
				}					
			}
			
			//if find the id i source[], add this point
			if(find_node==1){
				g->point[label]->lat = lat;
				g->point[label]->lon = lon;
				find_node=0;
			}	
			
			//if not find,add this point into the tail of the array
			else{
				count_point += 1;
				g->addPoint(lat,lon,nodeIdValue,count_point);				
			}			
			
			if(count_point > g->n){
				printf("The number of points is beyond maximum!");
				return 2;
			} 
		}	
	}

	fclose(fp); 
	return 0; 
}
