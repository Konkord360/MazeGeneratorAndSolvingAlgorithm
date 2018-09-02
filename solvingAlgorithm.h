#ifndef SOLVINGALGORITHM_H_   
#define SOLVINGALGORITHM_H_

#include "mazeGenerator.h"

typedef struct way
{
	Node *node;
	struct way *next;
	struct way *previous;
} WayOut;

void solvingAlgorithm(Node **nodes, const int width, const int height);
int nextDirection(WayOut *current, int width);
void addTheNextNode(WayOut **current);
void comeBackFromDeadEnd(WayOut** current, const int width);
int countPossibleWays(WayOut *current, const int width);
void freeMemoryAllocatedForlist(WayOut **current);
void initializeList(WayOut** wayOutHead, WayOut** current, Node **nodes, const int width);
#endif