#include "Model.h"

Model::Model()
:bb_heli(6,9,18,0,1,4)
{
	mainBody[0][0] = 0;
	mainBody[1][0] = 0;
	mainBody[2][0] = 0;
	mainBody[0][1] = -4.8;
	mainBody[1][1] = 2.7;
	mainBody[2][1] = mainBody[2][0];
	mainBody[0][2] = -4.8;
	mainBody[1][2] = 0;
	mainBody[2][2] = mainBody[2][0];
	mainBody[0][3] = -9; 
	mainBody[1][3] = 0;
	mainBody[2][3] = mainBody[2][0];
	mainBody[0][4] = -8.7;
	mainBody[1][4] = -1;
	mainBody[2][4] = mainBody[2][0];
	mainBody[0][5] = -8;
	mainBody[1][5] = -2;
	mainBody[2][5] = mainBody[2][0];
	mainBody[0][6] = -6.9;
	mainBody[1][6] = -2.3;
	mainBody[2][6] = mainBody[2][0];
	mainBody[0][7]= -5.5;
	mainBody[1][7]= -2.5;
	mainBody[2][7] = mainBody[2][0];
	mainBody[0][8]= -4.2;
	mainBody[1][8]= -2.4;
	mainBody[2][8] = mainBody[2][0];
	mainBody[0][9]= -2;
	mainBody[1][9]= -2.5;
	mainBody[2][9] = mainBody[2][0];
	mainBody[0][10]= 0;
	mainBody[1][10]= -1;
	mainBody[2][10] = mainBody[2][0];

	cockpit[0][0] = mainBody[0][1];
	cockpit[1][0] = mainBody[1][3];
	cockpit[2][0] = 0;
	cockpit[0][1] = mainBody[0][1];
	cockpit[1][1] = mainBody[1][1];
	cockpit[2][1] = cockpit[2][0];
	cockpit[0][2] = -6.7;
	cockpit[1][2] = 2.6;
	cockpit[2][2] = cockpit[2][0];
	cockpit[0][3] = -7.5;
	cockpit[1][3] = 2;
	cockpit[2][3] = cockpit[2][0];
	cockpit[0][4] = -8.1;
	cockpit[1][4] = 1.5;
	cockpit[2][4] = cockpit[2][0];
	cockpit[0][5] = -8.7;
	cockpit[1][5] = 0.7;
	cockpit[2][5] = cockpit[2][0];
	cockpit[0][6] = mainBody[0][3];
	cockpit[1][6] = mainBody[1][3];
	cockpit[2][6] = cockpit[2][0];

	tailConnect[0][0] = mainBody[0][0];
	tailConnect[1][0] = mainBody[1][0];
	tailConnect[2][0] = 0;
	tailConnect[0][1] = 2;
	tailConnect[1][1] = 1;
	tailConnect[2][1] = -2.25;
	tailConnect[0][2] = 6.3;
	tailConnect[1][2] = 1;
	tailConnect[2][2] = tailConnect[2][1];
	tailConnect[0][3] = 6.3;
	tailConnect[1][3] = 2;
	tailConnect[2][3] = tailConnect[2][1];
	tailConnect[0][4] = mainBody[0][1];
	tailConnect[1][4] = mainBody[1][1];
	tailConnect[2][4] = 0;
	tail[2][0] = tailConnect[2][3];
	tail[1][0] = tailConnect[1][3];
	tail[0][0] = tailConnect[0][3];
	tail[0][7] = tailConnect[0][2];
	tail[1][7] = tailConnect[1][2];
	tail[2][7] = tailConnect[2][2];
	tail[0][6] = 7;
	tail[1][6] = -1;
	tail[2][6] = tailConnect[2][3];
	tail[0][5] = 7.3;
	tail[1][5] = -1.4;
	tail[2][5] = tailConnect[2][3];
	tail[0][4] = 7.1;
	tail[1][4] = 1;
	tail[2][4] = tailConnect[2][3];
	tail[0][3] = 7.2;
	tail[1][3] = 1.5;
	tail[2][3] = tailConnect[2][3];
	tail[0][2] = 8.5;
	tail[1][2] = 5;	
	tail[2][2] = tailConnect[2][3];
	tail[0][1] = 8;
	tail[1][1] = 5;
	tail[2][1] = tailConnect[2][3];

	engine[0][0] = mainBody[0][1];
	engine[1][0] = mainBody[1][1];
	engine[2][0] = 0;
	engine[0][1] = 0.7;
	engine[1][1] = 2.2;
	engine[2][1] = -.8;
	engine[0][2] = engine[0][1];
	engine[1][2] = 3.2;
	engine[2][2] = engine[2][1];
	engine[0][3] = engine[0][0];
	engine[1][3] = 3.4;
	engine[2][3] = 0;

	landing[0][0] = -8.7;
	landing[1][0] = -3.4;
	landing[2][0] = 0;
	landing[0][1] = -3;
	landing[1][1] = landing[1][0];
	landing[2][1] = landing[2][0];
	landing[0][2] = -2.6;
	landing[1][2] = -2;
	landing[2][2] = 0;
	landing[0][3] = -3.2;
	landing[1][3] = landing[1][2];
	landing[2][3] = landing[2][2];
	landing[0][4] = -3.4;
	landing[1][4] = -2.8;

	landing[2][4] = landing[2][0];
	landing[0][5] = -6.2;
	landing[1][5] = landing[1][4];
	landing[2][5] = landing[2][0];
	landing[0][6] = -6;
	landing[1][6] = landing[1][2];
	landing[2][6] = landing[2][2];
	landing[0][7] = -6.5;
	landing[1][7] = landing[1][2];
	landing[2][7] = landing[2][2];
	landing[0][8] = -6.7;
	landing[1][8] = landing[1][4];
	landing[2][8] = landing[2][0];
	landing[0][9] = -8.6;
	landing[1][9] = landing[1][4];
	landing[2][9] = landing[2][0];
	landing[0][10] = -9;
	landing[1][10] = -2.5;
	landing[2][10] = landing[2][0];
	landing[0][11] = -9.2;
	landing[1][11] = -2.7;
	landing[2][11] = landing[2][0];
	introWarn = 250;
}
void Model::initialized() {
	loadImage();
	floorLevel = 0;
	size = 0;
	thr = shr = 0;
	heliWidth = 5;
	tRadius = 8;
	poly = 0;
	PI = 3.1415926535897932384626433832795 ;
	numVertices = 360;
	rotZ = 0;
	accel = 1;
	roadA = 0; 
	roadX = 0;
	roadZ = 0;
	roadY = floorLevel;
	rotZConstant = 5;
	accelConstant = 2.5;
	accelLimit = 8;
	running = 0;
	angle = -90;
	moveConstant = 0.5;
	iteration = 90;
	cLocation = 0;
	engWarn = 0;
	lap = 0;
	moveForward();
	bb_heli.updateAdd(roadX,roadY,roadZ);
}
void Model::createNormal(GLfloat x1,GLfloat y1,GLfloat z1, GLfloat x2,GLfloat y2,GLfloat z2, GLfloat x3,GLfloat y3,GLfloat z3) {
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
/*	void drawSide(const GLfloatx[],const GLfloaty[],const GLfloatz[], int size, const std::string side,  const GLfloatw=0) {
	This function takes the coordinates that was declared at
	the beginning of the program and puts the points on the canvas
	This only draws the sides of the object (left and right)
*/
void Model::drawSide(const GLfloat x[],const GLfloat y[],const GLfloat z[],int start, int size, const std::string side,  const GLfloat w) {
	if (side == "nRight")
		for (int i=size-1; i>start;i--)	{
			glPushMatrix();
				glBegin(GL_QUADS);
				createNormal(x[start -1]			,y[start -1]	,w,
							x[i]			,y[i]	,w,
							x[i-1]			,y[i-1]	,w);
				glVertex3f(x[start -1]			,y[start -1]	,w);
				glVertex3f(x[i]			,y[i]	,w);
				glVertex3f(x[i-1]			,y[i-1]	,w);
				glVertex3f(x[i-2]			,y[i-2]	,w);

				glEnd();
			glPopMatrix();
		}
	else if (side == "nLeft")	
		for (int i=start; i<size;++i){
			glPushMatrix();
				createNormal(x[start -1]			,y[start -1]	,w,
							 x[i]			,y[i]	,w,
							 x[(i+1)%size]			,y[(i+1)%size]	,w);
				glEnd();
				glBegin(GL_QUADS);
				glVertex3f(x[start -1]			,y[start -1]	,w);
				glVertex3f(x[i]			,y[i]	,w);
				glVertex3f(x[(i+1)%size]			,y[(i+1)%size]	,w);
				glVertex3f(x[(i+2)%size]			,y[(i+2)%size]	,w);
			glPopMatrix();
			}
}
/*	void drawCenterfold(const GLfloat x[],const GLfloat y[], const int size, const GLfloat w)
	This function creates the horizontal lines showing the front and back
	of the object.
	Only used when the lines of the object are parallel of each other
*/
void Model::drawCenterfold(const GLfloat x[],const GLfloat y[], const int size, const GLfloat w) {

	
	for (int i=0;i<size;++i) {
			glPushMatrix();
			createNormal(x[i]		,y[i]	,w,
				x[i]		,y[i]	,0,
				x[i+1]		,y[i+1]	,w);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
					glVertex3d(x[i]			,y[i]	,w);
				glTexCoord2f(0, 1);
					glVertex3d(x[i+1]		,y[i+1]	,w);
				glTexCoord2f(1, 1);
					glVertex3d(x[i+1]		,y[i+1]	,0);
				glTexCoord2f(1, 0);
					glVertex3d(x[i]			,y[i]	,0);
				glEnd();
			glPopMatrix();
		}
}
/*	void drawTopHeli()
	This function will draw the blades
	on top of the helicopter
*/
void Model::drawTopHeli() {
		glPushMatrix();
			glTranslated(-3.7,3.9,2.5);
			glRotated(thr, 0,1,0);
				drawCube();
			glPushMatrix();
				glTranslated(6,.1,.5);
				glScaled(10,.5,1);
				drawCube();
			glPopMatrix();
			glPushMatrix();
				glRotated(120,0,1,0);
				glTranslated(4.5,.1,.5);
				glScaled(10,.5,1);
				drawCube();
			glPopMatrix();
			glPushMatrix();
				glRotated(240,0,1,0);
				glTranslated(5.5,.1,-.75);
				glScaled(10,.5,1);
				drawCube();
			glPopMatrix();
		glPopMatrix();
}
/*	void drawSideHeli()
	This function will draw the blades
	on the side of the helicopter
*/
void Model::drawSideHeli() {
		glPushMatrix();
			glTranslated(6.7,1.5,2.8);
			glRotated(shr, 0,0,1);
			glPushMatrix();
				glScaled(.5,.5,.2);
				drawCube();
			glPopMatrix();
			glPushMatrix();
				glTranslated(0,1,.1);
				glScaled(.5,1.5,.1);
				drawCube();
			glPopMatrix();
			glPushMatrix();
				glRotated(120,0,0,1);
				glTranslated(0,1,.1);
				glScaled(.5,1.5,.1);
				drawCube();
			glPopMatrix();
			glPushMatrix();
				glRotated(240,0,0,1);
				glTranslated(0,1,.1);
				glScaled(.5,1.5,.1);
				drawCube();
			glPopMatrix();

		glPopMatrix();
}
void Model::drawTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, GLfloat w){
	glPushMatrix();
	setType();
		createNormal(x[a]		,y[a]	,z[a] + w,
					 x[b]		,y[b]	,z[b] + w,
					 x[c]		,y[c]	,z[c] + w);
		glVertex3d(x[a]		,y[a]	,z[a] + w);
		glVertex3d(x[b]		,y[b]	,z[b] + w);
		glVertex3d(x[c]		,y[c]	,z[c] + w);
	glEnd();
	glPopMatrix();
}
void Model::drawTriangle(const GLfloat x[],const GLfloat y[],const GLfloat z[], int a, int b, int c, int d, GLfloat w){
	glPushMatrix();
		createNormal(x[a]		,y[a]	,z[a] + w,
					 x[b]		,y[b]	,z[b] + w,
					 x[c]		,y[c]	,z[c] + w);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(x[a]		,y[a]	,z[a] + w);
		glTexCoord2f(0, 1);
			glVertex3d(x[b]		,y[b]	,z[b] + w);
		glTexCoord2f(1, 1);
			glVertex3d(x[c]		,y[c]	,z[c] + w);
		glTexCoord2f(1, 0);
			glVertex3d(x[d]		,y[d]	,z[d] + w);
		glEnd();
	glPopMatrix();
}
void Model::drawTriangle(const GLfloat x[],const GLfloat y[], int a, int b, int c, int d, GLfloat w){
	glPushMatrix();
		createNormal(x[a]		,y[a]	,w,
					 x[b]		,y[b]	,w,
					 x[c]		,y[c]	,w);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(x[a]		,y[a]	,w);
		glTexCoord2f(0, 1);
			glVertex3d(x[b]		,y[b]	,w);
		glTexCoord2f(1, 1);
			glVertex3d(x[c]		,y[c]	,w);
		glTexCoord2f(1, 0);
			glVertex3d(x[d]		,y[d]	,w);
		glEnd();
	glPopMatrix();
}
void Model::drawCockpit() {
		// Cockpit
		size = 6;
		glPushMatrix();
			setPosition();
//				drawTriangle(cockpit[0],cockpit[1],cockpit[2], 0, 1, 2, 3, heliWidth);
				drawSide(cockpit[0],cockpit[1],cockpit[2],1, size+1,"nLeft",heliWidth);			// Right
				drawSide(cockpit[0],cockpit[1],cockpit[2],1, size+1,"nRight");				// Left

/*
				drawTriangle(mainBody[0],mainBody[1], 2, 3, 4, 2, heliWidth);
				drawTriangle(mainBody[0],mainBody[1], 2, 4, 5, 2, heliWidth);
				drawTriangle(mainBody[0],mainBody[1], 2, 5, 6, 2, heliWidth);
				drawTriangle(mainBody[0],mainBody[1], 2, 6, 7, 2, heliWidth);
				drawTriangle(mainBody[0],mainBody[1], 2, 7, 8, 2, heliWidth);

				drawTriangle(mainBody[0],mainBody[1], 2, 4, 3, 2);
				drawTriangle(mainBody[0],mainBody[1], 2, 5, 4, 2);
				drawTriangle(mainBody[0],mainBody[1], 2, 6, 5, 2);
				drawTriangle(mainBody[0],mainBody[1], 2, 7, 6, 2);
				drawTriangle(mainBody[0],mainBody[1], 2, 8, 7, 2);
*/
				drawCenterfold(cockpit[0],cockpit[1],size,heliWidth);
			glPopMatrix();
		glPopMatrix();
}
void Model::drawSideEngineLeft(GLfloat w) {
	drawTriangle(engine[0], engine[1], engine[2], 0, 1, 2, 3, w);
}
void Model::drawSideEngineRight(GLfloat w) {
	glPushMatrix();
		glScalef(1,1,-1);
		drawTriangle(engine[0], engine[1], engine[2], 0, 1, 2, 3, w);
	glPopMatrix();
}
void Model::drawCenterEngine(GLfloat w) {
	glPushMatrix();
		createNormal(engine[0][2]		,engine[1][2]	,engine[2][2] + w,
			engine[0][2]		,engine[1][2]	,-engine[2][2],
			engine[0][3]		,engine[1][3]	,engine[2][3]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(engine[0][2]		,engine[1][2]	,engine[2][2] + w);
		glTexCoord2f(0, 1);
			glVertex3d(engine[0][2]		,engine[1][2]	,-engine[2][2]);
		glTexCoord2f(1, 1);
			glVertex3d(engine[0][3]		,engine[1][3]	,engine[2][3]);
		glTexCoord2f(1, 0);
			glVertex3d(engine[0][3]		,engine[1][3]	,engine[2][3] + w);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		createNormal(engine[0][1]		,engine[1][1]	,engine[2][1] + w,
			engine[0][1]		,engine[1][1]	,-engine[2][1],
			engine[0][2]		,engine[1][2]	,-engine[2][2]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(engine[0][1]		,engine[1][1]	,engine[2][1] + w);
		glTexCoord2f(0, 1);
			glVertex3d(engine[0][1]		,engine[1][1]	,-engine[2][1]);
		glTexCoord2f(1, 1);
			glVertex3d(engine[0][2]		,engine[1][2]	,-engine[2][2]);
		glTexCoord2f(1, 0);
			glVertex3d(engine[0][2]		,engine[1][2]	,engine[2][2] + w);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		createNormal(engine[0][0]		,engine[1][0]	,-engine[2][0],
			engine[0][0]		,engine[1][0]	,engine[2][0] + w,
			engine[0][3]		,engine[1][3]	,engine[2][3] + w);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(engine[0][0]		,engine[1][0]	,-engine[2][0]);
		glTexCoord2f(0, 1);
			glVertex3d(engine[0][0]		,engine[1][0]	,engine[2][0] + w);
		glTexCoord2f(1, 1);
			glVertex3d(engine[0][3]		,engine[1][3]	,engine[2][3] + w);
		glTexCoord2f(1, 0);
			glVertex3d(engine[0][3]		,engine[1][3]	,-engine[2][3]);
		glEnd();
	glPopMatrix();
}
void Model::drawEngine() {
	// Engine
	size = 3;
	glPushMatrix();
	drawSideEngineLeft(heliWidth);
	drawSideEngineRight();
	drawCenterEngine(heliWidth);
	glPopMatrix();
}
void Model::drawSideLandRight(GLfloat w) {
	drawTriangle(landing[0], landing[1], landing[2], 0, 9, 10, 11, w);
	drawTriangle(landing[0], landing[1], landing[2], 0, 1, 4, 5, w);
	drawTriangle(landing[0], landing[1], landing[2], 1, 2, 3, 4, w);
	drawTriangle(landing[0], landing[1], landing[2], 0, 5, 8, 9, w);
	drawTriangle(landing[0], landing[1], landing[2], 5, 6, 7, 8, w);
}
void Model::drawSideLandLeft(GLfloat w) {
	drawTriangle(landing[0], landing[1], landing[2], 11, 10, 9, 0, w);
	drawTriangle(landing[0], landing[1], landing[2], 5, 4, 1, 0, w);
	drawTriangle(landing[0], landing[1], landing[2], 4, 3, 2, 1, w);
	drawTriangle(landing[0], landing[1], landing[2], 9, 8, 5, 0, w);
	drawTriangle(landing[0], landing[1], landing[2], 8, 7, 6, 5, w);
}
void Model::drawLanding() {
	// Landing
	size = 11;
	glPushMatrix();
		setPosition();
			// Left Side
			glPushMatrix();
				drawSideLandRight(heliWidth/10 + heliWidth); // Left side
				drawSideLandLeft(heliWidth);
			glPopMatrix();
			// Right Side
			glPushMatrix();
				drawSideLandRight(); // Left side
				drawSideLandLeft(-heliWidth/10);
			glPopMatrix();
			// Right Side Landing
			glTranslated(0,0,-heliWidth/10);
			drawCenterfold(landing[0],landing[1],size,heliWidth/10);
			// Left Side Landing
			glTranslated(0,0,heliWidth/10 +heliWidth);
			drawCenterfold(landing[0],landing[1],size,heliWidth/10);
		glPopMatrix();
	glPopMatrix();
}
void Model::drawSideTailConnectLeft(GLfloat w) {
	drawTriangle(tailConnect[0], tailConnect[1], tailConnect[2], 0, 1, 4, 4, w);
	drawTriangle(tailConnect[0], tailConnect[1], tailConnect[2], 1, 2, 3, 4, w);
}
void Model::drawSideTailConnectRight(GLfloat w) {
	glPushMatrix();
	glScalef(1,1,-1);
	drawSideTailConnectLeft(w);
	glPopMatrix();
}
void Model::drawCenterFoldTailConnect(GLfloat w) {
	glPushMatrix();
	createNormal(tailConnect[0][3]		,tailConnect[1][3]	,tailConnect[2][3] + w,
		tailConnect[0][3]		,tailConnect[1][3]	,tailConnect[2][3] + w-w/10,
		tailConnect[0][4]		,tailConnect[1][4]	,tailConnect[2][4]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(tailConnect[0][3]		,tailConnect[1][3]	,tailConnect[2][3] + w);
		glTexCoord2f(0, 1);
			glVertex3d(tailConnect[0][3]		,tailConnect[1][3]	,tailConnect[2][3] + w-w/10);
		glTexCoord2f(1, 1);
			glVertex3d(tailConnect[0][4]		,tailConnect[1][4]	,tailConnect[2][4]);
		glTexCoord2f(1, 0);
			glVertex3d(tailConnect[0][4]		,tailConnect[1][4]	,tailConnect[2][4] + w);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		createNormal(tailConnect[0][0]		,tailConnect[1][0]	,tailConnect[2][0] + w,
			tailConnect[0][0]		,tailConnect[1][0]	,tailConnect[2][0],
			tailConnect[0][1]		,tailConnect[1][1]	,tailConnect[2][1]+w-w/10);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(tailConnect[0][0]		,tailConnect[1][0]	,tailConnect[2][0] + w);
		glTexCoord2f(0, 1);
			glVertex3d(tailConnect[0][0]		,tailConnect[1][0]	,tailConnect[2][0]);
		glTexCoord2f(1, 1);
			glVertex3d(tailConnect[0][1]		,tailConnect[1][1]	,tailConnect[2][1]+w-w/10);
		glTexCoord2f(1, 0);
			glVertex3d(tailConnect[0][1]		,tailConnect[1][1]	,tailConnect[2][1] + w);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
			glVertex3d(tailConnect[0][1]		,tailConnect[1][1]	,tailConnect[2][1]+w-w/10);
		glTexCoord2f(0, 1);
			glVertex3d(tailConnect[0][1]		,tailConnect[1][1]	,tailConnect[2][1] + w);
		glTexCoord2f(1, 1);
			glVertex3d(tailConnect[0][2]		,tailConnect[1][2]	,tailConnect[2][2] + w);
		glTexCoord2f(1, 0);
			glVertex3d(tailConnect[0][2]		,tailConnect[1][2]	,tailConnect[2][2]+w-w/10);
		glEnd();
	glPopMatrix();

}
void Model::drawTailConnect() {
	// TailConnect
	glPushMatrix();
		drawSideTailConnectLeft(heliWidth);
		drawSideTailConnectRight();
		drawCenterFoldTailConnect(heliWidth);
	glPopMatrix();
}
void Model::drawSideTailRight(GLfloat w) {
	drawTriangle(tail[0], tail[1], tail[2], 0, 1, 2, 3, w);
	drawTriangle(tail[0], tail[1], tail[2], 0, 3, 4, 7, w);
	drawTriangle(tail[0], tail[1], tail[2], 7, 4, 5, 6, w);

}
void Model::drawSideTailLeft(GLfloat w) {
	drawTriangle(tail[0], tail[1], tail[2], 3, 2, 1, 0, w);
	drawTriangle(tail[0], tail[1], tail[2], 3, 0, 7, 4, w);
	drawTriangle(tail[0], tail[1], tail[2], 6, 5, 4, 7, w);
}
void Model::drawTail() {
	// Tail
	size = 7;
	glPushMatrix();
		drawSideTailLeft(heliWidth);
		drawSideTailRight(heliWidth-heliWidth/10);
		glTranslated(0,0,heliWidth/2+.25);
		drawCenterfold(tail[0],tail[1],size,heliWidth/-10);
	glPopMatrix();
}
void Model::drawSideBodyLeft(GLfloat w) {
			drawTriangle(mainBody[0],mainBody[1], 0, 1, 2, 0, w);
			drawTriangle(mainBody[0],mainBody[1], 0, 2, 10, 0, w);
			drawTriangle(mainBody[0],mainBody[1], 10, 2, 8, 9, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 3, 4, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 4, 5, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 5, 6, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 6, 7, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 7, 8, 2, w);

}
void Model::drawSideBodyRight(GLfloat w) {
			drawTriangle(mainBody[0],mainBody[1], 0, 2, 1, 0, w);
			drawTriangle(mainBody[0],mainBody[1], 0, 10, 2, 0, w);
			drawTriangle(mainBody[0],mainBody[1], 9, 8, 2, 10, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 4, 3, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 5, 4, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 6, 5, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 7, 6, 2, w);
			drawTriangle(mainBody[0],mainBody[1], 2, 8, 7, 2, w);
}
void Model::drawCenterfold(GLfloat w) {
			glPushMatrix();
			createNormal(mainBody[0][8]		,mainBody[1][8]	,w,
				mainBody[0][8]		,mainBody[1][8]	,0,
				mainBody[0][9]		,mainBody[1][9]	,w);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
					glVertex3d(mainBody[0][8]		,mainBody[1][8]	,w);
				glTexCoord2f(0, 1);
					glVertex3d(mainBody[0][9]		,mainBody[1][9]	,w);
				glTexCoord2f(1, 1);
					glVertex3d(mainBody[0][9]		,mainBody[1][9]	,0);
				glTexCoord2f(1, 0);
					glVertex3d(mainBody[0][8]		,mainBody[1][8]	,0);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			createNormal(mainBody[0][9]		,mainBody[1][9]	,w,
				mainBody[0][9]		,mainBody[1][9]	,0,
				mainBody[0][10]		,mainBody[1][10]	,w);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
					glVertex3d(mainBody[0][9]		,mainBody[1][9]	,w);
				glTexCoord2f(0, 1);
					glVertex3d(mainBody[0][10]		,mainBody[1][10]	,w);
				glTexCoord2f(1, 1);
					glVertex3d(mainBody[0][10]		,mainBody[1][10]	,0);
				glTexCoord2f(1, 0);
					glVertex3d(mainBody[0][9]		,mainBody[1][9]	,0);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			createNormal(mainBody[0][10]		,mainBody[1][10]	,w,
				mainBody[0][10]		,mainBody[1][10]	,0,
				mainBody[0][0]		,mainBody[1][0]	,w);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
					glVertex3d(mainBody[0][10]		,mainBody[1][10]	,w);
				glTexCoord2f(0, 1);
					glVertex3d(mainBody[0][0]		,mainBody[1][0]	,w);
				glTexCoord2f(1, 1);
					glVertex3d(mainBody[0][0]		,mainBody[1][0]	,0);
				glTexCoord2f(1, 0);
					glVertex3d(mainBody[0][10]		,mainBody[1][10]	,0);
				glEnd();
			glPopMatrix();
}
void Model::drawBody() {
		// Main Body
		size = 10;
		glPushMatrix();
			drawSideBodyLeft(heliWidth);
			drawSideBodyRight();
			drawCenterfold(mainBody[0],mainBody[1],size+1,heliWidth);
		glPopMatrix();
}
/*	void drawHelicopter()
	This function holds all the creation of 
	the parts of the helicopter
*/
void Model::drawHelicopter() {
	glPushMatrix();
		setPosition();
			drawEngine();
			drawTailConnect();
			drawTail();
			drawBody();

		glPopMatrix();		// Last pop containing the helicopter
	glPopMatrix();
}
void Model::toggleSolid() {
	poly = 1 - poly;
}
void Model::rotateBlades() {
		thr = thr + 30 % 360;
		shr = shr + 30 % 360;
}
void Model::tiltHelicopterForward(){
	if (rotZ < (rotZConstant*(accelLimit-1)))	rotZ += rotZConstant;
}
void Model::tiltHelicopterBackward(){
	if (rotZ > -(rotZConstant*(accelLimit-1)))	rotZ -= rotZConstant;
}
void Model::moveForward() {
	tiltHelicopterForward();
	if (accel < (accelLimit*accelConstant))
		accel += accelConstant;
}
void Model::moveBackward(){
	if (accel > 1) {
		tiltHelicopterBackward();
		accel -= accelConstant;
	}
	else
		accel = 1;
}
void Model::levitate(){
	int direction = 1;
	if (accel > 0)		direction = 1;
	else if (accel < 0) direction = -1;

	//roadZ -= direction*moveConstant*log(abs(accel) + 1);
}
void Model::toggleEngine() {
	running = 1 - running;
}
bool Model::engingWarning() {
	return (engWarn > 0);
}
bool Model::introWarning() {
	return (introWarn > 0);
}
void Model::stopWarnings() {
	if (engingWarning())
		engWarn--;
	if (introWarning())
		introWarn--;
}
std::string Model::getEngineStatus() {
	if (running) return "Active";
	else		 return "Not Active";
}
std::string Model::getSpeed() {
	std::ostringstream oss;
	oss  << abs(accel);
	return oss.str();
}
std::string Model::getLaps() {
	std::ostringstream oss;
	oss  << lap;
	return oss.str();
}
void Model::setType() {
	if (poly)	glBegin(GL_TRIANGLES);
	else		glBegin(GL_LINE_LOOP);
}
GLfloat Model::getX() {
	return roadX;
}
GLfloat Model::getY() {
	return roadY;
}
GLfloat Model::getZ() {
	return roadZ;
}
GLfloat Model::getA() {
	return roadA;
}
std::string Model::getCoord() {
	std::ostringstream oss1;
	std::ostringstream oss2;
	std::ostringstream oss3;
	oss1  << roadX;
	oss2  << roadY;
	oss3  << roadZ;

	return "Coord(" + oss1.str() + "," + oss2.str() + "," + oss3.str() + ")";
}
std::string Model::getMode() {
	if (poly) return "Solid";
	else	  return "Wire";
}
GLuint Model::loadTexture(Image* image) {
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
void Model::loadImage() {
	Image* image = loadBMP("Metal.bmp");
	_textureId = loadTexture(image);
	delete image;
}
void Model::setPosition() {
	glTranslatef(roadX, roadY, roadZ);
	glRotatef(roadA, 0, 1, 0);
	glPushMatrix();					// Push containing everything related to the helicopter
		glRotated(270,0,1,0);		// Rotates object to make sure when its called the object is facing forward
		glRotated(rotZ,0,0,1);
		glScaled(0.5,0.5,0.5);
		glTranslated(5, 0,-2.5);	// Makes the center of gravity in the cockpit
}

void Model::drawHelis(){
	glPushMatrix();
		setPosition();
		drawTopHeli();
		drawSideHeli();
		glPopMatrix();
	glPopMatrix();

}

void Model::drawCube() {
	glTranslatef(-.5,-.5,-.5);
	createNormal(
		1,0,0,0,0,0,
		1,1,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2f(1, 0);
		glVertex3f(1,0,0);
		glTexCoord2f(1, 1);
		glVertex3f(1,1,0);
		glTexCoord2f(0, 1);
		glVertex3f(0,1,0);
	glEnd();
	glBegin(GL_QUADS);
	createNormal(0,0,0, // This one check last
		1,0,1,
		1,1,1);
		glTexCoord2f(0, 0);
		glVertex3f(1,0,0);
		glTexCoord2f(1, 0);
		glVertex3f(1,0,1);
		glTexCoord2f(1, 1);
		glVertex3f(1,1,1);
		glTexCoord2f(0, 1);
		glVertex3f(0,1,0);
	glEnd();
	glBegin(GL_QUADS);
	createNormal(
		0,0,0,0,0,1,
		0,1,0);
		glTexCoord2f(0, 0);
		glVertex3f(0,0,1);
		glTexCoord2f(1, 0);
		glVertex3f(0,0,0);
		glTexCoord2f(1, 1);
		glVertex3f(0,1,0);
		glTexCoord2f(0, 1);
		glVertex3f(0,1,1);
	glEnd();
	glBegin(GL_QUADS);
	createNormal(
		0,0,1,1,0,1,
		0,1,1);
		glTexCoord2f(0, 0);
		glVertex3f(1,0,1);
		glTexCoord2f(1, 0);
		glVertex3f(0,0,1);
		glTexCoord2f(1, 1);
		glVertex3f(0,1,1);
		glTexCoord2f(0, 1);
		glVertex3f(1,1,1);
	glEnd();
	glBegin(GL_QUADS);
	createNormal(
		1,1,0,0,1,0,
		1,1,1);
		glTexCoord2f(0, 0);
		glVertex3f(0,1,0);
		glTexCoord2f(1, 0);
		glVertex3f(1,1,0);
		glTexCoord2f(1, 1);
		glVertex3f(1,1,1);
		glTexCoord2f(0, 1);
		glVertex3f(0,1,1);
	glEnd();
	glBegin(GL_QUADS);
	createNormal(
		1,0,1,0,0,1,
		1,0,0);
		glTexCoord2f(0, 0);
		glVertex3f(0,0,1);
		glTexCoord2f(1, 0);
		glVertex3f(1,0,1);
		glTexCoord2f(1, 1);
		glVertex3f(1,0,0);
		glTexCoord2f(0, 1);
		glVertex3f(0,0,0);
	glEnd();
}