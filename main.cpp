#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "grid.h"
#include "fruits.h"

using namespace std;

#define COL 10
#define ROW 20

// Parameters controlling the size of the Robot's arm
const GLfloat BASE_HEIGHT      = 2.0;
const GLfloat BASE_WIDTH       = 5.0;
const GLfloat LOWER_ARM_HEIGHT = 12.0;
const GLfloat LOWER_ARM_WIDTH  = 0.5;
const GLfloat UPPER_ARM_HEIGHT = 12.0;
const GLfloat UPPER_ARM_WIDTH  = 0.5;


typedef struct{
	int rand_shape;
	int x;
	int y;
	int c1;
	int c2;
	int c3;
	int c4;
	int displayOnBoard =0;
}saveBlock;

int RANDOM = randShape();
float XRAND;
float YRAND;
int COLOR1 = colorGen();
int COLOR2 = colorGen();
int COLOR3 = colorGen();
int COLOR4 = colorGen();

int COUNT=0;


// Array of rotation angles 
enum {
    Base,
    LowerArm,
    UpperArm,
    NumberAngles
};

GLfloat angle_Rotate[NumberAngles] = {
0.0, 	//Base
0.0, 	//LowerArm
45.0, 	//UpperArm
};

GLfloat  Theta[NumberAngles] = { 0.0 };

GLint Axis = Base;  



void base()
{
	

glPushMatrix();

glBegin(GL_QUADS);      

    //Top 
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( 0, BASE_HEIGHT, 1);    
    glVertex3i(BASE_WIDTH, BASE_HEIGHT, 1);    
    glVertex3i(BASE_WIDTH, BASE_HEIGHT, -1);   
    glVertex3i( 0, BASE_HEIGHT, -1);   

    //Bottom
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( 0, 0, 1);
    glVertex3i(BASE_WIDTH, 0, 1); 
    glVertex3i(BASE_WIDTH, 0, -1); 
    glVertex3i(0, 0, -1); 
 
 	//Front
	glColor3f(0.0, 1.0, 0.0);
    glVertex3i( 0, 0, 1);   
    glVertex3i(BASE_WIDTH, 0, 1);   
    glVertex3i(BASE_WIDTH, BASE_HEIGHT, 1);  
    glVertex3i( 0, BASE_HEIGHT, 1);  
 	//Back
	glColor3f(0.0, 0.0, 1.0);
    glVertex3i( 0, 0, -1);   
    glVertex3i(BASE_WIDTH, 0, -1);    
    glVertex3i(BASE_WIDTH, BASE_HEIGHT, -1);   
    glVertex3i( 0, BASE_HEIGHT, -1);  

    //Left
	glColor3f(0.0, 1.0, 0.0);
    glVertex3i(0, 0, -1);   
    glVertex3i(0, 0, 1);    
    glVertex3i(0,BASE_HEIGHT, 1);   
    glVertex3i(0,BASE_HEIGHT, -1);   


    //Right
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( BASE_WIDTH, 0, 1);   
    glVertex3i( BASE_WIDTH, 0, -1);   
    glVertex3i( BASE_WIDTH, BASE_HEIGHT, -1);    
    glVertex3i( BASE_WIDTH, BASE_HEIGHT, 1);   
    
  glEnd();            
	

glPopMatrix();
}

//----------------------------------------------------------------------------

void upper_arm()
{
	

glPushMatrix();


glBegin(GL_QUADS);     

	//Top
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( 0, UPPER_ARM_HEIGHT, 1);   
    glVertex3i(1, UPPER_ARM_HEIGHT, 1);   
    glVertex3i(1, UPPER_ARM_HEIGHT, 0);   
    glVertex3i( 0, UPPER_ARM_HEIGHT, 0);

    //Bottom
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( 0, 0, 1);
    glVertex3i(1, 0, 1);    
    glVertex3i(1, 0, 0);
    glVertex3i(0, 0, 0);
 	
 	//Front
	glColor3f(0.0, 1.0, 1.0);
    glVertex3i( 0, 0, 1);
    glVertex3i(1, 0, 1);
    glVertex3i(1, UPPER_ARM_HEIGHT, 1);
    glVertex3i( 0, UPPER_ARM_HEIGHT, 1);
 
 	//Back
	glColor3f(0.0, 0.0, 1.0);
    glVertex3i( 0, 0, 0);  
    glVertex3i( 1, 0, 0);   
    glVertex3i(1, UPPER_ARM_HEIGHT, 0); 
    glVertex3i( 0, UPPER_ARM_HEIGHT, 0);  

    //Left
	glColor3f(0.0, 1.0, 0.0);
    glVertex3i(0, 0, 0); 
    glVertex3i(0, 0, 1);  
    glVertex3i(0,UPPER_ARM_HEIGHT, 1);  
    glVertex3i(0,UPPER_ARM_HEIGHT, 0); 

    //Right
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( UPPER_ARM_WIDTH, 0, 1);
    glVertex3i( UPPER_ARM_WIDTH, 0, 0);
    glVertex3i( UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, 0);
    glVertex3i( UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, 1); 
    
  glEnd();        

glPopMatrix();

}

