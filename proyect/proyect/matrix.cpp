
#include "math.h"
#include <memory.h>
#include "matrix.h"

Matrix::Matrix() {

    Identity();
}


Matrix::~Matrix() {

}


Matrix & Matrix::Identity() {

    _11=1.0f; _12=0.0f; _13=0.0f; _14=0.0f;
    _21=0.0f; _22=1.0f; _23=0.0f; _24=0.0f;
    _31=0.0f; _32=0.0f; _33=1.0f; _34=0.0f;
    _41=0.0f; _42=0.0f; _43=0.0f; _44=1.0f;

	return *this;
}

Matrix & Matrix::Translate(const Vector3 &trans) {

    Identity();
    
    PositionX = trans.x; 
    PositionY = trans.y; 
    PositionZ = trans.z;
    
	return *this;
}

Matrix & Matrix::Translate(float x, float y, float z) {

    Identity();
    
    PositionX = x; 
    PositionY = y; 
    PositionZ = z;
    
	return *this;
}

Matrix & Matrix::TranslateX(const float &dist) {

    Identity();
    
    PositionX = dist;
    
	return *this;
}

Matrix & Matrix::TranslateY(const float &dist) {

    Identity();
    
    PositionY = dist;
    
	return *this;
}

Matrix & Matrix::TranslateZ(const float &dist) {

    Identity();
    
    PositionZ = dist;
    
	return *this;
}

Matrix & Matrix::Rotate(const float &angle, Vector3 &axis) {

    float s = (float)sin((angle)*0.017453293f);
    float c = (float)cos((angle)*0.017453293f);

    axis.Normalize();

    float ux = axis.x;
    float uy = axis.y;
    float uz = axis.z;
    
    _11= c + (1-c) * ux;
    _12= (1-c) * ux*uy + s*uz;
    _13= (1-c) * ux*uz - s*uy;
    _14= 0;
    
    _21= (1-c) * uy*ux - s*uz;
    _22= c + (1-c) * (float)pow(uy,2);
    _23= (1-c) * uy*uz + s*ux;
    _24= 0;
    
    _31= (1-c) * uz*ux + s*uy;
    _32= (1-c) * uz*uz - s*ux;
    _33= c + (1-c) * (float)pow(uz,2);
    _34= 0;
    
    _41= 0;
    _42= 0;
    _43= 0;
    _44= 1;

	return *this;
}

Matrix & Matrix::RotateX(const float &angle) {

    float s = (float)sin((angle)*0.017453293f);
    float c = (float)cos((angle)*0.017453293f);

    Identity();

    _22=  c;
    _23=  s;
    _32= -s;
    _33=  c;

	return *this;
}

Matrix &Matrix::RotateY(const float &angle) {

    float s = (float)sin((angle)*0.017453293f);
    float c = (float)cos((angle)*0.017453293f);

    Identity();

    _11=  c;
    _13= -s;
    _31=  s;
    _33=  c;

	return *this;
}

Matrix & Matrix::RotateZ(const float &angle) {

    float s = (float)sin((angle)*0.017453293f);
    float c = (float)cos((angle)*0.017453293f);

    Identity();

    _11=  c;
    _12=  s;
    _21= -s;
    _22=  c;

	return *this;
}

Matrix & Matrix::Scale(const Vector3 &scale) {

    Identity();

    _11= scale.x;
    _22= scale.y;
    _33= scale.z;

	return *this;
}

Vector3 & Matrix::TransformPoint( Vector3 &vector ) {

    Vector3 &v = vector;

    float x = v.x;
    float y = v.y;
    float z = v.z;

    v.x = x * _11 +
          y * _21 +
          z * _31 + _41;

    v.y = x * _12 +
          y * _22 +
          z * _32 + _42;

    v.z = x * _13 +
          y * _23 +
          z * _33 + _43;

	return v;
}

Matrix & Matrix::Transpose() {

    float swap;

    //      | M00 M10 M20 M33 |   | M00 M01 M02 M03 |
    //      | M01 M11 M12 M31 |   | M10 M11 M12 M13 |
    //  T = | M02 M12 M22 M32 | = | M20 M21 M22 M23 |
    //      | M03 M13 M23 M33 |   | M30 M31 M32 M33 |

  for (int i = 0; i<4; i++) {
    
    for (int j=i+1; j<4; j++) {
      
             swap   = m[i][j];
             m[i][j]= m[j][i];
             m[j][i]= swap;
        }
    }

	return *this;
}

