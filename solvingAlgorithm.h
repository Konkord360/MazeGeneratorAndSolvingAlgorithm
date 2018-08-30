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
void comeBackFromDeadEnd(WayOut* current, const int width);
int countPossibleWays(WayOut *current, const int width);
#endif