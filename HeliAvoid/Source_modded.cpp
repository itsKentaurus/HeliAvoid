#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <Windows.h>

#include <iostream>

#include "imageloader.h"
#include "Model.h"
#include "Camera.h"
#include "View.h"
#include "BoundingBox.h"
//#include "Environment.h"
//#include "Frames.h"

//Environment e;
Model m;
Camera c;
View v;
//Frames f;
float width = 600,
	height = 500;

BoundingBox bb_scene(50,100,1000,0,0,0);
const int NUM_BRIDGES = 20;
int curBridge = 0;
BoundingBox bridges[NUM_BRIDGES];

int light0 = 1;
int light1 = 1;
int light2 = 1;
int light3 = 1;
int light  = 1;
int shiny  = 1;
int sRotation = 1;
int rotLight2 = 0;
int ex = 128;
int spotlight = 10;
int spotAngle = 0;
int seconds;
int eThunder;
int delay;
int lightpos;
int numBuild1;
int numBuild2;
int numSide;
int rotIntro;

int phase;

float hx,hy;
float bridgeZ;

//movement 
bool right, left, up = (false);
 

const int NUM_BUILDINGS = 100;
const float d = 4;

GLfloat wb1[NUM_BUILDINGS];
GLfloat hb1[NUM_BUILDINGS];

GLfloat wb2[NUM_BUILDINGS];
GLfloat hb2[NUM_BUILDINGS];

GLfloat wb1Sum[NUM_BUILDINGS];
GLfloat wb2Sum[NUM_BUILDINGS];

GLfloat wb1SumIter;
GLfloat wb2SumIter;

GLfloat sunPosition[] = {0.0, 1.0, 0.0, 0.0};

GLfloat crimson_light[] = {0.94, 0.0, 0.0, 1.0};
GLfloat yellow_light[] =  {1, 1, 0.0, 0.0, 1};
GLfloat green_light[] = {0.0, 1.0, 0.0, 1.0};
GLfloat blue_light[] = {0.0, 0.0, 1.0};
GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat black_light[] = {0.0, 0.0, 0.0};
GLfloat mat_shininess[] = { 128.0 };


GLuint _textureId[3];           //The OpenGL id of the texture
GLuint _btextureId[4];           //The OpenGL id of the texture
GLuint _stextureId[3];           //The OpenGL id of the texture
GLuint _swtextureId;
GLuint _ltextureId;

int randText1[NUM_BUILDINGS];
int randText2[NUM_BUILDINGS];

int randSky;
void init() {
	m.initialized();
	c.initialized();
	v.initialized();
	eThunder = hx = hy = 0;
	for (int i = 0; i!=NUM_BUILDINGS; ++i) {
		hb1[i] = abs( 60 + rand() % 41 );
		wb1[i] = abs( 30 + rand() % 11 );

		hb2[i] = abs( 60 + rand() % 41 );
		wb2[i] = abs( 30 + rand() % 11 );

		randText1[i] = rand() % 4;
		randText2[i] = rand() % 4;

		if (i != 0)			wb1Sum[i] = wb1Sum[i-1] + wb1[i];
		else				wb1Sum[i] = wb1[i];
		if (i != 0)			wb2Sum[i] = wb2Sum[i-1] + wb2[i];
		else				wb2Sum[i] = wb2[i];

		if (i == NUM_BUILDINGS-1) {
			wb1SumIter = wb1Sum[i];
			wb2SumIter = wb2Sum[i];
		}
	}

	randSky = (rand() * 3 + rand() * 2 + rand() * 4) % 3;
	lightpos = 1;
	numBuild1=0;
	numBuild2=0;
	numSide = 0;
	rotIntro = 0;

	bridgeZ = 0;
	for(int i = 0; i < NUM_BRIDGES; i++) {
		bridgeZ += 150+rand()%51;
		bridges[i] = BoundingBox(100,
			10 + rand()%26,
			10+rand()%26,
			0,
			-25+(rand()%5)*(15),
			-bridgeZ);
	}

	phase = 0;
}
void drawHeadLight() {
		glPushMatrix();
		GLfloat spotlightPostition[] = {m.getX(),m.getY(),m.getZ()+5,1};
		GLfloat spotlightDirection[] = {0,-0.1,-1,0};
		glLightfv(GL_LIGHT6, GL_SPECULAR, white_light);
		glLightfv(GL_LIGHT6, GL_AMBIENT, black_light);
		glLightfv(GL_LIGHT6, GL_DIFFUSE, white_light);
		glLightfv(GL_LIGHT6, GL_POSITION, spotlightPostition);
		glLightf (GL_LIGHT6, GL_SPOT_CUTOFF, spotlight);
		glLightfv (GL_LIGHT6, GL_SPOT_DIRECTION, spotlightDirection);
	glPopMatrix();
}