Matrix Matrix::operator + (const Matrix &other) {

    Matrix result;

    result._11= _11 + other._11;
    result._12= _12 + other._12;
    result._13= _13 + other._13;
    result._14= _14 + other._14;

    result._21= _21 + other._21;
    result._22= _22 + other._22;
    result._23= _23 + other._23;
    result._24= _24 + other._24;

    result._31= _31 + other._31;
    result._32= _32 + other._32;
    result._33= _33 + other._33;
    result._34= _34 + other._34;

    result._41= _41 + other._41;
    result._42= _42 + other._42;
    result._43= _43 + other._43;
    result._44= _44 + other._44;

    return result;
}

Matrix & Matrix::operator += (const Matrix &other) {

    Matrix result= *this + other;
	memcpy( m, result.m, sizeof(Matrix) );
    return *this;
}

Matrix Matrix::operator - (const Matrix &other) {

    Matrix result;

    result._11= _11 - other._11;
    result._12= _12 - other._12;
    result._13= _13 - other._13;
    result._14= _14 - other._14;

    result._21= _21 - other._21;
    result._22= _22 - other._22;
    result._23= _23 - other._23;
    result._24= _24 - other._24;

    result._31= _31 - other._31;
    result._32= _32 - other._32;
    result._33= _33 - other._33;
    result._34= _34 - other._34;

    result._41= _41 - other._41;
    result._42= _42 - other._42;
    result._43= _43 - other._43;
    result._44= _44 - other._44;

    return result;
}

Matrix & Matrix::operator -= (const Matrix &other) {

    Matrix result= *this - other;
	memcpy( m, result.m, sizeof(Matrix) );
    return *this;
}

Matrix Matrix::operator * (const Matrix &other) {

    Matrix result;

    //  n=4
    //  | m00 m01 m02 m03 |   | A00 A01 A02 A03 |   | B00 B01 B02 B03 |
    //  | m10 m11 m12 m13 |   | A10 A11 A12 A13 |   | B10 B11 B12 B13 |
    //  | m20 m21 m22 m23 | = | A20 A21 A22 A23 | * | B20 B21 B22 B23 |
    //  | m30 m31 m32 m33 |   | A30 A31 A32 A33 |   | B30 B31 B32 B33 |

  for (int i=0; i<4; i++) {
    
    for (int j=0; j<4; j++) {
      
             result.m[i][j]= m[i][0] * other.m[0][j] + 
                             m[i][1] * other.m[1][j] + 
                             m[i][2] * other.m[2][j] + 
                             m[i][3] * other.m[3][j] ;
        }
    }
    return result;
}

Matrix & Matrix::operator *= (const Matrix &other) {

    Matrix result= *this * other;
	memcpy( m, result.m, sizeof(Matrix) );
    return *this;
}

Matrix Matrix::operator * (const float scalar) {

    Matrix result;

    result._11= _11 * scalar;
    result._12= _12 * scalar;
    result._13= _13 * scalar;
    result._14= _14 * scalar;

    result._21= _21 * scalar;
    result._22= _22 * scalar;
    result._23= _23 * scalar;
    result._24= _24 * scalar;

    result._31= _31 * scalar;
    result._32= _32 * scalar;
    result._33= _33 * scalar;
    result._34= _34 * scalar;

    result._41= _41 * scalar;
    result._42= _42 * scalar;
    result._43= _43 * scalar;
    result._44= _44 * scalar;

    return result;
}

Vector3 Matrix::operator * (const Vector3 &other) {

    Vector3 vector;
    
    vector.x = other.x * _11 + other.y * _21 + other.z * _31;
    vector.y = other.y * _12 + other.y * _22 + other.z * _32;
    vector.z = other.z * _13 + other.y * _23 + other.z * _33;

	return vector;
}

void Matrix::setForwardVector( Vector3 vForward ) {

    ForwardX= vForward.x;
    ForwardY= vForward.y;
    ForwardZ= vForward.z;
}

void Matrix::setStrafeVector( Vector3 vStrafe ) {

    StrafeX= vStrafe.x;
    StrafeY= vStrafe.y;
    StrafeZ= vStrafe.z;
}

void Matrix::setUpVector( Vector3 vUp ) {

    UpX= vUp.x;
    UpY= vUp.y;
    UpZ= vUp.z;
}

Vector3 Matrix::getForwardVector() {
  
  return Vector3( ForwardX, ForwardY, ForwardZ );
}

Vector3 Matrix::getUpVector() {

	return Vector3( UpX ,UpY, UpZ );
}

Vector3 Matrix::getStrafeVector() {

	return Vector3( StrafeX, StrafeY, StrafeZ );
}
Vector3 Matrix::getPosition() {

	return Vector3( PositionX, PositionY, PositionZ );
}
