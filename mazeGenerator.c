#include "includes.h"
int initialize(const int width, const int height, Node **nodes)
{
	int i, j;
	Node *n;

	*nodes = calloc(width * height, sizeof(Node));

	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			n = (*nodes) + i + j * width;

			if (i * j % 2)
			{
				n->x = i;
				n->y = j;
				n->directionsToExplore = 15; 
				n->displayCharacter = ' ';
			}
			else
				n->displayCharacter = '#';
			n->isVisited = false;
		}
	}
	setExitAndEntrance(width, height, &(*nodes));

	return 0;
}

void setExitAndEntrance(const int width, const int height, Node **nodes)
{
	(*nodes)[width].displayCharacter = ' ';
	(*nodes)[((width) * (height - 1)) - 1].displayCharacter = ' ';
}

Node *link(Node *n, const int width, const int height, Node **nodes)
{
	int x, y;
	char dir;
	Node *dest;

	if (n == NULL) 
		return NULL;

	while (n->directionsToExplore)
	{
		//setDirection(&n, width, height, &x, &y);
		dir = (1 << (rand() % 4));
		
		if (~n->directionsToExplore & dir)
			continue;
		
		n->directionsToExplore &= ~dir;
		
		switch (dir)
		{
		case 1:
			if (n->x + 2 < width)
			{
				x = n->x + 2;
				y = n->y;
			}
			else continue;
			break;
		
		case 2:
			if (n->y + 2 < height)
			{
				x = n->x;
				y = n->y + 2;
			}
			else continue;
			break;
		
		case 4:
			if (n->x - 2 >= 0)
			{
				x = n->x - 2;
				y = n->y;
			}
			else continue;
			break;
		
		case 8:
			if (n->y - 2 >= 0)
			{
				x = n->x;
				y = n->y - 2;
			}
			else continue;
			break;
		}
		dest = (*nodes) + x + y * width;

		if (dest->displayCharacter == ' ')
		{
			if (dest->parent != NULL) continue;

			dest->parent = n;

			(*nodes)[n->x + (x - n->x) / 2 + (n->y + (y - n->y) / 2) * width].displayCharacter = ' ';

			return dest;
		}
	}
	return n->parent;
}

void setDirection(Node *n, const int width, const int height, int *x, int* y)
{

	char dir;

	dir = (1 << (rand() % 4));

	//if (~n->directionsToExplore & dir)
	//	continue;

	n->directionsToExplore &= ~dir;

	switch (dir)
	{
	case 1:
		if (n->x + 2 < width)
		{
			x = n->x + 2;
			y = n->y;
		}
		//else continue;
		break;

	case 2:
		if (n->y + 2 < height)
		{
			x = n->x;
			y = n->y + 2;
		}
		//else continue;
		break;

	case 4:
		if (n->x - 2 >= 0)
		{
			x = n->x - 2;
			y = n->y;
		}
		//else continue;
		break;

	case 8:
		if (n->y - 2 >= 0)
		{
			x = n->x;
			y = n->y - 2;
		}
		//else continue;
		break;
	}
}

void setupStartNode(Node ** start, Node ** last, Node ** nodes,const int width)
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