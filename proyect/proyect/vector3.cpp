
#include <math.h>
#include "vector3.h"

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector3::~Vector3() {
}

Vector3 Vector3::operator + (Vector3 other) {
  return Vector3(other.x + x, other.y + y, other.z + z);
}

Vector3 & Vector3::operator += (const Vector3 &other) {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

Vector3 Vector3::operator - (Vector3 other) {
  return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 & Vector3::operator -= (const Vector3 &other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  
  return *this;
}

Vector3 Vector3::operator * (const Vector3 &other) {
  Vector3 vResult;
  
  vResult.x = ((this->y * other.z) - (this->z * other.y));
  vResult.y = ((this->z * other.x) - (this->x * other.z));
  vResult.z = ((this->x * other.y) - (this->y * other.x));
  
  return vResult;
}

Vector3 Vector3::operator * (float num) {
  return Vector3(x * num, y * num, z * num);
}

float Vector3::operator % (const Vector3 &other) {
  return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector3 Vector3::operator / (float num) {
  if (num != 0)
    return Vector3(x / num, y / num, z / num);
  else
    return *this; // no se divide
}

float Vector3::Magnitude() {
  return (float)sqrt( (x * x) + (y * y) + (z * z) );
}

Vector3 &Vector3::Normalize() {
  float magnitude = Magnitude();
  
  if (magnitude)
  {
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
  }
  
  return *this;
}