void drawThunder() {
	glEnable(GL_LIGHT0);
		glPushMatrix();
			glTranslatef(0, 0, -20+m.getZ());
			glPushMatrix();
				glTranslatef(20, 0, m.getZ()+20);
				GLfloat spotlightDirection[] = {0,0,1,0};
				GLfloat spotlightPostition[] = {0,0,0,1};
				glLightfv(GL_LIGHT0, GL_POSITION, spotlightDirection);
				glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
				glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
				glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 45);
			glPopMatrix();
			glEnable(GL_LIGHT1);
			glPushMatrix();
			GLfloat spotlightPostition1[] = {-20,20,-20,1};
			GLfloat spotlightDirection1[] = {1,-1,0,0};
	//		glTranslated(hx,hy,0);
			glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
			glLightfv(GL_LIGHT1, GL_AMBIENT, white_light);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
			glLightfv (GL_LIGHT1, GL_SPOT_DIRECTION, spotlightDirection1);
			glLightfv(GL_LIGHT1, GL_POSITION, spotlightPostition1);
	//		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, ex);
			glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 70);
	//		glRotatef(spotAngle,0,0,1);
		glPopMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _ltextureId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glColor4f(1.0f, 1.0f, 1.0f,0.6);

			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
					glVertex3f(-20,0,0);
				glTexCoord2f(1, 0);
					glVertex3f(2,0,0);
				glTexCoord2f(1, 1);
					glVertex3f(2,24,0);
				glTexCoord2f(0, 1);
					glVertex3f(-20,24,0);
			glEnd();

		glPopMatrix();
	glDisable(GL_LIGHT0);
}
void renderBitmapString( const std::string str, int y = 0){
    glRasterPos2f(0, y);
    for( size_t i = 0; i < str.size(); ++i ){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
    }
} 

