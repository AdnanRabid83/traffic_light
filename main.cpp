#include<GL/glut.h>
#include <stdio.h>
#include <string>
#include <iostream>
#define ESCAPE 27
#define HIGH 1
#define LOW 0.2
#define RED 0
#define YELLOW 1
#define GREEN 2
#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);

using namespace std;
GLint bus1 = -300;
int view=0;
bool rl2[] = {false, false, true};

void text(int x, int y, string s, int font) {

	int i=0;

	glColor3f(0.0,0.0,0.8);

	glRasterPos2f(x,y);

	for(i=0;i<s.length();i++) {

		if(font==1)

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

		else if(font==2)

			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);

		else if(font==3) {

			glColor3f(1.0,0.0,0.0);

			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);

		}

	}

}

void First_win() {

	glClearColor(0.0,1.0,0.6,0.0);

	text(370,700,"TRAFFIC SIGNAL",1);

	text(400,620,"INSTRUCTIONS:",2);
	text(400,540,"For Traffic Light",2);

	text(400,460,"A -- Red Light",2);

	text(400,420,"S -- Yellow Light",2);

	text(400,380,"D -- Green Light",2);

	text(340,100," PRESS SPACEBAR TO ENTER ",3);

	glutPostRedisplay();

}

void init() {

	glClearColor(0, 0, 0, 0);

	glPointSize(5.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0.0,1000,0.0,800,50.0,-50.0);

	glutPostRedisplay();

}
void bus_chalao() {

	if(rl2[GREEN] || bus1 > 700) {

		bus1 -=2;

	}

	if(!rl2[GREEN] && (bus1 < -650 && bus1 > -720)) {

		bus1 += 2;

	}

	if((rl2[RED] || rl2[YELLOW]) && (bus1 > -650 || bus1 < -720)) {

		bus1 -= 2;

	}

	if(bus1 < -1650) {

		bus1 = -300;

	}

}
void bus() {

	glPushMatrix();

	glTranslated(bus1,-100,0);

	glScaled(50.0,50.0,0.0);

	glColor3f(0.5,0.0,0.0);

	//bus out line

	glBegin(GL_POLYGON);

	glVertex2f(25,8);

	glVertex2f(25,9.5);

	glVertex2f(26,11);

	glVertex2f(32,11);

	glVertex2f(32,8);

	glEnd();

	//window frame

	glColor3f(0,0.1,1);

	glBegin(GL_POLYGON);

	glVertex2f(26.1,9.5);

	glVertex2f(26.1,10.5);

	glVertex2f(31.8,10.5);

	glVertex2f(31.8,9.5);

	glEnd();


	//small windows

	glColor3f(0,1,1);

	glBegin(GL_POLYGON);

	glVertex2f(27.8,9.6);

	glVertex2f(27.8,10.4);

	glVertex2f(29,10.4);

	glVertex2f(29,9.6);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(29.1,9.6);

	glVertex2f(29.1,10.4);

	glVertex2f(30.2,10.4);

	glVertex2f(30.2,9.6);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(30.3,9.6);

	glVertex2f(30.3,10.4);

	glVertex2f(31.7,10.4);

	glVertex2f(31.7,9.6);

	glEnd();

	//driver window

	glColor3f(0,0.8,1);

	glBegin(GL_POLYGON);

	glVertex2f(25,9.5);

	glVertex2f(26,11);

	glVertex2f(26,9.5);

	glEnd();

	glPopMatrix();

	//tyre

	glPushMatrix();//front tyre

	glTranslated(bus1+1220,250,0.0);

	glScaled(20.0,20.0,0.0);

	glColor3f(0.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex2f(3.0,2.5);

	glVertex2f(3.0,2.6);

	glVertex2f(3.15,3.1);

	glVertex2f(3.2,3.2);

	glVertex2f(3.3,3.35);

	glVertex2f(3.4,3.4);

	glVertex2f(3.5,3.45);

	glVertex2f(3.6,3.55);

	glVertex2f(3.7,3.6);

	glVertex2f(3.8,3.63);

	glVertex2f(4.0,3.65);

	glVertex2f(4.2,3.7);

	glVertex2f(4.4,3.7);

	glVertex2f(4.6,3.65);

	glVertex2f(4.8,3.55);

	glVertex2f(5.0,3.45);

	glVertex2f(5.1,3.4);

	glVertex2f(5.2,3.25);

	glVertex2f(5.3,3.2);

	glVertex2f(5.4,3.0);

	glVertex2f(5.5,2.5);



	glVertex2f(5.45,2.15);

	glVertex2f(5.4,1.9);

	glVertex2f(5.35,1.8);

	glVertex2f(5.2,1.6);

	glVertex2f(5.0,1.5);

	glVertex2f(4.9,1.4);

	glVertex2f(4.7,1.3);

	glVertex2f(4.6,1.27);

	glVertex2f(4.4,1.25);

	glVertex2f(4.0,1.25);

	glVertex2f(3.9,1.3);

	glVertex2f(3.75,1.35);

	glVertex2f(3.6,1.4);

	glVertex2f(3.45,1.55);

	glVertex2f(3.3,1.7);

	glVertex2f(3.2,1.8);

	glVertex2f(3.1,2.2);

	glEnd();

	glPopMatrix();

    //back tyre
	glPushMatrix();
	glTranslated(bus1+1460,250,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(3.0,2.5);
	glVertex2f(3.0,2.6);
	glVertex2f(3.15,3.1);
	glVertex2f(3.2,3.2);
	glVertex2f(3.3,3.35);
	glVertex2f(3.4,3.4);
	glVertex2f(3.5,3.45);
	glVertex2f(3.6,3.55);
	glVertex2f(3.7,3.6);
	glVertex2f(3.8,3.63);
	glVertex2f(4.0,3.65);
	glVertex2f(4.2,3.7);
	glVertex2f(4.4,3.7);
	glVertex2f(4.6,3.65);
	glVertex2f(4.8,3.55);
	glVertex2f(5.0,3.45);
	glVertex2f(5.1,3.4);
	glVertex2f(5.2,3.25);
	glVertex2f(5.3,3.2);
	glVertex2f(5.4,3.0);
	glVertex2f(5.5,2.5);



	glVertex2f(5.45,2.15);

	glVertex2f(5.4,1.9);

	glVertex2f(5.35,1.8);

	glVertex2f(5.2,1.6);

	glVertex2f(5.0,1.5);

	glVertex2f(4.9,1.4);

	glVertex2f(4.7,1.3);

	glVertex2f(4.6,1.27);

	glVertex2f(4.4,1.25);

	glVertex2f(4.0,1.25);

	glVertex2f(3.9,1.3);

	glVertex2f(3.75,1.35);

	glVertex2f(3.6,1.4);

	glVertex2f(3.45,1.55);

	glVertex2f(3.3,1.7);

	glVertex2f(3.2,1.8);

	glVertex2f(3.1,2.2);

	glEnd();

	glPopMatrix();

}


void traffic_light() {

	//traffic signal controller

	glPushMatrix();

	glTranslatef(-190,20,0);

	glColor3f(0.0,0.0,0.0);

	glBegin(GL_POLYGON);

    glVertex2d(600,350);  //1

    glVertex2d(650,350);  //2

    glVertex2d(650,370);  //3

    glVertex2d(600,370);  //12

	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-190,20,0);

	glBegin(GL_POLYGON);

		glVertex2d(630,370);  //4

		glVertex2d(630,520);  //5

		glVertex2d(620,520);  //10

		glVertex2d(620,370);  //11

	glEnd();

	glPopMatrix();

	//Right Red Light

	glPushMatrix();

	glTranslatef(-190,20,0);

	glBegin(GL_POLYGON);

		glVertex2d(700,450);  //11

		glVertex2d(700,600);  //12

		glVertex2d(650,600);  //13

		glVertex2d(650,450);  //14

	glEnd();

	glPopMatrix();

	//Connecting Rod

	glPushMatrix();

	glTranslatef(-190,20,0);

	glBegin(GL_POLYGON);

		glVertex2d(650,520);  //15

		glVertex2d(650,540);  //16

		glVertex2d(600,540);  //17

		glVertex2d(600,520);  //18

	glEnd();

	glPopMatrix();

	//Red 2

	glPushMatrix();

	glTranslatef(485, 580, 0);

	if(rl2[RED])

		glColor3f(1.0, 0.0, 0.0);

	else

		glColor3f(0.2, 0.0, 0.0);

	glutSolidSphere(12, 80, 80);

	glPopMatrix();

	//Yellow 2

	glPushMatrix();

	glTranslatef(485, 540, 0);

	if(rl2[YELLOW])

		glColor3f(1.0, 1.0, 0.0);

	else

		glColor3f(0.2, 0.2, 0.0);

	glutSolidSphere(12, 80, 80);

	glPopMatrix();

	//Green 2

	glPushMatrix();

	glTranslatef(485, 500, 0);

	if(rl2[GREEN])

		glColor3f(0.0, 1.0, 0.0);

	else

		glColor3f(0.0, 0.2, 0.0);

	glutSolidSphere(12, 80, 80);

	glPopMatrix();

}

void road_strips() {

	//first bottom green strip

	glPushMatrix();

	glBegin(GL_POLYGON);

	glColor3f(0.85,0.64,0.12);

		glVertex2d(0,200);

		glVertex2d(0,250);

		glVertex2d(1000,250);

		glVertex2d(1000,200);

	glEnd();

	glPopMatrix();

	//second grey strip

	glPushMatrix();

	glBegin(GL_POLYGON);

	glColor3f(0.5,0.5,0.5);

		glVertex2d(0,250);

		glVertex2d(0,500);

		glVertex2d(1000,500);

		glVertex2d(1000,250);

	glEnd();

	glPopMatrix();

	//tilted grey strip

	glPushMatrix();

	glBegin(GL_POLYGON);

	glColor3f(0.85,0.64,0.12);

		glVertex2d(300,500);

		glVertex2d(200,800);

		glVertex2d(350,800);

		glVertex2d(500,500);

	glEnd();

	glPopMatrix();

	traffic_light();
	bus();
	bus_chalao();

}


void main_display() {

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	if(view==0) {

		init();

		First_win();

	}

	else {

		//CONSTANT PARTS

		//ROAD STRIP

		road_strips();

	}

	glutSwapBuffers();

}


void traffic_start() {


}

void keyboard(unsigned char key, int x, int y) {


	switch(key) {

		case ESCAPE:exit(1);

		case ' ':

			view=1;

			glClearColor(0.6, 0.8, 0.2, 0);

			traffic_start();

			break;

		case 'a':

			cout<<"Red light 2 to RED"<<endl;

			rl2[RED] = true;

			rl2[YELLOW] = false;

			rl2[GREEN] = false;

			break;

		case 's':

			cout<<"Red light 2 to YELLOW"<<endl;

			rl2[RED] = false;

			rl2[YELLOW] = true;

			rl2[GREEN] = false;

			break;


		case 'd':

			cout<<"Red light 2 to GREEN"<<endl;

			rl2[RED] = false;

			rl2[YELLOW] = false;

			rl2[GREEN] = true;

			break;

		default:

			cout<<"You pressed: "<<key;

	}

}

int main(int argc,char** argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1000,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic Light Simulation");
	glutDisplayFunc(main_display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(main_display);
	glutMainLoop();

	return 0;

}
