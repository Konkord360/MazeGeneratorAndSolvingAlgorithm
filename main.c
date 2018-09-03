#include "includes.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	Node *start = NULL, *last = NULL, *nodes = NULL;
	int width = 0, height = 0, choice = 0;
	enum choice { generateLabirynth = 1, endProgram = 2};
	bool areSizesValid = false;

	while (choice != endProgram)
	{
		if (argc == 1)
			choice = viewMenu();

		else
		{
			getValuesFromCommandLineArguments(&height, &width, argv);
			choice = generateLabirynth;
		}

		switch (choice)
		{
		case generateLabirynth:
			do {
				if(argc == 1)
					setDimensionsManually(&width, &height);

				areSizesValid = validateSizes(height, width);
				argc = 1;
			} while (!areSizesValid);

			initialize(width, height, &nodes);
			setupStartNodeForGenerator(&start, &last, &nodes, width);
			while ((last = link(last, width, height, &nodes)) != start);
			setExitAndEntrance(width, height, &nodes);
			break;

		case endProgram:
			_CrtDumpMemoryLeaks();
			return 0;
		}
		showTheWay(&width, &height, &nodes);
		resetLabirynth(&width, &height, &nodes);
		system("pause");
	}
	return 0;
}