void createNormal(GLfloat x1,GLfloat y1,GLfloat z1, GLfloat x2,GLfloat y2,GLfloat z2, GLfloat x3,GLfloat y3,GLfloat z3) {
		GLfloat u1 = x2 - x1;
		GLfloat u2 = y2 - y1;
		GLfloat u3 = z2 - z1;
		GLfloat v1 = x3 - x1;
		GLfloat v2 = y3 - y1;
		GLfloat v3 = z3 - z1;

		glNormal3f( u2*v3-u3*v2,
					u3*v1-u1*v3,
					u1*v2-u2*v1);
}
void keyspecial( int key, int x, int y ) {
	//int moveX,moveY;
	//moveX = moveY = 0;

	//if (key == GLUT_KEY_DOWN)
	//	--moveY;
	//if (key == GLUT_KEY_UP)
	//	++moveY;
	//if (key == GLUT_KEY_LEFT)
	//	--moveX;
	//if (key == GLUT_KEY_RIGHT)
	//	++moveX;

	if (key == GLUT_KEY_RIGHT)
		right = true;
	if (key == GLUT_KEY_LEFT)
		left = true;

		c.moveDown(hy);


	glutPostRedisplay();
}
void keySpecialUp( int key, int x, int y ) {
	if (key == GLUT_KEY_RIGHT)
		right = false;
	if (key == GLUT_KEY_LEFT)
		left = false;
	glutPostRedisplay();
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case '1':
			c.moveCamera('1');
			break;
		case '3':
			c.moveCamera('3');
			break;
		case 27:		// esc
			exit(0);			// QUITS the program
			break;
		case 'W':
		case 'w':
			m.toggleSolid();	// Changes from wire to solid and vice versa
			break;
		case 'z':
			v.zoom('+');			// Changes the value of the ortho and perspective
			break;				// To make the effect of zooming in
		case 'Z':
			v.zoom('-');			// Changes the value of the ortho and perspective
			break;				// To make the effect of zooming out
		case 'C':
		case 'c':
//			initial();			// Resets the program to default values
			break;
		case 'P':
		case 'p':
			v.togglePers();
			break;
		case 'o':
		case 'O':
			v.toggleOrtho();
			break;
		case 'f':
		case 'F':
			c.moveCamera('+');	// Moves the camera towards the center of the helicopter
			break;
		case 'a':
			m.moveForward();
			break;
		case 'A':
			m.moveBackward();
			break;
		case 'b':
		case 'B':
			c.moveCamera('-');	// Moves the camera away the center of the helicopter
			break;
		case 's':
		case 'S':
			m.toggleEngine();
			break;
		case 'i':
		case 'I':
			c.moveCamUp();
			break;
		case 'k':
		case 'K':
			c.moveCamDown();
			break;
		case 'j':
		case 'J':
			c.moveCamLeft();
			break;
		case 'l':
		case 'L':
			c.moveCamRight();
			break;
		case '2':
			sRotation = 1 - sRotation;
			break;
		case 32:		//spacebar
			up = true;
			if (phase == 0) phase = 1;
			if (phase == 2) {
				phase = 1;
				init();
			}
			break;

	}
	glutPostRedisplay();
}
void keyboardUp(unsigned char key, int x, int y)
{
	switch (key) {
		case 32:		//spacebar
			if (phase == 0) phase = 1;
			if (phase == 1) up = false;
			if (phase == 2) {
				phase = 1;
				init();
			}
			break;
	}
	glutPostRedisplay();
} 
void drawBridges() {

	for(int j= curBridge;j < curBridge + 3; j++) {
		int i = j % NUM_BRIDGES;
		float minX = bridges[i].m_minVertex.getX();
		float minY = bridges[i].m_minVertex.getY();
		float minZ = bridges[i].m_minVertex.getZ();

		float maxX = bridges[i].m_maxVertex.getX();
		float maxY = bridges[i].m_maxVertex.getY();
		float maxZ = bridges[i].m_maxVertex.getZ();

			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
				glBegin(GL_TRIANGLES);
				for (int k = minY; k < maxY; ++k) {
					for (int i = minX; i <maxX ; ++i) {
						createNormal(	i,k,maxZ,
										i+1,k,maxZ,
										i,k+1,maxZ);
						glVertex3f(i,k,maxZ);
						glVertex3f(i+1,k,maxZ);
						glVertex3f(i,k+1,maxZ);
						createNormal(	i+1,k,maxZ,
										i+1,k+1,maxZ,
										i,k+1,maxZ);

						glVertex3f(i+1,k,maxZ);
						glVertex3f(i+1,k+1,maxZ);
						glVertex3f(i,k+1,maxZ);
					}
				}
			for (int j = minZ; j<maxZ; ++j) {
				for (int i = minX; i <maxX ; ++i) {
						glVertex3f(i,maxY,j);
						glVertex3f(i+1,maxY,j);
						glVertex3f(i,maxY,j-1);

						glVertex3f(i+1,maxY,j);
						glVertex3f(i+1,maxY,j-1);
						glVertex3f(i,maxY,j-1);
				}
			}
			for (int j = minZ; j<maxZ; ++j) {
				for (int i = minX; i <maxX ; ++i) {
						glVertex3f(i,minY,j);
						glVertex3f(i+1,minY,j);
						glVertex3f(i,minY,j-1);

						glVertex3f(i+1,minY,j);
						glVertex3f(i+1,minY,j-1);
						glVertex3f(i,minY,j-1);
				}
			}
				glDisable(GL_BLEND);
//			glTranslatef((maxX+minX)/2,(maxY+minY)/2,(maxZ+minZ)/2);
//			glScalef(maxX-minX,maxY-minY,maxZ-minZ);
//			glutSolidCube(1); 
			glEnd();
			glPopMatrix();
	}

}
void drawRightBuildings(int i) {
	i = i%NUM_BUILDINGS;
	float l1 = wb1[i] / (d/2) - (d/2);
	// Building
	glBindTexture(GL_TEXTURE_2D, _btextureId[randText1[i]]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f,0.6);

	glPushMatrix();
	glTranslatef(25,-50,0);
		glBegin(GL_TRIANGLES);
		for (int j=0; j < l1; ++++++j)
			for (int k=0; k <hb1[i]; ++++++k) {
					createNormal(	0,k,j,
									0,k,j+3,
									0,k+1,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k,j,
									0,k+1,j+3,
									0,k+1,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
			}
			for (int j=l1; j < l1 + d; ++++++j)
				for (int k=5; k <hb1[i]; ++++++k) {
					createNormal(	0,k,j,
									0,k,j+3,
									0,k+3,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k,j,
									0,k+3,j+3,
									0,k+3,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
				}
			for (int j=l1 + d; j < wb1[i]; ++++++j)
				for (int k=0; k <hb1[i]; ++++++k) {
					createNormal(	0,k,j,
									0,k,j+3,
									0,k+3,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k,j,
									0,k+3,j+3,
									0,k+3,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
				}
			glEnd();
//		glPopMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
//			glVertex3f(0,0,l1);
				glTexCoord2f(0, 1);
//			glVertex3f(0,0,l1 + d);
				glTexCoord2f(1, 1);
//			glVertex3f(0,05,l1 + d);
				glTexCoord2f(1, 0);
//			glVertex3f(0,05,l1);
		glEnd();
	glPopMatrix();
}
void drawLeftBuildings(int i) {

	float d = 4;
	float l2 = wb2[i] / (d/2) - (d/2);
	
	// Building
	glBindTexture(GL_TEXTURE_2D, _btextureId[randText2[i]]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f,0.6);

	glPushMatrix();
		glTranslatef(-25,-50,0);
		glBegin(GL_TRIANGLES);
		for (int j=0; j < l2; ++++++j)
			for (int k=0; k <=hb2[i]; ++++++k) {
					createNormal(	0,k,j+3,
									0,k,j,
									0,k+1,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k+1,j+3,
									0,k,j,
									0,k+1,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
			}
			for (int j=l2; j < l2 + d; ++++++j)
				for (int k=5; k <hb2[i]; ++++++k) {
					createNormal(	0,k,j+3,
									0,k,j,
									0,k+3,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k+3,j+3,
									0,k,j,
									0,k+3,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
				}
			for (int j=l2 + d; j < wb2[i]; ++++++j)
				for (int k=0; k <=hb2[i]; ++++++k) {
					createNormal(	0,k,j+3,
									0,k,j,
									0,k+3,j+3);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 0);
					glVertex3f(0,k,j+3);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);

					createNormal(	0,k+3,j+3,
									0,k,j,
									0,k+3,j);
				glTexCoord2f(0, 0);
					glVertex3f(0,k,j);
				glTexCoord2f(1, 1);
					glVertex3f(0,k+3,j+3);
				glTexCoord2f(0, 1);
					glVertex3f(0,k+3,j);
				}
		glEnd();
		glVertex3f(0,0,l2);
		glVertex3f(0,0,l2 + d);
		glVertex3f(0,05,l2 + d);
		glVertex3f(0,05,l2);
	glPopMatrix();
}

void drawRightScene(int i) {
		glPushMatrix();
			if (i != 0)		glTranslatef(0,0,-wb1Sum[i]);
			drawRightBuildings(i);
		glPopMatrix();
}

void drawLeftScene(int i) {

		glPushMatrix();
			if (i != 0)		glTranslatef(0,0,-wb2Sum[i]);
			drawLeftBuildings(i);
		glPopMatrix();
}
void drawSky() {
	glBindTexture(GL_TEXTURE_2D, _stextureId[randSky]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f,0.6);

	glPushMatrix();
	glTranslatef(0,80,m.getZ());
	glScalef(200,1, 220);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
	glVertex3f( -1,0,-1);
		glTexCoord2f(0, 1);
	glVertex3f( -1,0,1);
		glTexCoord2f(1, 1);
	glVertex3f( 1,0,1);
		glTexCoord2f(1, 0);
	glVertex3f( 1,0,-1);

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-250,-50,-250+m.getZ());
	glScalef(500,140, 1);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
	glVertex3f( 0,0,0);
		glTexCoord2f(1, 0);
	glVertex3f( 1,0,0);
		glTexCoord2f(1, 1);
	glVertex3f( 1,1,0);
		glTexCoord2f(0, 1);
	glVertex3f( 0,1,0);

	glEnd();
	glPopMatrix();

}
void drawRightSidewalk(float h = 0) {
	glPushMatrix();
	glTranslated(18,-50,-7*h);
	glScalef(7,1,7);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
	glVertex3f(0,0,0);
		glTexCoord2f(0, 1);
	glVertex3f(0,0,1);
		glTexCoord2f(1, 1);
	glVertex3f(1,0,1);
		glTexCoord2f(1, 0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();
}
void drawLeftSidewalk(float h = 0) {
	glPushMatrix();
	glTranslated(-25,-50,-7*h);
	glScalef(7,1,7);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
	glVertex3f(0,0,0);
		glTexCoord2f(0, 1);
	glVertex3f(0,0,1);
		glTexCoord2f(1, 1);
	glVertex3f(1,0,1);
		glTexCoord2f(1, 0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();
}

void drawLampost(float h = 0) {
		glPushMatrix();
			glTranslatef(20, -45, -120*h);
			glPushMatrix();
				glTranslatef(-1,7,0);
				glScalef(3,1,1);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glScalef(1,14,1);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-2,6,0);
				glScalef(1,2,1);
				glutSolidCube(1);
			glPopMatrix();

			glTranslatef(-40, 0,0);
			glPushMatrix();
				glScalef(-1,1,1);
				glPushMatrix();
					glTranslatef(-1,7,0);
					glScalef(3,1,1);
					glutSolidCube(1);
				glPopMatrix();
				glPushMatrix();
					glScalef(1,14,1);
					glutSolidCube(1);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-2,6,0);
					glScalef(1,2,1);
					glutSolidCube(1);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
}
//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE, 
				 image->pixels);
	return textureId;
}

