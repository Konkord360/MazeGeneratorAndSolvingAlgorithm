#include "includes.h"


void solvingAlgorithm(Node **nodes, const int width, const int height) {
	enum directions { right = 0, down = 1, up = 2, left = 3, deadEnd = 4 };
	char displayCharacter = (char)219;
	int wayToCheck = 0, possibleWays = 0;
	WayOut *wayOutHead = NULL, *current = NULL;

	initializeList(&wayOutHead, &current, &*nodes, width);

	do {
		current->next = malloc(sizeof(WayOut));

		switch (wayToCheck) 
		{
		case right:
			current->next->node = current->node + 1;
			break;
		case down:
			current->next->node = current->node + width;
			break;
		case up:
			current->next->node = current->node - width;
			break;
		case left:
			current->next->node = current->node - 1;
			break;
		case deadEnd:
			comeBackFromDeadEnd(&current, width);
			break;
		}

		if (wayToCheck != deadEnd)
			addTheNextNode(&current);

		wayToCheck = nextDirection(current, width);
	} while (current->node != &(*nodes)[((width) * (height - 1)) - 1]);
	
	current = wayOutHead;
	freeMemoryAllocatedForlist(&current);
}

int nextDirection(WayOut *current, int width)
{
	current->node = current->node + 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node - 1;
		return 0;
	}

	current->node = current->node - 1;
	current->node = current->node + width;

	if (current->node->displayCharacter != '#' && current->node->isVisited == false)
	{
		current->node = current->node - width;
		return 1;
	}

	current->node = current->node - width;
	current->node = current->node - width;

	if (current->node->displayCharacter != '#' && current->node->isVisited == false)
	{
		current->node = current->node + width;
		return 2;
	}

	current->node = current->node + width;
	current->node = current->node - 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false)
	{
		current->node = current->node + 1;
		return 3;
	}

	current->node = current->node + 1;
	return 4;
}

void addTheNextNode(WayOut **current) 
{
	char displayCharacter = (char)219;
	(*current)->next->previous = (*current);
	(*current) = (*current)->next;
	(*current)->next = NULL;
	(*current)->node->displayCharacter = displayCharacter;
	(*current)->node->isVisited = true;
}

void comeBackFromDeadEnd(WayOut **current, const int width) 
{
	int possibleWays = 0;
	do 
	{
		possibleWays = countPossibleWays(*current, width);
		if (possibleWays == 0)
		{
			free((*current)->next);
			(*current)->next = NULL;
			(*current)->node->displayCharacter = ' ';
			(*current) = (*current)->previous;
			free((*current)->next);
			(*current)->next = NULL;
		}
	} while (possibleWays == 0);
}

int countPossibleWays(WayOut *current, const int width)
{
	int possibleWays = 0;

	current->node = current->node + 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false)
	{
		current->node = current->node - 1;
		possibleWays++;
	}
	else
		current->node = current->node - 1;

	current->node = current->node + width;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false)
	{
		current->node = current->node - width;
		possibleWays++;
	}
	else
		current->node = current->node - width;

	current->node = current->node - width;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) 
	{
		current->node = current->node + width;
		possibleWays++;
	}

	else
		current->node = current->node + width;

	current->node = current->node - 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) 
	{
		current->node = current->node + 1;
		possibleWays++;
	}
	else
		current->node = current->node + 1;
	return possibleWays;
}

void freeMemoryAllocatedForlist(WayOut **current)
{
	while ((*current)->next != NULL)
	{
		(*current) = (*current)->next;
		free((*current)->previous);
		(*current)->previous = NULL;
	}
	free((*current));
	(*current) = NULL;
}

void initializeList(WayOut** wayOutHead, WayOut** current, Node **nodes, const int width)
{
	char displayCharacter = (char)219;
	(*wayOutHead) = malloc(sizeof(WayOut));
	(*wayOutHead)->node = &(*nodes)[width];
	(*wayOutHead)->previous = NULL;
	(*wayOutHead)->next = NULL;

	(*current) = (*wayOutHead);
	(*current)->node->displayCharacter = displayCharacter;
	(*current)->node->isVisited = true;
}