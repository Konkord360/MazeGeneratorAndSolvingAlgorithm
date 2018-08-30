#include "libraries.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	Node *start = NULL, *last = NULL, *nodes = NULL;
	int width=0, height=0;
	char choice = ' ';

	while (choice != '2') 
	{
		if (argc == 1)
			choice = viewMenu();

		else
		{
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
			_CrtDumpMemoryLeaks();
			return 0;
		}
		showTheWay(&width, &height, &nodes);
		resetLabirynth(&width, &height, &nodes);
		system("pause");
	}
	return 0;
}