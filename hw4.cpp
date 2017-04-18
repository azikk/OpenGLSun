// hw4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL\freeglut.h>
#include<stdio.h>
#include<math.h>
#include<ctime>
#include<iostream>
using namespace std;

GLfloat sumRY = 0.0f, sumBig = 1.0f;
GLfloat earthTXY = 0.0f, ttTXY = 0.0f, earthRY = 0.0f, ttRY = 0.0f;
void drawing(float n) {
	GLfloat t = n*0.5f;
	glBegin(GL_QUADS);
	//front  red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(n, n, n);
	glVertex3f(n, n, -n);
	glVertex3f(-n, n, -n);
	glVertex3f(-n, n, n);
	/*glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);*/

	//bottom  green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(n, n, -n);
	glVertex3f(n, -n, -n);
	glVertex3f(-n, -n, -n);
	glVertex3f(-n, n, -n);
	/*
	glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f); */

	//top  blue  
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(n, n, n);
	glVertex3f(n, -n, n);
	glVertex3f(-n, -n, n);
	glVertex3f(-n, n, n);
	/*
	glVertex3f(0.05f, 0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);*/

	//behind  purple
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(n, -n, -n);
	glVertex3f(n, -n, n);
	glVertex3f(-n, -n, n);
	glVertex3f(-n, -n, -n);
	/*glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);*/

	//left  ao
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-n, -n, n);
	glVertex3f(-n, n, n);
	glVertex3f(-n, n, -n);
	glVertex3f(-n, -n, -n);
	
/*	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);*/

	//right  yellow
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(n, n, n);
	glVertex3f(n, n, -n);
	glVertex3f(n, -n, -n);
	glVertex3f(n, -n, n);
	/*glVertex3f(0.05f, 0.05f, 0.05f);
	glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);*/

	glEnd();

}

void draw() {
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(sumRY, 0.0f, 1.0f, 0.0f); //绕着Y自传
	glScalef(sumBig, sumBig, sumBig); //变大
	drawing(0.1);//大概是太阳

	glRotatef(ttRY, 0.0f, 1.0f, 0.0f);
	glTranslatef(sumBig-1.0f+0.6f, 0.0f, 0.0f);
	glRotatef(ttTXY, 1.0f, 1.0f, 0.0f); //绕着XY转
	drawing(0.03); //地球
	glPopMatrix();
	
	glRotatef(earthRY, 0.0f, 1.0f, 0.0f);
	glTranslatef(sumBig-1.0f+0.8f, 0.0f, 0.0f);
	glRotatef(earthTXY, 1.0f, 1.0f, 0.0f); //绕着XY转
	drawing(0.05); //地球2号
	glPopMatrix();

}

void drawCube(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	
	draw();
	
	glutSwapBuffers();//双缓存

	earthTXY += 0.1;
	sumRY += 2;
	ttTXY += 0.2f;
	ttRY += 1.5;
	earthRY -= 3;
	sumBig += 0.0000001f;


	glutPostRedisplay();
}



int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	
	glutCreateWindow("drawCube");
	
	glutDisplayFunc(drawCube);

	glutMainLoop();
	return 0;
}
