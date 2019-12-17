#include "grid.h"
#include "fruits.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>


using namespace std;

int xCoordinate , yCoordinate ;

void makeGrid(int x, int y){

	xCoordinate = x;
	yCoordinate = y;
}

void box (int x, int y){

  
    float scale = 1;
    glPushMatrix();

	glBegin(GL_LINE_LOOP);    

	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( x, y+scale, 0);  
    glVertex3i(x+scale, y+scale, 0);    
    glVertex3i(x+scale, y+scale, -1);  
    glVertex3i( x, y+scale, -1);  

    glEnd();

    glBegin(GL_LINE_LOOP);     
    
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( x, y, 0);    
    glVertex3i(x+scale, y, 0);   
    glVertex3i(x+scale, y, -1);  
    glVertex3i(x, y, -1);  


   

	glBegin(GL_LINE_LOOP);        
  
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( x, y, 0);   
    glVertex3i(x+scale, y, 0);   
    glVertex3i(x+scale, y+scale, 0);  
    glVertex3i( x, y+scale, 0);   
  glEnd();          



	glBegin(GL_LINE_LOOP);      
   
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( x, y, -1);   
    glVertex3i( x+scale, y, -1);   
    glVertex3i(x+scale, y+scale, -1);  
    glVertex3i( x, y+scale, -1);   
  glEnd();          



	glBegin(GL_LINE_LOOP);      
   
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i(x, y, -1);  
    glVertex3i(x, y, 0);    
    glVertex3i(x,y+scale, 0);    
    glVertex3i(x,y+scale, -1);  
  glEnd();            


	glBegin(GL_LINE_LOOP);       

	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( x+scale, y, 0);  
    glVertex3i( x+scale, y, -1);   
    glVertex3i( x+scale, y+scale, -1);    
    glVertex3i( x+scale, y+scale, 0);    
    
  glEnd();          

  glPopMatrix();


}

void drawGrid(){

	for (int i = 0; i < xCoordinate; i++){

		for (int j = 0; j < yCoordinate; j++){
			box(i,j);

		}
	}

}
