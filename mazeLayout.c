#include "includes.h"

void setDimensionsManually(int *width, int *height)
{
		printf("Set width: ");
		scanf("%d", &(*width));
		printf("\nset height: ");
		scanf("%d", &(*height));
}

void drawMaze(const int width, const int height, const Node *nodes)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", nodes[j + i * width].displayCharacter);
		}
		printf("\n");
	}
}

bool validateSizes(const int height, const int width)
{
	if (width <= 0 || height <= 0)
	{
		printf("dimensions must be greater than 0!\n");
		return false;
	}

	else if (width + height < minimumSize)
	{
		printf("invalid maze size value!\n");
		return false;
	}

	else if (!(width % 2) || !(height % 2))
	{
		printf("dimensions must be odd!\n");
		return false;
	}
	return true;
}

int viewMenu() 
{
	int choice = 0;
	printf("1.Wygeneruj labirynt\n");
	printf("2.koniec\n");
	scanf(" %d", &choice);

	return choice;
}

void showTheWay(int *width, int *height, Node **nodes)
{
	drawMaze(*width, *height, *nodes);
	solvingAlgorithm(&(*nodes), *width, *height);
	drawMaze(*width, *height, *nodes);
}