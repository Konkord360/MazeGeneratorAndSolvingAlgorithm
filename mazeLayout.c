#include "libraries.h"

//void setSizes(int *height, int*width)
//{
//		setDimensionsManually(&(*height), &(*width));
//	else {
//		*height = atoi(*argv[1]);
//		*width = atoi(*argv[2]);
//		printf("wysokosc: %d \n szerokosc: %d ", height, width);
//		system("pause");
//		argc = 1;
//}

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