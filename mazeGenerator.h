#ifndef MAZEGENERATOR_H_   
#define MAZEGENERATOR_H_
#define minimumSize 2

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	int x, y; 
	void *parent; 
	char displayCharacter; 
	char directionsToExplore; 
	bool isVisited;
} Node;

int initialize(const int width, const int height, Node **nodes);
void setExitAndEntrance(const int width, const int height, Node **nodes);
Node *link(Node *n, const int width, const int height, Node **nodes);
void setupStartNode(Node **start, Node **last, Node **nodes,const int width);

#endif 