//----------------------------------------------------------------------------

void lower_arm()
{ 

glPushMatrix();

glBegin(GL_QUADS);
	//Top Face
	glColor3f(0.0, 0.0, 0.0);
    glVertex3i( 0, LOWER_ARM_HEIGHT, 1);    
    glVertex3i(1, LOWER_ARM_HEIGHT, 1);    
    glVertex3i(1, LOWER_ARM_HEIGHT, 0);    
    glVertex3i( 0, LOWER_ARM_HEIGHT, 0);   

    //Bottom Face
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( 0, 0, 1);    
    glVertex3i(1, 0, 1);    
    glVertex3i(1, 0, 0);   
    glVertex3i(0, 0, 0);   
 
 	//Front Face
	glColor3f(1.0, 1.0, 0.0);
    glVertex3i( 0, 0, 1);   
    glVertex3i(1, 0, 1);   
    glVertex3i(1, LOWER_ARM_HEIGHT, 1); 
    glVertex3i( 0, LOWER_ARM_HEIGHT, 1);  
 
    //Back Face
	glColor3f(0.0, 0.0, 1.0);
    glVertex3i( 0, 0, 0);   
    glVertex3i( 1, 0, 0);  
    glVertex3i(1, LOWER_ARM_HEIGHT, 0);    
    glVertex3i( 0, LOWER_ARM_HEIGHT, 0);  

    //Left Face
	glColor3f(0.0, 1.0, 0.0);
    glVertex3i(0, 0, 0);  
    glVertex3i(0, 0, 1);   
    glVertex3i(0,LOWER_ARM_HEIGHT, 1);   
    glVertex3i(0,LOWER_ARM_HEIGHT, 0);   


    //Right Face
	glColor3f(1.0, 0.0, 0.0);
    glVertex3i( 1, 0, 1);    
    glVertex3i( 1, 0, 0);   
    glVertex3i( 1, LOWER_ARM_HEIGHT, 0);    
    glVertex3i( 1, LOWER_ARM_HEIGHT, 1);    
    
  glEnd();    

glPopMatrix();

}



void drawRobot(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();		
		glTranslatef(-3.5, -3.0, 0.0);
		glRotatef(angle_Rotate[Base], 0.0, 1.0, 0.0);
		base();
		glTranslatef(BASE_WIDTH/2 -0.5	, BASE_HEIGHT-1,0.0);
		glRotatef(-angle_Rotate[LowerArm], 0.0, 0.0, 1.0); 
		lower_arm();
		glTranslatef(0, LOWER_ARM_HEIGHT,0.0);
		glRotatef(-angle_Rotate[UpperArm], 0.0, 0.0, 1.0); 
		upper_arm();
	   
	glPopMatrix();
	
		
}
//----------------------------------------------------------------------------

void tilePos(){
	float xnew, ynew;
	xnew = -2.0;
	ynew = -1.5;
	xnew += LOWER_ARM_HEIGHT   * cos(M_PI/180.0 * (90.0 - angle_Rotate[LowerArm]));
	xnew += UPPER_ARM_HEIGHT  * cos(M_PI/180.0 * (90.0 - angle_Rotate[LowerArm] - angle_Rotate[UpperArm]));
	
	ynew += LOWER_ARM_HEIGHT  * sin(M_PI/180.0 * (90 - angle_Rotate[LowerArm]));
	
	ynew += UPPER_ARM_HEIGHT * sin(M_PI/180.0 * (90.0 - angle_Rotate[LowerArm] - angle_Rotate[UpperArm]));

	XRAND = xnew;

	YRAND = ynew;


}



