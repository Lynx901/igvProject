#ifndef __VECTOR3_H__
#define __VECTOR3_H__

class Vector3 {
public:
  
  float x, y, z;	// Coordenadas del vector. Estos miembros son públicos para permitir un acceso rapido a los mismos.
  
public:
  Vector3();
  Vector3(float x, float y, float z);
  ~Vector3();
  
  Vector3   operator +  (Vector3 other);
  Vector3 & operator += (const Vector3 &other);
  Vector3   operator -  (Vector3 other);
  Vector3 & operator -= (const Vector3 &other);
  Vector3   operator *  (const Vector3 &other);
  Vector3   operator *  (float num);
  float     operator %  (const Vector3 &other);
  Vector3   operator /  (float num);
  
  float     Magnitude();
  Vector3 & Normalize();
};

#endif
