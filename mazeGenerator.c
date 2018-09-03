#include "includes.h"
void initializeMaze(const int width, const int height, Node **nodes)
{
	int i, j;
	Node *current;

	*nodes = calloc(width * height, sizeof(Node));

	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			current = (*nodes) + i + j * width;

			if (i * j % 2)
			{
				current->x = i;
				current->y = j;
				current->directionsToExplore = 15; 
				current->displayCharacter = ' ';
			}
			else
				current->displayCharacter = '#';
			current->isVisited = false;
		}
	}
}

void setExitAndEntrance(const int width, const int height, Node **nodes)
{
	(*nodes)[width].displayCharacter = ' ';
	(*nodes)[((width) * (height - 1)) - 1].displayCharacter = ' ';
}

Node *linkNodes(Node *current, const int width, const int height, Node **nodes)
{
	int x, y, numberOfDirections = 4;
	char dir;
	Node *dest;
	enum directions{right = 1, down = 2, left = 4, up = 8};

	if (current == NULL) 
		return NULL;

	while (current->directionsToExplore)
	{
		dir = (1 << (rand() % numberOfDirections));
		
		if (~current->directionsToExplore & dir)
			continue;
		
		current->directionsToExplore &= ~dir;
		
		switch (dir)
		{
		case right:
			if (current->x + 2 < width)
			{
				x = current->x + 2;
				y = current->y;
			}
			else continue;
			break;
		
		case down:
			if (current->y + 2 < height)
			{
				x = current->x;
				y = current->y + 2;
			}
			else continue;
			break;
		
		case left:
			if (current->x - 2 >= 0)
			{
				x = current->x - 2;
				y = current->y;
			}
			else continue;
			break;
		
		case up:
			if (current->y - 2 >= 0)
			{
				x = current->x;
				y = current->y - 2;
			}
			else continue;
			break;
		}
		dest = (*nodes) + x + y * width;

		if (dest->displayCharacter == ' ')
		{
			if (dest->parent != NULL) continue;

			dest->parent = current;

			(*nodes)[current->x + (x - current->x) / 2 + (current->y + (y - current->y) / 2) * width].displayCharacter = ' ';

			return dest;
		}
	}
	return current->parent;
}

void setupStartNodeForGenerator(Node ** start, Node ** last, Node ** nodes,const int width)
{
	*start = *nodes + 1 + width;
	(*start)->parent = *start;
	*last = *start;
}

void resetLabirynth(int *width, int *height, Node **nodes)
{
	free(*nodes);
	*nodes = NULL;
	*width = 0;
	*height = 0;
}

void getValuesFromCommandLineArguments(int *width, int *height, char ***argv)
{
	*width = atoi(argv[1]);
    *height = atoi(argv[2]);
}