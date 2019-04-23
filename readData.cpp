#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h" 

void readData( Graph g){
	FILE *fp;
	int i=0,finda=0,findb=0,label=0,find_node=0;
	
	int a,b;
	int node_one_id,node_two_id;
	int first_point, second_point;
	char tag[6],pathId[20],node_one[5],node_two[5],way[20],tag_length[7];
	char cmp1[6] ="<link";
	char cmp2[6]="<node";
	
	int nodeIdValue;
	double lat,lon,length;
	char nodeId[3],tag_lat[4],tag_lon[4];
	char c[10000];

	fp = fopen("Final_Map.map" ,"r");
	while(fgets(c,10000,fp))
	{
		sscanf(c, "%5c", tag);
		tag[5] ='\0';
		if(strcmp(tag,cmp1)==0)
		{
			sscanf(c,"%s %s %5c %d %5c %d %s %7c %lf",tag,pathId,node_one,&node_one_id,node_two,&node_two_id,way,tag_length,&length);
			for(i=0;i<=count;i++)
			{
				if (node_one_id==source[i])
				{
						a=i;
						finda+=1;
				}
				if (node_two_id==source[i])
				{
						b=i;	
						findb+=1;
				}	
			}
			
			if((finda+findb)==2)	
			{
				g.addEdge(a,b,length);
				g.addEdge(b,a,length);
			}	
			else if(finda==0 && findb==1)
			{
				source[count+1]=node_one_id;
			//	g.point[count+1]->nodeId=node_one_id;
				g.addEdge(count+1,b,length);
				g.addEdge(b,count+1,length);
				count++;
			}
			else if(findb==0 && finda==1)	
			{
				source[count+1]=node_two_id;
			//	g.point[count+1]->nodeId=node_two_id;
				g.addEdge(a,count+1,length);
				g.addEdge(count+1,a,length);
				count++;
			}		
			else if(findb==0 && finda==0)	
			{
				source[count+1]=node_one_id;
				//g.point[count+1]->nodeId=node_one_id;
				source[count+2]=node_two_id;
				//g.point[count+2]->nodeId=node_two_id;
				g.addEdge(count+1,count+2,length);
				g.addEdge(count+2,count+1,length);
				count+=2;
			}		
			finda=0;
			findb=0;	
		}
		
		
		else if( strcmp(tag,cmp2)==0 )
		{
			count_point=count;
			sscanf(c,"%s %3c %d %4c %lf %4c %lf",tag,nodeId,&nodeIdValue,tag_lat,&lat,tag_lon,&lon);
			for(i=0;i<=count;i++){
				if(nodeIdValue==source[i]){
					label=i;
					find_node=1;
					break;					
				}					
			}
			if(find_node==1)
			{
				g.addPoint(lat,lon,nodeIdValue,label);
				find_node=0;
			}	
			else
			{
				count_point+=1;
				g.addPoint(lat,lon,nodeIdValue,count_point);
				
			}
			
		}	
	}

	fclose(fp);  
}
