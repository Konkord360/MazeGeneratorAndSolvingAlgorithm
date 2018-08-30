#include "libraries.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	Node *start = NULL, *last = NULL, *nodes = NULL;
	int width=0, height=0;
	char choice = ' ';
	while (choice != '2') {
		width = 0;
		height = 0;

		if (argc == 1) {
			printf("1.Wygeneruj labirynt\n");
			printf("2.koniec\n");
			choice = ' ';
			scanf(" %c", &choice);
		}

		else {
			height = atoi(argv[1]);
			width = atoi(argv[2]);
			choice = '1';
			argc = 1;
		}

		switch (choice)
		{
		case '1':
			if(height == 0)
				setDimensionsManually(&width, &height);

			validateSizes(height, width);
			initialize(width, height, &nodes);
			
			setupStartNode(&start, &last, &nodes, width);
			while ((last = link(last, width, height, &nodes)) != start);
			break;

		case '2':
			free(nodes);
			nodes = NULL;
			_CrtDumpMemoryLeaks();
			return 0;
			break;
		}

		draw(width, height, nodes);
		solvingAlgorithm(&nodes, width, height);
		draw(width, height, nodes);
		free(nodes);
		nodes = NULL;
		system("pause");
		
	}
	return 0;
}