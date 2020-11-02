#include<GL\glut.h>
#include<stdlib.h>
float tx,ty,th, sx = 0.0,sy = 0.0;
int move=2;
float xpos=-1;
float r,g,b;
void Di()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx,ty,0.0);
	glScalef(2,1.5,1);
    glRotatef(xpos,0,0,1);
	glBegin(GL_POLYGON) ; 
	          
      glColor3f ( 0.3, 1.0, 0.2);     
      glVertex2f( -0.1, -0.1 );       
      glVertex2f(  0.1, -0.1 );       
      glVertex2f(  0.1,  0.1 ); 
	  glVertex2f( -0.1,  0.1 ); 
	  
glEnd();
  	glFlush();
}

void XYZ(int v)
{


	if(move ==1)
{
	tx += 0.01;
	
	//ty += 0.01;
}	
if(move ==0)
{
	tx -= 0.01;
//	ty -= 0.01;
}
glutPostRedisplay();	
	glutTimerFunc(10,XYZ,v);
}



void mo(int but, int sta, int x, int y) 
{
  if (but == GLUT_LEFT_BUTTON && sta == GLUT_DOWN){
  
	move =1;

}
  else if (but == GLUT_RIGHT_BUTTON && sta == GLUT_DOWN) 
  move =0;
  
 }
 
 void idle()
{
	if (xpos<=1)
	{
		r=(rand()%9/8);
		g=(rand()%9/8);
		b=(rand()%9/8);
		xpos+=0.001;
	}
	else
	{
		xpos=xpos-2;
	}
	glutPostRedisplay();
}



void key(unsigned char k, int x, int y)
{
	if(k == 'l'|| k == 'L')
	move=1;

else	if(k == 'r'||k == 'R')
//	moving1();
		move=0;
}

int main( int argc, char** argv)
{
	glutInit( &argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Moving objects Program with Amazing Effects");
	glutDisplayFunc(Di);
	glutMouseFunc(mo);
	glutKeyboardFunc(key);
	glutTimerFunc(10,XYZ,0);
	glutIdleFunc(idle);

	glutMainLoop();
}