saveBlock fruits[1000];
int boardColor[COL][ROW];

void drawTileOnBoard(float x2, float y2, int color){

	if(x2 < 0 || x2 > 9 || y2 < 0 || y2 > 19)
		color = 5;

	glBegin(GL_QUADS);        // Draw The Cube Using quads

	   	randColor(color); //TOP FACE
	    glVertex3i( x2, y2+1, -1);  
	    glVertex3i(x2+1, y2+1, -1);
	    glVertex3i(x2+1, y2+1, 0);
	    glVertex3i( x2, y2+1, 0);  

	    randColor(color); //BOTTOM FACE
	    glVertex3i( x2, y2, -1);   
	    glVertex3i(x2+1, y2, -1);  
	    glVertex3i(x2+1, y2, 0);  
	    glVertex3i(x2, y2, 0);   
	  
	    randColor(color);//FRONT FACE
	    glVertex3i( x2, y2, -1);  
	    glVertex3i(x2+1, y2, -1);  
	    glVertex3i(x2+1, y2+1, -1); 
	    glVertex3i( x2, y2+1, -1);  

	    randColor(color);//BACK FACE
	    glVertex3i( x2, y2, 0);    
	    glVertex3i( x2+1, y2, 0);    
	    glVertex3i(x2+1, y2+1, 0);  
	    glVertex3i( x2, y2+1, 0);    


	    randColor(color);//LEFT FACE
	    glVertex3i(x2, y2, 0); 
	    glVertex3i(x2, y2, -1); 
	    glVertex3i(x2,y2+1, -1);
	    glVertex3i(x2,y2+1, 0);

	    randColor(color);//RIGHT FACE
	    glVertex3i( x2+1, y2, -1); 
	    glVertex3i( x2+1, y2, 0); 
	    glVertex3i( x2+1, y2+1, 0);  
	    glVertex3i( x2+1, y2+1, -1);   
	    
  glEnd();            // End Drawing The Cube
}



void drawIBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){//drawn towards righ up
	drawTileOnBoard(x,y,colors1);
	x++;
	drawTileOnBoard(x,y,colors2);
	x++;
	drawTileOnBoard(x,y,colors3);
	x++;
	drawTileOnBoard(x,y,colors4);

}

void drawIVerticalBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){//drawn bottom up
	drawTileOnBoard(x,y,colors1);
	y++;
	drawTileOnBoard(x,y,colors2);
	y++;
	drawTileOnBoard(x,y,colors3);
	y++;
	drawTileOnBoard(x,y,colors4);
}

void drawSBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	x++;
	drawTileOnBoard(x,y,colors2);
	y++;
	drawTileOnBoard(x,y,colors3);
	x++;
	drawTileOnBoard(x,y,colors4);
}

void drawSVerticalBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	y++;
	drawTileOnBoard(x,y,colors2);
	x--;
	drawTileOnBoard(x,y,colors3);
	y++;
	drawTileOnBoard(x,y,colors4);
}

void drawLLeftBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	y++;
	drawTileOnBoard(x,y,colors2);
	x++;
	drawTileOnBoard(x,y,colors3);
	x++;
	drawTileOnBoard(x,y,colors4);
}

void drawLBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	x--;
	drawTileOnBoard(x,y,colors2);
	y++;
	drawTileOnBoard(x,y,colors3);
	y++;
	drawTileOnBoard(x,y,colors4);
}

void drawLRightBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	x++;
	drawTileOnBoard(x,y,colors2);
	x++;
	drawTileOnBoard(x,y,colors3);
	y++;
	drawTileOnBoard(x,y,colors4);
}

void drawLInvBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
	drawTileOnBoard(x,y,colors1);
	y++;
	drawTileOnBoard(x,y,colors2);
	y++;
	drawTileOnBoard(x,y,colors3);
	x--;
	drawTileOnBoard(x,y,colors4);
}

void drawTBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTileOnBoard(x,y,colors1);
        y++;
        x--;
        drawTileOnBoard(x,y,colors2);
        x++;
        drawTileOnBoard(x,y,colors3);
        x++;
        drawTileOnBoard(x,y,colors4);
}

void drawTLeftBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTileOnBoard(x,y,colors1);
        y++;
        drawTileOnBoard(x,y,colors2);
        x--;
        drawTileOnBoard(x,y,colors3);
        x++;
        y++;
        drawTileOnBoard(x,y,colors4);
}


void drawTRightBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTileOnBoard(x,y,colors1);
        y++;
        drawTileOnBoard(x,y,colors2);
        x++;
        drawTileOnBoard(x,y,colors3);
        y++;
        x--;
        drawTileOnBoard(x,y,colors4);
}

void drawTInvBoard(float x, float y, int colors1, int colors2, int colors3, int colors4){
        drawTileOnBoard(x,y,colors1);
        x++;
        drawTileOnBoard(x,y,colors2);
        x++;
        drawTileOnBoard(x,y,colors3);
        x--;
        y++;
        drawTileOnBoard(x,y,colors4);
}



void drawPolyBoard(float x, float y, int randomShape, int colorRand1, int colorRand2, int colorRand3, int colorRand4){

  

	bool flag2 = false;
	while(flag2 == false){
		switch(randomShape){
			case 0:
				
				drawIVerticalBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 1:
		
				drawIBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 2:
			
				drawSBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 3:
			
				drawSVerticalBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 4:
		
                drawLLeftBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 5:
			
				drawLBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 6:
			
                drawLRightBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
			case 7:
			
                drawLInvBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
				flag2 = true;
				break;
            case 8:
           
                drawTBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 9:
            
                drawTInvBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 10:
         
                drawTLeftBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;
            case 11:
      
                drawTRightBoard(x,y,colorRand1, colorRand2, colorRand3, colorRand4);
                flag2 = true;
                break;

			default:
				flag2 = false;
				continue;
		}
	}
}

void drawBoardTile(){
	for(int x=0; x < 10; x++){
		for(int y=0; y < 20; y++){
			int colorVal = boardColor[x][y];
			if(boardColor[x][y] > -1 && colorVal != 5){
				fruits[COUNT].displayOnBoard = 1;
				drawTileOnBoard(x, y, colorVal);
			}
		}
	}
}

int check(){

	int Dropable = 1;

	if(fruits[COUNT].x < 0 ||  fruits[COUNT].x > 9 || fruits[COUNT].y < 0 || fruits[COUNT].y > 19){
		Dropable = 0;
		return	Dropable;
	}
 
	switch(fruits[COUNT].rand_shape){
			case 0://IVertical
				if( boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 || 
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+2] > -1||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+3] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
			case 1://I
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y] > -1||
				boardColor[fruits[COUNT].x+3][fruits[COUNT].y] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
			case 2://S
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1||
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] > -1 ||
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
			case 3://SVertical
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] > -1){
                	fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
                }
				break;
            case 4://LLeft
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] > -1 ||
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
			case 5://L
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] > -1 ||
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
            case 6://LRight
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
            case 7://LInv
				if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
				boardColor[fruits[COUNT].x][fruits[COUNT].y+2] > -1 ||
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] > -1){
					fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
				}
				break;
	        case 8://T
                if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] > -1||
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] > -1){
                	fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;	
                }
                break;
	        case 9://TInv
                if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x+2][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] > -1){
                	fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
                }
                break;
	        case 10://TLeft
                if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x][fruits[COUNT].y+2] > -1){
                	fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
                }
                break;
	        case 11://TRight
                if(boardColor[fruits[COUNT].x][fruits[COUNT].y] > -1 ||
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] > -1 ||
                boardColor[fruits[COUNT].x][fruits[COUNT].y+2] > -1){
                	fruits[COUNT].c1 = 5;
					fruits[COUNT].c2 = 5;
					fruits[COUNT].c3 = 5;
					fruits[COUNT].c4 = 5;
					Dropable = 0;
                }
                break;
		}//Switch ends

	

	return Dropable;

}

