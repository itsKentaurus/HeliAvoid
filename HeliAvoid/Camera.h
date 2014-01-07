#ifndef CAMERA_H
#define CAMERA_H
#include "Model.h"
#include <string>
#include <stdlib.h>
#include <GL/glut.h> 

class Camera {
private:

	// LookAt
	float distance;
	float dz, dx, dy;
	float ey, ex, ez;
	float tx, ty, tz;
	float savedDistance;
	// Rotation of camera
	float longitude, latitude;
	int person;
	// Rotation of eyes
	float eLongitude, eLatitude;
	void update();
	void reset();
	void modLongitude(float );
	void modLatitude(float );
	void modeLongitude(float );
	void modeLatitude(float );
public:
	Camera();
	void moveCamera(unsigned char key);
	void initialized();
	void updateLook();
	void updateLook(Model m);
	void Camera::updateLook(float x, float y, float z);
	void moveCamLeft();
	void moveCamRight();
	void moveCamUp();
	void moveCamDown();
	bool isThirdPerson();
	bool isFirstPerson();

	void moveRight(float i);
	void moveLeft(float i);
	void moveUp(float i);
	void moveDown(float i);

};

#endif