void initRendering() {
	
	Image* image = loadBMP("Metal.bmp");
	_textureId[0] = loadTexture(image);
	delete image;
	image = loadBMP("Land.bmp");
	_textureId[1] = loadTexture(image);
	delete image;
	image = loadBMP("Heli.bmp");
	_textureId[2] = loadTexture(image);
	delete image;
	image = loadBMP("Building1.bmp");
	_btextureId[0] = loadTexture(image);
	delete image;
	image = loadBMP("Building2.bmp");
	_btextureId[1] = loadTexture(image);
	delete image;
	image = loadBMP("Building3.bmp");
	_btextureId[2] = loadTexture(image);
	delete image;
	image = loadBMP("Building4.bmp");
	_btextureId[3] = loadTexture(image);
	delete image;
	image = loadBMP("Sky1.bmp");
	_stextureId[0] = loadTexture(image);
	delete image;
	image = loadBMP("Sky2.bmp");
	_stextureId[1] = loadTexture(image);
	delete image;
	image = loadBMP("Sky3.bmp");
	_stextureId[2] = loadTexture(image);
	delete image;
	image = loadBMP("Sidewalk.bmp");
	_swtextureId = loadTexture(image);
	delete image;
	image = loadBMP("Lightning.bmp");
	_ltextureId = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	v.setView(w, h);
	c.updateLook();
	width = w;
	height = h;
}

