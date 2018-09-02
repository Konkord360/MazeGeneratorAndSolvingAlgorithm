#ifndef MAZELAYOUT_H_   
#define MAZELAYOUT_H_
#define dimensions 2
#include "mazeGenerator.h"

void setDimensionsManually(int *height, int *width);
void draw(const int width, const int height, const Node *nodes);
bool validateSizes(const int height, const int width);
int viewMenu();
void showTheWay(int *width, int *height, Node **nodes);

#endif