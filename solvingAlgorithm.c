#include "libraries.h"


void solvingAlgorithm(Node **nodes, const int width, const int height) {
	enum directions { right = 0, down = 1, up = 2, left = 3, deadEnd = 4 };
	char displayCharacter = (char)219;
	WayOut *wayOutHead = NULL, *current = NULL;
	int wayToCheck = 0, possibleWays = 0;
	//osobna funnkcja 
	wayOutHead = malloc(sizeof(WayOut));
	wayOutHead->node = &(*nodes)[width];
	wayOutHead->previous = NULL;
	wayOutHead->next = NULL;

	current = wayOutHead;
	current->node->displayCharacter = displayCharacter;
	current->node->isVisited = true;

	do {
		current->next = malloc(sizeof(WayOut));

		switch (wayToCheck) {
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
			possibleWays = 0;
			do {
				possibleWays = countPossibleWays(current, width);
				if (possibleWays == 0) {
					free(current->next);
					current->next = NULL;
					current->node->displayCharacter = ' ';
					current = current->previous;
					free(current->next);
					current->next = NULL;
				}
				//system("cls");
				//draw(width, height, *nodes);
			//	Sleep(100);
			} while (possibleWays == 0);
			break;
		}
		if (wayToCheck != deadEnd) {
			current->next->previous = current;
			current = current->next;
			current->next = NULL;
			current->node->displayCharacter = displayCharacter;
			current->node->isVisited = true;
		}

		//system("cls");
		//draw(width, height, *nodes);
		//Sleep(100);
		wayToCheck = nextDirection(current, width);
	} while (current->node != &(*nodes)[((width) * (height - 1)) - 1]);
	
	current = wayOutHead;

	while (current->next != NULL) {
		current = current->next;
		free(current->previous);
		current->previous = NULL;
	}
	free(current);
	current = NULL;
}

int nextDirection(WayOut *current, int width) {
	current->node = current->node + 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node - 1;
		return 0;
	}

	current->node = current->node - 1;
	current->node = current->node + width;

	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node - width;
		return 1;
	}

	current->node = current->node - width;
	current->node = current->node - width;

	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node + width;
		return 2;
	}

	current->node = current->node + width;
	current->node = current->node - 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node + 1;
		return 3;
	}

	current->node = current->node + 1;
	return 4;
}

void comeBackFromDeadEnd(WayOut *current, const int width) {
	int possibleWays = 0;
	do {
		current->node->displayCharacter = ' ';
		possibleWays = countPossibleWays(&current, width);
		if (possibleWays == 0) {
			current = current->previous;
			free(current->next);
			current->next = NULL;
		}
	} while (possibleWays == 0);
}

int countPossibleWays(WayOut *current, const int width) {
	int possibleWays = 0;

	current->node = current->node + 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node - 1;
		possibleWays++;
	}
	else
		current->node = current->node - 1;

	current->node = current->node + width;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node - width;
		possibleWays++;
	}
	else
		current->node = current->node - width;

	current->node = current->node - width;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node + width;
		possibleWays++;
	}

	else
		current->node = current->node + width;

	current->node = current->node - 1;
	if (current->node->displayCharacter != '#' && current->node->isVisited == false) {
		current->node = current->node + 1;
		possibleWays++;
	}
	else
		current->node = current->node + 1;
	return possibleWays;
}


void dodajmyFunkcjêTestowaZebySprawdzicCzyDobrzeDzialaGit() {
	return 0;
}