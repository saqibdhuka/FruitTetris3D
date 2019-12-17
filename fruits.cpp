#include "fruits.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int colorGen(){
	return (rand()%4);
}


void randColor(int color){

	bool flag = false;
	while (flag == false){



		switch (color){

			case -1:
				glColor3f(0.0,0.0,0.0);
				flag = true;
				break;
			case 0: //RED
				glColor3f(1.0,0.0,0.0);
				flag = true;
				break;

			case 1:	//YELLOW
				glColor3f(1.0,1.0,0.0);
				flag = true;
				break;

			case 2://PURPLE
				glColor3f(1.0,0.0,1.0);
				flag = true;
				break;

			case 3://Green
				glColor3f(0.0,1.0,0.0);
				flag = true;
				break;

			case 4://Orange
				glColor3f(1.0,0.5,0.0);
				flag = true;
				break;

			case 5://Grey
				glColor3f(0.5, 0.5, 0.5);
				flag = true;
				break;

			default:
				flag = false;
				continue;
		}

	}
}

int randX(int RANDOM){

	srand(time(NULL));
	int xRand = rand() %6; // Between 0 and 6


	switch(RANDOM){

		case 3://SVertical
			if(xRand <= 0 ){
				xRand++;
			}
			break;
		case 5://L
			if(xRand == 0){
				xRand++;
			}
			break;
                case 7://LInv
			if(xRand ==0){
				xRand++;
			}
			break;
		default:
			break;
	}

	return xRand;

}



int randY(int RANDOM){
	int yRand;

	switch(RANDOM){
		case 0://IVertical
			yRand=16;
			break;
		case 1://I
			yRand =19;
			break;
		case 2://S
			yRand=18;
			break;
		case 3://SVertical
			yRand = 17;
			break;
                case 4://LLeft
			yRand = 18;
			break;
		case 5://L
			yRand = 17;
			break;
                case 6://LRight
			yRand =18;
			break;
                case 7://LInv
			yRand = 17;
			break;
                case 8://T
                        yRand = 18;
                        break;
                case 9://TInv
                        yRand = 18;
                        break;
                case 10://TLeft
                        yRand = 17;
                        break;
                case 11://TRight
                        yRand = 17;
                        break;

                }


	return yRand;
}



int randShape(){
	srand(time(NULL));
        int random = rand() % 13;
	return random;

}

//SHAPES

void drawTile(float x2, float y2, int color){

	if(x2 < 0 || x2 > 9 || y2 < 0 || y2 > 19)
		color = 5;

	glBegin(GL_QUADS);        

	    randColor(color); //TOP FACE
	    glVertex3i( x2, y2+1, 1);    
	    glVertex3i(x2+1, y2+1, 1);  
	    glVertex3i(x2+1, y2+1, 0);   
	    glVertex3i( x2, y2+1, 0);    

	    randColor(color); //BOTTOM FACE
	    glVertex3i( x2, y2, 1);    
	    glVertex3i(x2+1, y2, 1);  
	    glVertex3i(x2+1, y2, 0);   
	    glVertex3i(x2, y2, 0);    
	  
	    randColor(color);//FRONT FACE
	    glVertex3i( x2, y2, 1);  
	    glVertex3i(x2+1, y2, 1); 
	    glVertex3i(x2+1, y2+1, 1);  
	    glVertex3i( x2, y2+1, 1);  

	    randColor(color);//BACK FACE
	    glVertex3i( x2, y2, 0);  
	    glVertex3i( x2+1, y2, 0);  
	    glVertex3i(x2+1, y2+1, 0);   
	    glVertex3i( x2, y2+1, 0); 


	    randColor(color);//LEFT FACE
	    glVertex3i(x2, y2, 0);   
	    glVertex3i(x2, y2, 1);   
	    glVertex3i(x2,y2+1, 1);    
	    glVertex3i(x2,y2+1, 0);   

	    randColor(color);//RIGHT FACE
	    glVertex3i( x2+1, y2, 1);   
	    glVertex3i( x2+1, y2, 0); 
	    glVertex3i( x2+1, y2+1, 0);  
	    glVertex3i( x2+1, y2+1, 1);  
	    
  glEnd();          
}


void drawI(float x, float y, int colors1, int colors2, int colors3, int colors4){//drawn towards righ up
	drawTile(x,y,colors1);
	x++;
	drawTile(x,y,colors2);
	x++;
	drawTile(x,y,colors3);
	x++;
	drawTile(x,y,colors4);

}

void drawIVertical(float x, float y, int colors1, int colors2, int colors3, int colors4){//drawn bottom up
	drawTile(x,y,colors1);
	y++;
	drawTile(x,y,colors2);
	y++;
	drawTile(x,y,colors3);
	y++;
	drawTile(x,y,colors4);
}

void drawS(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	x++;
	drawTile(x,y,colors2);
	y++;
	drawTile(x,y,colors3);
	x++;
	drawTile(x,y,colors4);
}

void drawSVertical(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	y++;
	drawTile(x,y,colors2);
	x--;
	drawTile(x,y,colors3);
	y++;
	drawTile(x,y,colors4);
}

void drawLLeft(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	y++;
	drawTile(x,y,colors2);
	x++;
	drawTile(x,y,colors3);
	x++;
	drawTile(x,y,colors4);
}

void drawL(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	x--;
	drawTile(x,y,colors2);
	y++;
	drawTile(x,y,colors3);
	y++;
	drawTile(x,y,colors4);
}

void drawLRight(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	x++;
	drawTile(x,y,colors2);
	x++;
	drawTile(x,y,colors3);
	y++;
	drawTile(x,y,colors4);
}

void drawLInv(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTile(x,y,colors1);
	y++;
	drawTile(x,y,colors2);
	y++;
	drawTile(x,y,colors3);
	x--;
	drawTile(x,y,colors4);
}

void drawT(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTile(x,y,colors1);
        y++;
        x--;
        drawTile(x,y,colors2);
        x++;
        drawTile(x,y,colors3);
        x++;
        drawTile(x,y,colors4);
}

void drawTLeft(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTile(x,y,colors1);
        y++;
        drawTile(x,y,colors2);
        x--;
        drawTile(x,y,colors3);
        x++;
        y++;
        drawTile(x,y,colors4);
}


void drawTRight(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTile(x,y,colors1);
        y++;
        drawTile(x,y,colors2);
        x++;
        drawTile(x,y,colors3);
        y++;
        x--;
        drawTile(x,y,colors4);
}

void drawTInv(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTile(x,y,colors1);
        x++;
        drawTile(x,y,colors2);
        x++;
        drawTile(x,y,colors3);
        x--;
        y++;
        drawTile(x,y,colors4);
}



void drawPoly(float x, float y, int randomShape, int colorRand1, int colorRand2, int colorRand3, int colorRand4){


	bool flag2 = false;
	while(flag2 == false){
		switch(randomShape){
			case 0:
			
				drawIVertical(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 1:
			
				drawI(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 2:
			
				drawS(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 3:
				drawSVertical(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 4:
                drawLLeft(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 5:
				drawL(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 6:
			    drawLRight(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 7:
				
                drawLInv(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
            case 8:
               
                drawT(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 9:
               
                drawTInv(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 10:
                    
                drawTLeft(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 11:
                    
                drawTRight(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;

			default:
				flag2 = false;
				continue;
		}
	}
}