void idlePlayPhase() {
	seconds++;
	delay--;
	if (seconds >22*100)
		seconds = -20;
	if (seconds == 5 || 
		seconds == 10*10 || 
		seconds == 10*100 || 
		seconds == 15*10 || 
		seconds == 22*100 || 
		seconds == 12*100) {
		PlaySound( TEXT("Thunder.wav"), NULL, SND_ASYNC);
		eThunder = 12;
		delay = 240;
	}
	if (delay < 0) {
		PlaySound( TEXT("Rotor.wav"), NULL, SND_ASYNC);
		delay = 370;
	}
	eThunder--;
	m.rotateBlades();
	//fix for infinite buildings
	if (m.getZ() <= -120* lightpos) 
		(lightpos++);
	if (m.getZ() <= -wb2Sum[numBuild2]) {
		numBuild2++;
		if(numBuild2 == NUM_BUILDINGS) {
			numBuild2 = 0;
			for (int i = 0; i < NUM_BUILDINGS; i++) {
				wb2Sum[i] += wb2SumIter;
			}
		}
	}
	if (m.getZ() <= -wb1Sum[numBuild1]) {
		numBuild1++;
		if(numBuild1 == NUM_BUILDINGS) {
			numBuild1 = 0;
			for (int i = 0; i < NUM_BUILDINGS; i++) {
				wb1Sum[i] += wb1SumIter;
			}
		}
	}
	if (m.getZ() <= -7*numSide)
		numSide+= 3;
	//movement
	float moveX,moveY;
	moveX = moveY = 0;
	if (left && !right) {
		moveX = -0.5;
	}
	if (right && !left) {
		moveX = 0.5;
	}

	if (up) {
		moveY = 0.2;

	}else {
		moveY = -0.15;
	}
	if(moveX != 0){
		m.bb_heli.updateAdd(moveX,0,0);
		if(m.bb_heli.isInside(bb_scene)&&m.bb_heli.isIntersecting(bridges[curBridge])==Sides::None) {
			hx += moveX;
		}else {
			m.bb_heli.updateAdd(-moveX,0,0);
		}
	}

	if(moveY != 0){
		m.bb_heli.updateAdd(0,moveY,0);
		if(m.bb_heli.isInside(bb_scene)&&m.bb_heli.isIntersecting(bridges[curBridge])==Sides::None) {
			hy += moveY;
			c.moveDown(hy);
		}else {
			m.bb_heli.updateAdd(0,-moveY,0);
		}
	}




	//
	if (m.bb_heli.isBehind(bridges[curBridge])) {
		if (curBridge == (NUM_BRIDGES-1)) {
			//remake bridges
			//for(int i = 0; i < NUM_BRIDGES; i++) {
			//	bridgeZ += 150+rand()%51;
			//	bridges[i] = BoundingBox(100,10+rand()%26,25+rand()%26,0,-25+(rand()%3)*(20),-bridgeZ);
		
			//}
		}
		curBridge = (curBridge+1)%NUM_BRIDGES;
	}

	if(m.bb_heli.isIntersecting(bridges[curBridge]) == Sides::None) {
		m.addZ(1.5);
		m.bb_heli.updateAdd(0,0,-1.5);
	}else {
//		phase = 2;
		std::cout << "PHASE 2" << std::endl;
	}

}
void idleIntroPhase() {
	rotIntro++;
}
void idle(void) {
	if (phase == 0)		idleIntroPhase();
	if (phase == 1)		idlePlayPhase();
	if (phase == 2);

	glutPostRedisplay();
}
void drawStreet() {
	//x-37,17 
	//-50,
	//
	glBegin(GL_TRIANGLES);
		for (int i=-18; i<18; ++i) {
			for (int j=0; j>-250; --j) {
				glVertex3f(i,-50,j);
				glVertex3f(i+1,-50,j);
				glVertex3f(i+1,-50,j-1);
				glVertex3f(i,-50,j);
				glVertex3f(i,-50,j-1);
				glVertex3f(i+1,-50,j-1);
			}
		}
	glEnd();
}
void drawHelicopter() {
	glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
			glColor4d(0.6, 0.6, 1.0, 0.5);
				m.drawCockpit();
			glDisable(GL_BLEND);


			glBindTexture(GL_TEXTURE_2D, _textureId[0]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glColor4f(1.0f, 1.0f, 1.0f,0.6);
			m.drawHelicopter();


			glBindTexture(GL_TEXTURE_2D, _textureId[1]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glColor4f(1.0f, 1.0f, 1.0f,0.6);

			m.drawLanding();

			glBindTexture(GL_TEXTURE_2D, _textureId[2]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glColor4f(1.0f, 1.0f, 1.0f,0.6);

			m.drawHelis();
	glPopMatrix();
}
void introGame() {

	glColor3f(1,1,1);
	glViewport(width*0.1,height*.80,30,40);
		renderBitmapString("WELCOME TO");
	glViewport(width*0.1,height*.770,30,40);
		renderBitmapString("HELICOPTER EVASION");
	glViewport(width*0.1,height*.740,30,40);
		renderBitmapString("INSTRUCTION:");
	glViewport(width*0.1,height*.710,30,40);
		renderBitmapString("Avoid the random bridge around the city");
	glViewport(width*0.1,height*.68,30,40);
		renderBitmapString("Using the space bar the helicopter will go up");
	glViewport(width*0.1,height*.65,30,40);
		renderBitmapString("The Helicopter will go automatically go down");
	glViewport(width*0.1,height*.62,30,40);
		renderBitmapString("Left key will move the helicopter go left");
	glViewport(width*0.1,height*.59,30,40);
		renderBitmapString("Right key will move the helicopter go right");
	glViewport(width*0.1,height*.56,30,40);
		renderBitmapString("1 will change your view to first person");
	glViewport(width*0.1,height*.53,30,40);
		renderBitmapString("3 will change your view to third person");

	glViewport(width*0.1,height*.50,30,40);
		renderBitmapString("PRESS SPACE TO START");

	glViewport(0,0,width,height);
	glPushMatrix();
	glTranslatef(4,3,8);
	glRotatef(rotIntro,0,1,0);
	drawHelicopter();
	glPopMatrix();

}

void playGame() {
	glEnable(GL_LIGHTING);	
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);
	glPushMatrix();
	if (eThunder > 0)
		drawThunder();

		GLfloat spotlightPostition2[] = {11,-40,-120*(lightpos+1),1};
		GLfloat spotlightDirection2[] = {0,-1,0,0};
		glLightfv(GL_LIGHT2, GL_SPECULAR, white_light);
		glLightfv(GL_LIGHT2, GL_AMBIENT, white_light);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, white_light);
		glLightfv (GL_LIGHT2, GL_SPOT_DIRECTION, spotlightDirection2);
		glLightfv(GL_LIGHT2, GL_POSITION, spotlightPostition2);
		glLightf (GL_LIGHT2, GL_SPOT_CUTOFF, 45);
		GLfloat spotlightPostition3[] = {-11,-40,-120*(lightpos+1),1};
		GLfloat spotlightDirection3[] = {0,-1,0,0};
		glLightfv(GL_LIGHT3, GL_SPECULAR, white_light);
		glLightfv(GL_LIGHT3, GL_AMBIENT, white_light);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, white_light);
		glLightfv (GL_LIGHT3, GL_SPOT_DIRECTION, spotlightDirection3);
		glLightfv(GL_LIGHT3, GL_POSITION, spotlightPostition3);
		glLightf (GL_LIGHT3, GL_SPOT_CUTOFF, 45);

		GLfloat spotlightPostition4[] = {11,-40,-120*lightpos,1};
		GLfloat spotlightDirection4[] = {0,-1,0,0};
		glLightfv(GL_LIGHT4, GL_SPECULAR, white_light);
		glLightfv(GL_LIGHT4, GL_AMBIENT, white_light);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, white_light);
		glLightfv (GL_LIGHT4, GL_SPOT_DIRECTION, spotlightDirection4);
		glLightfv(GL_LIGHT4, GL_POSITION, spotlightPostition4);
		glLightf (GL_LIGHT4, GL_SPOT_CUTOFF, 45);
		GLfloat spotlightPostition5[] = {-11,-40,-120*lightpos,1};
		GLfloat spotlightDirection5[] = {0,-1,0,0};
		glLightfv(GL_LIGHT5, GL_SPECULAR, white_light);
		glLightfv(GL_LIGHT5, GL_AMBIENT, white_light);
		glLightfv(GL_LIGHT5, GL_DIFFUSE, white_light);
		glLightfv (GL_LIGHT5, GL_SPOT_DIRECTION, spotlightDirection5);
		glLightfv(GL_LIGHT5, GL_POSITION, spotlightPostition5);
		glLightf (GL_LIGHT5, GL_SPOT_CUTOFF, 45);

		if (c.isThirdPerson()) {
			glColor3f(0,0,0);
			glTranslatef(hx, hy, 0);
			drawHeadLight();
			drawHelicopter();
		}
	glPopMatrix();


	//

	
	//
	glBindTexture(GL_TEXTURE_2D, _swtextureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f,0.6);
		glColor3f(1,0,0);
	for (int i = 0; i < 70; ++i) {
		drawRightSidewalk(numSide + i);
		drawLeftSidewalk(numSide + i);
	}
	for (int i = 0; i <= 9; ++i) {

		drawRightScene((numBuild1 + i)%NUM_BUILDINGS);
		drawLeftScene((numBuild2 + i)%NUM_BUILDINGS);
	}


	glColor3f(0,0,1);
	glPushMatrix();
