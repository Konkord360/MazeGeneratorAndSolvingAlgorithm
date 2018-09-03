#ifndef MAZEGENERATOR_H_   
#define MAZEGENERATOR_H_
#define minimumSize 2

#include "includes.h"
#include <stdbool.h>

typedef struct
{
	int x, y; 
	void *parent; 
	char displayCharacter; 
	char directionsToExplore; 
	bool isVisited;
} Node;

void initializeMaze(const int width, const int height, Node **nodes);
void setExitAndEntrance(const int width, const int height, Node **nodes);
Node *linkNodes(Node *n, const int width, const int height, Node **nodes);
void setupStartNodeForGenerator(Node **start, Node **last, Node **nodes,const int width);
void resetLabirynth(int *width, int *height, Node **nodes);
void getValuesFromCommandLineArguments(int *width, int *height, char ***argv);

#endif 