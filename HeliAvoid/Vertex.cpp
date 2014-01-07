#include "Vertex.h"

Vertex::Vertex(void)
{ 
	for(int i = 0; i < coords.size(); i++) {
		coords[i] = 0.0f;
	}
}
Vertex::Vertex(float x, float y, float z)
{
coords[0] = x;
coords[1] = y;
coords[2] = z;
}
Vertex::Vertex(const std::array<float,3> copy)
{
	for(int i = 0; i < copy.size();i++) {
		coords[i] = copy[i];
	}
}

Vertex::~Vertex(void) {
}
//
bool Vertex::operator<(Vertex a) { 

	for(int i = 0; i < this->size(); i ++) {
		if(coords[i] > a.coords[i]) {
			return false;
		}
	}
	return true;
}
bool Vertex::operator>(Vertex a) { 
	for(int i = 0; i < this->size(); i ++) {
		if(coords[i] < a.coords[i]) {
			return false;
		}
	}
	return true;
}

int Vertex::size() {
	return (int)(coords.size());
}