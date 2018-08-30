#ifndef MAZELAYOUT_H_   
#define MAZELAYOUT_H_
#define dimensions 2
#include "mazeGenerator.h"

void setDimensionsManually(int *height, int *width);
void draw(const int width, const int height, const Node *nodes);
void validateSizes(const int height, const int width);
char viewMenu();

#endif