void updateBoardColor(){
	switch(fruits[COUNT].rand_shape){
			case 0://IVertical			                                                                                                                                                                                          )
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+2] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+3] = fruits[COUNT].c4;
				break;
			case 1://I
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x+3][fruits[COUNT].y] = fruits[COUNT].c4;
				break;
			case 2://S
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] = fruits[COUNT].c2;
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] = fruits[COUNT].c4;
				break;
			case 3://SVertical
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
                 boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] = fruits[COUNT].c3;
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] = fruits[COUNT].c4;
				break;
                        case 4://LLeft
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] = fruits[COUNT].c4;
				break;
			case 5://L
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] = fruits[COUNT].c4;
				break;
                        case 6://LRight
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x+1][fruits[COUNT].y] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x+2][fruits[COUNT].y+1] = fruits[COUNT].c4;
				break;
                        case 7://LInv
				boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
				boardColor[fruits[COUNT].x][fruits[COUNT].y+2] = fruits[COUNT].c3;
				boardColor[fruits[COUNT].x-1][fruits[COUNT].y+2] = fruits[COUNT].c4;
				break;
	        case 8://T
                boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] = fruits[COUNT].c2;
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c3;
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] = fruits[COUNT].c4;
                break;
	        case 9://TInv
                boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y] = fruits[COUNT].c2;
                boardColor[fruits[COUNT].x+2][fruits[COUNT].y] = fruits[COUNT].c3;
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] = fruits[COUNT].c4;
                break;
	        case 10://TLeft
                boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
                boardColor[fruits[COUNT].x-1][fruits[COUNT].y+1] = fruits[COUNT].c3;
                boardColor[fruits[COUNT].x][fruits[COUNT].y+2] = fruits[COUNT].c4;
                break;
	        case 11://TRight
                boardColor[fruits[COUNT].x][fruits[COUNT].y] = fruits[COUNT].c1;
                boardColor[fruits[COUNT].x][fruits[COUNT].y+1] = fruits[COUNT].c2;
                boardColor[fruits[COUNT].x+1][fruits[COUNT].y+1] = fruits[COUNT].c3;
                boardColor[fruits[COUNT].x][fruits[COUNT].y+2] = fruits[COUNT].c4;
                break;
		}//Switch ends
}


void putTile(){
	XRAND = (floor(XRAND));
	YRAND = (floor(YRAND));
	
	if(fruits[COUNT].c1 == 5 || fruits[COUNT].c2 == 5 ||fruits[COUNT].c3 ==  5 ||fruits[COUNT].c4 ==  5){
		return;
	}

    fruits[COUNT].c1 = COLOR1;
    fruits[COUNT].c2 = COLOR2;
    fruits[COUNT].c3 = COLOR3;
    fruits[COUNT].c4 = COLOR4;
    fruits[COUNT].rand_shape = RANDOM;
    fruits[COUNT].x = XRAND;
    fruits[COUNT].y = YRAND;
    updateBoardColor();
	drawBoardTile();
	COUNT++;
	RANDOM = randShape();
	tilePos();
	COLOR1 = colorGen();
	COLOR2 = colorGen();
	COLOR3 = colorGen();
	COLOR4 = colorGen();
}

void
keyboard( unsigned char key, int x, int y )
{

	if(key =='w' || key =='W'){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		Axis =UpperArm;
		angle_Rotate[Axis] -= 4;
		
		tilePos();
		glPopMatrix();
	}
	

	if(key =='s' || key =='S'){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		Axis = UpperArm;
		angle_Rotate[Axis] += 4;
	
		tilePos();
		glPopMatrix();

	}
	

	if(key =='a' || key =='A'){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		Axis = LowerArm;
		
		angle_Rotate[Axis] -= 4;

		tilePos();

		glPopMatrix();

	}
	

	if(key =='d' || key =='D'){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		Axis = LowerArm;
		
		angle_Rotate[Axis] += 4;
		
		tilePos();
		
		// lower_arm();
		glPopMatrix();
		
	}

	if(key == ' '){
		if(check() == 0){
			return;
		}
			
		putTile();
		glutPostRedisplay();	
		
	}
	
   if(key == 'r' || key == 'R'){

		angle_Rotate[UpperArm] = 45.0;
		angle_Rotate[LowerArm] = 0.0;
		COUNT =0;
		RANDOM = randShape();
		tilePos();
		COLOR1 = colorGen();
		COLOR2 = colorGen();
		COLOR3 = colorGen();
		COLOR4 = colorGen();
		glClearColor(1.0,1.0,1.0,1.0);
		makeGrid(COL,ROW);
	}

	if(key=='q' || key == 'Q'){
		exit(EXIT_SUCCESS);
	}
	
	glutPostRedisplay();

}

