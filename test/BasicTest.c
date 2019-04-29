#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include "..\Graph.h" 
#include "..\plot.h"
#include "..\readData.h"
#include "..\interface.h"

/* Test dijkstra with integer length */
void test_dijkstra_int(void)
{
	Graph g(100);
    g.addEdge(0,1,10);
    g.addEdge(1,2,15);
    g.addEdge(2,3,40);
    g.addEdge(0,2,11);
    g.addEdge(2,5,40);
    g.addEdge(3,5,20);
    g.addEdge(0,4,30);
    g.addEdge(0,5,60);
    
	TEST_ASSERT_EQUAL_INT(51,g.dijkstra(0,5));
	TEST_ASSERT_EQUAL_INT(2,g.way[5]);
    TEST_ASSERT_EQUAL_INT(0,g.way[2]);

}

/* Test dijkstra with float length */
void test_dijkstra_float(void)
{
	Graph g(100);
    g.addEdge(0,1,100.5);
    g.addEdge(1,2,67.5);
    g.addEdge(2,3,55.9);
    g.addEdge(0,2,200);
    g.addEdge(2,5,57.985);
    g.addEdge(5,2,57.985);
    g.addEdge(3,5,324.67);
    g.addEdge(0,4,11.9);
    g.addEdge(0,5,99.67);
    g.addEdge(5,6,294.6);
    g.addEdge(3,6,120.8);
    
	TEST_ASSERT_EQUAL_FLOAT(334.355000,g.dijkstra(0,6));
	TEST_ASSERT_EQUAL_INT(3,g.way[6]);
	TEST_ASSERT_EQUAL_INT(2,g.way[3]);
	TEST_ASSERT_EQUAL_INT(5,g.way[2]);
	TEST_ASSERT_EQUAL_INT(0,g.way[5]);

}

/* User input the two node ID in map, test whether they can be translated to correct index of point array*/
void test_user_input(void){
	
	Graph g(10000);
	
	readData(&g);
	
    printf("\n");

	printf("Please input source point id 1967770416 and end point id 2027774317 for user input module test \n");
	
	userInput(&g);
	
	TEST_ASSERT_EQUAL_INT(1765,start);
	TEST_ASSERT_EQUAL_INT(1773,end);
}


int mymain(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_dijkstra_int);
	RUN_TEST(test_dijkstra_float);
	RUN_TEST(test_user_input);

	UNITY_END();
	return 0;
}


