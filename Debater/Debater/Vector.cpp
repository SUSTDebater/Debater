#include "stdafx.h"
#include "Vector.h"
#include"Head.h"

using SUST::Vector;

Vector::Vector(double dLen, double dDir)
{
	this->reAngle(dDir);
	this->reMod(dLen);
}

double Vector::getMod() {
	return this->length;
}

double Vector::getAngle() {
	return this->direction;
}

bool Vector::reMod(double dLen) {
	if (dLen < 1e-6) return false;
	this->length = dLen;
	return true;
}

bool Vector::reAngle(double dDir) {
	if (dDir < 1e-6) return false;
	this->direction = dDir - (int)(dDir / 360) * 360.0;
	return true;
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
	return;
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
