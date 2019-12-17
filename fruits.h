#ifndef FRUITS_H
#define FRUITS_H


int colorGen();
void randColor(int color);
void drawTile(float x2, float y2, int color);
void drawI(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawIVertical(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawS(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawSVertical(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawLLeft(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawL(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawLRight(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawLInv(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawT(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawTLeft(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawTRight(float x, float y, int colors1, int colors2, int colors3, int colors4);
void drawTInv(float x, float y, int colors1, int colors2, int colors3, int colors4);
int randX(int RANDOM);
int randY(int RANDOM);
int randShape();
void drawPoly(float x, float y, int randomShape, int colorRand1, int colorRand2, int colorRand3, int colorRand4);

#endif
