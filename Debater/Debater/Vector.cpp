#include "stdafx.h"
#include "Vector.h"
#include"Head.h"

using namespace SUST;

Vector::Vector(unsigned int uLen, double dDir) {
	uLen = 0;
	dDir = 0.0;
}

void Vector::getMod(unsigned int uLen) {
	length = uLen;
}

void Vector::getAngle(double dDir) {
	direction = dDir;
}

bool Vector::reMod(unsigned int uLen) {
	if (uLen <= 0) return 0;
	else return 1;
}

bool Vector::reAngle(double dDir) {
	if (dDir < 0 || dDir>360) return 0;
	else return 1;
}

Vector& Vector::add(const Vector &vVec) {
	Vector vec;
	vec.direction= this->direction + vVec.direction;
	if (vec.direction > 360)
		vec.direction -= 360;
	double n;
	n = this->between(vVec);
	vec.length = sqrt(pow(this->length, 2) + pow(vVec.length, 2)
		+ 2 * (this->length)*(vVec.length)*cos(n));
	return vec;
}

double& Vector::multiply(const Vector &vVec) {
	double j;
	double n;
	n = this->between(vVec);
	j = (this->length)*(vVec.length)*cos(n);
	return j;                                                                            //向量点乘返回的值
}

Vector& Vector::minus(const Vector &vVec) {
	Vector vec;
	vec=vVec;                                                             
	return this->add(~vec);
}

double Vector::between(const Vector &vVec) {
	Vector vec;
	vec,direction = fabs(this->direction - vVec.direction);
	return vec.direction;
}

bool Vector::vertical(const Vector &vVec) {
	if (this->between(vVec) == 90 || this->between(vVec) == 270)
		return 1;
	else return 0;
}

bool Vector::parallel(const Vector &vVec) {
	if (this->between(vVec) == 0 || this->between(vVec) == 180)
		return 1;
	else return 0;
}

bool Vector:: equal(const Vector &vVec) {
	if (this->between(vVec) == 0 && this->length == vVec.length)
		return 1;
	else return 0;
}

Vector& Vector::operator +(const Vector &vVec) {
	return this->add(vVec);
}

Vector &Vector::operator *(int n){
	Vector vec;
	vec = *this;
	vec.length *= n;
	return vec;
}

Vector& Vector::operator ~(){
	Vector vec;
	vec = *this;
	if (vec.direction <= 180)
		vec.direction += 180;
	else vec.direction -= 180;
	return vec;
}

Vector& Vector::operator -(const Vector &vVec) {
	return this->minus(vVec);
}