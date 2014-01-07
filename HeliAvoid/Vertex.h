#ifndef Vertex_H
#define Vertex_H
#include <array>

class Vertex
{
private:
	std::array<float,3> coords;
public:
	Vertex(void);
	Vertex(float x, float y, float z);
	Vertex(const std::array<float,3> copy);
	virtual ~Vertex(void);

	void update(float x, float y,float z){coords[0]=x; coords[1]=y; coords[2]=z;};

	float getX(){return coords[0];};
	float getY(){return coords[1];};
	float getZ(){return coords[2];};

	bool operator<(Vertex a);
	bool operator>(Vertex a);

	int size();
};
#endif