void specialKeyboard(int key, int x, int y){
	

	if(glutGetModifiers() == 2 && key == GLUT_KEY_LEFT){
		// Incrase the joint angle

		glMatrixMode(GL_PROJECTION);
		glRotatef(-5.0, 0.0, 1.0, 0.0);
		if ( angle_Rotate[Axis] > 360.0 ) { angle_Rotate[Axis] -= 360.0; }
		
	    glMatrixMode(GL_MODELVIEW);
	}
	
	if (glutGetModifiers() == 2 && key == GLUT_KEY_RIGHT){
		glMatrixMode(GL_PROJECTION);
		glRotatef(5.0, 0.0, 1.0, 0.0);
		if ( angle_Rotate[Axis] < 0.0 ) { angle_Rotate[Axis] += 360.0; }
		
	    glMatrixMode(GL_MODELVIEW);
		
	}

	if(key == GLUT_KEY_UP){

            int temp;

                switch(RANDOM){
                    case 0://IVertical
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM=1;
                            break;
                    case 1://I
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 0;
                            break;
                    case 2://S
                            RANDOM = 3;
                            break;
                    case 3://SVertical
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 2;
                            break;
                    case 4://LLeft
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 5;
                            break;
                    case 5://L
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 6;
                            break;
                    case 6://LRight
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 7;
                            break;
                    case 7://LInv
                            temp=COLOR1;
                            COLOR1=COLOR4;
                            COLOR4=temp;
                            temp=COLOR2;
                            COLOR2=COLOR3;
                            COLOR3=temp;
                            RANDOM = 4;
                            break;
                    case 8://T
                    		temp=COLOR1;
                            COLOR1=COLOR2;
                            COLOR2=temp;
                            RANDOM = 11;
                            break;
                    case 9://TInv
                    		temp=COLOR3;
                    		COLOR3=COLOR4;
                    		COLOR4=temp;
                            RANDOM = 10;
                            break;
                    case 10://TLeft
                    		temp=COLOR1;
                    		COLOR1=COLOR3;
                    		COLOR3=COLOR2;
                    		COLOR2=COLOR4;
                    		COLOR4=temp;
                            RANDOM = 8;
                            break;
                    case 11://TRight
                    		temp = COLOR3;
                    		COLOR3=COLOR1;
                    		COLOR1=COLOR4;
                    		COLOR4=temp;
                            RANDOM = 9;
                            break;
                        }
	}

	glutPostRedisplay();

}



void init(){
    glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glOrtho(-15,25, -15,25,-50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	for(int k=0;k<10;k++){
            for(int j=0; j<	20; j++){
                 boardColor[k][j]=-1;
            }
    }
	makeGrid(COL,ROW);		
}


void callbackDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH);

	// Axis = Grid;
	glMatrixMode(GL_MODELVIEW);

	drawGrid();	

	drawRobot();


        fruits[COUNT].c1 = COLOR1;
        fruits[COUNT].c2 = COLOR2;
        fruits[COUNT].c3 = COLOR3;
        fruits[COUNT].c4 = COLOR4;
        fruits[COUNT].rand_shape = RANDOM;
        fruits[COUNT].x = XRAND;
        fruits[COUNT].y = YRAND;


	for(int i = 0; i <= COUNT;i++){

		if(check() == 0){ 
			fruits[i].c1 = 5;
			fruits[i].c2 = 5;
			fruits[i].c3 = 5;
			fruits[i].c4 = 5;
 
		}

		if(fruits[i].displayOnBoard == 1){

			for(int xCord = 0; xCord < 10; xCord++){
				for(int yCord = 0; yCord < 20; yCord++){
					if(boardColor[xCord][yCord] > -1){
						drawTileOnBoard(xCord, yCord, boardColor[xCord][yCord]);
					}
				}
			}
			
		}else{
			drawPoly(fruits[i].x, fruits[i].y, fruits[i].rand_shape, fruits[i].c1, fruits[i].c2, fruits[i].c3, fruits[i].c4);
		}
			
	}//for ends
	
    glutSwapBuffers();
}


int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(525,0);
	glutInitWindowSize(720,720);
    glutInitContextProfile( GLUT_CORE_PROFILE );
	glutCreateWindow("Falling Fruitris");


	glewExperimental = GL_TRUE;
	glewInit();
	
	init();
	// register callbacks
	tilePos();
	glutDisplayFunc(callbackDisplay);
	glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
