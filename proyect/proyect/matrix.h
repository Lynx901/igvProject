#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "vector3.h"
class Matrix
{
public:
  
  union
  {
    struct
    {
      float   _11, _12, _13, _14;
      float   _21, _22, _23, _24;
      float   _31, _32, _33, _34;
      float   _41, _42, _43, _44;
    };
    
    struct
    {
      float   StrafeX, UpX, ForwardX, DummyX;
      float   StrafeY, UpY, ForwardY, DummyY;
      float   StrafeZ, UpZ, ForwardZ, DummyZ;
      float   PositionX, PositionY, PositionZ, One;
    };
    
    float m[4][4];
  };
  
public:
  Matrix();
  ~Matrix();
  
  Matrix & Identity();
  
  Matrix & Translate(const Vector3 &trans);
  Matrix & Translate(float x, float y, float z);
  Matrix & TranslateX(const float &dist);
  Matrix & TranslateY(const float &dist);
  Matrix & TranslateZ(const float &dist);
  
  Matrix & Rotate(const float &angle, Vector3 &axis);
  Matrix & RotateX(const float &angle);
  Matrix & RotateY(const float &angle);
  Matrix & RotateZ(const float &angle);
  
  Matrix & Scale(const Vector3 &scale);
  Vector3 & TransformPoint ( Vector3 &vector );
  Matrix & Transpose();
  
  Matrix operator + (const Matrix &other);
  Matrix & operator += (const Matrix &other);
  Matrix operator - (const Matrix &other);
  Matrix & operator -= (const Matrix &other);
  Matrix operator * (const Matrix &other);
  Matrix & operator *= (const Matrix &other);
  Matrix operator * (const float scalar);
  Vector3 operator * (const Vector3 &other);
  
  void setForwardVector( Vector3 vForward );
  void setStrafeVector( Vector3 vStrafe );
  void setUpVector( Vector3 vUp );
  
  Vector3 getForwardVector();
  Vector3 getUpVector();
  Vector3 getStrafeVector();
  Vector3 getPosition();
};
#endif
