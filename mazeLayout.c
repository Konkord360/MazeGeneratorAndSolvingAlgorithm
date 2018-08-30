#include "libraries.h"

void setDimensionsManually(int *width, int *height)
{
		printf("Set width: ");
		scanf("%d", &(*width));
		printf("\nset height: ");
		scanf("%d", &(*height));
}

void draw(const int width, const int height, const Node *nodes)
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

void validateSizes(const int height, const int width)
{
	if (width <= 0 || height <= 0)
	{
		printf("dimensions must be greater than 0!\n");
		exit(1);
	}

	else if (width + height < minimumSize)
	{
		printf("invalid maze size value!\n");
		exit(1);
	}

	else if (!(width % 2) || !(height % 2))
	{
		printf("dimensions must be odd!\n");
		exit(1);
	}
}

char viewMenu() {
	char choice = ' ';
	printf("1.Wygeneruj labirynt\n");
	printf("2.koniec\n");
	scanf(" %c", &choice);

	return choice;
}

void showTheWay(int *width, int *height, Node **nodes) {
	draw(*width, *height, *nodes);
	solvingAlgorithm(&(*nodes), *width, *height);
	draw(*width, *height, *nodes);
}