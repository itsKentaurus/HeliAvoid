#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <stdlib.h>
#include <GL/glut.h> 
#include <iostream>
#include <sstream>
#include "imageloader.h"
#include "BoundingBox.h"

class Model {
private:

	// Road
	int road;
	GLfloat roadX, roadY, roadZ, roadA;
	int accel;
	GLfloat moveConstant;
	GLfloat floorLevel;
	bool clockwise;
	int cLocation;
	//Flag
	int poly;
	// Drawing
	GLfloat heliWidth;	// Default = 5
	int size;
	// Points coordinates
	GLfloat mainBody[2][11];
	GLfloat tailConnect[3][5];
	GLfloat tail[3][8];
	GLfloat engine[3][4];
	GLfloat cockpit[2][7];
	GLfloat landing[3][12];
	// Rotation of blades
	GLfloat thr, shr;
	// Circle
	GLfloat CCX, CCZ;
	GLfloat CRadius;
	GLfloat PI;
	GLfloat numVertices;
	GLfloat rotZ;
	GLfloat rotZConstant;
	GLfloat accelConstant;
	GLfloat accelLimit;
	GLfloat angle;
	GLfloat running;
	// Turning
	int iteration;
	GLfloat tRadius;
	// Warning
	int engWarn;
	int introWarn;

	int lap;

	void drawSide(const GLfloat x[],const GLfloat y[],const GLfloat z[],int start, int size, const std::string side,  const GLfloat w=0);
	void drawCenterfold(const GLfloat x[],const GLfloat y[], const int size, const GLfloat w);
	void drawUnevenCenterfold(const GLfloat x[],const GLfloat y[],const GLfloat z[], const int size, const GLfloat w);
	void tiltHelicopterForward();
	void tiltHelicopterBackward();
	void setType();

	void drawTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, GLfloat w = 0); // This one is used for the sides
	void drawTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, int d, GLfloat w);
	void drawTriangle(const GLfloat x[],const GLfloat y[], int a, int b, int c, int d, GLfloat w = 0);

	void draw2LeftTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, GLfloat w = 0); // This one is used for the sides
	void draw2RightTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, GLfloat w = 0); // This one is used for the sides

	void drawSideEngineLeft(GLfloat w = 0);
	void drawSideEngineRight(GLfloat w = 0);
	void drawSideLandLeft(GLfloat w = 0);
	void drawSideLandRight(GLfloat w = 0);
	void drawSideTailLeft(GLfloat w = 0);
	void drawSideTailRight(GLfloat w = 0);
	void drawSideTailConnectLeft(GLfloat w = 0);
	void drawSideTailConnectRight(GLfloat w = 0);
	void drawSideBodyLeft(GLfloat w = 0);
	void drawSideBodyRight(GLfloat w = 0);
	void Model::drawCenterfold(GLfloat w = 0);
	void drawCenterFoldTailConnect(GLfloat w= 0);
	void drawCenterEngine(GLfloat w = 0);

	void drawEngine();
	void drawTailConnect();
	void drawTail();
	void drawBody();
	void drawTopHeli();
	void drawSideHeli();
	void drawCube();


	void createNormal(GLfloat x1,GLfloat y1,GLfloat z1, GLfloat x2,GLfloat y2,GLfloat z2, GLfloat x3,GLfloat y3,GLfloat z3);

	void loadImage();
	GLuint _textureId;
	GLuint loadTexture(Image* image);

public:
	BoundingBox bb_heli;
	Model();
	void drawHelis();

	void drawCockpit();

	void drawLanding();

	void rotateBlades();
	void drawHelicopter();
	void initialized();
	void toggleSolid();
	void moveForward();
	void moveBackward();
	void levitate();
	void toggleEngine();
	void stopWarnings();

	GLfloat getX();
	GLfloat getY();
	GLfloat getZ();
	GLfloat getA();

	void addZ(float z){roadZ -= z;};

	bool engingWarning();
	bool introWarning();

	void setPosition();	// Requires glPopMatrix() to end it.



	std::string getEngineStatus();
	std::string getSpeed();
	std::string getLaps();
	std::string getCoord();

	std::string getMode();

};
#endif 