//	glTranslatef(0,0,m.getZ());
		drawSky();
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
//	glColor3f(0,1,1);

	drawLampost(lightpos-1);
	drawLampost(lightpos);
	drawLampost(lightpos+1);
	glPushMatrix();

	glTranslatef(0,0,m.getZ());
		drawStreet();
	glPopMatrix();

	drawBridges();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glDisable(GL_LIGHT5);
	glDisable(GL_LIGHT6);
}
void concGame() {
	glViewport(width*0.1,height*.80,30,40);
		renderBitmapString("GAME OVER");
	glViewport(width*0.1,height*.770,30,40);
		renderBitmapString("Your helicopter crashed and will not be remembered");
	glViewport(width*0.1,height*.740,30,40);
		renderBitmapString("Thank you for playing HELICOPTER AVOID");
	glViewport(width*0.1,height*.71,30,40);
		renderBitmapString("You lasted: ");
	glViewport(width*0.1,height*.68,30,40);
		renderBitmapString("Press space to restart");
}

void drawScene() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	
	glViewport(0,0, width, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	v.setView(width, height);
	if (c.isThirdPerson())		c.updateLook(m);
	else						c.updateLook(m.getX()+hx, m.getY()+hy, m.getZ());

	if (phase == 0) introGame();
	if (phase == 1) playGame();
	if (phase == 2) concGame();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	init();
	glutCreateWindow("Helicopter");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(keyboardUp);

	glutReshapeFunc(handleResize);
	
	glutSpecialFunc(keyspecial);
	glutSpecialUpFunc(keySpecialUp);
	glutIdleFunc(idle);
	
	glutMainLoop();
	return 0;
}
//
void moveHeli(){};