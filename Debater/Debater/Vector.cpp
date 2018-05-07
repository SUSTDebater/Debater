#include "stdafx.h"
#include "Vector.h"
#include"Head.h"

using SUST::Vector;

Vector::Vector(double dLen, double dDir)
{
	this->reAngle(dDir);
	this->reMod(dLen);
}

Vector::Vector(const Vector& vVec) {
	this->length = vVec.length;
	this->direction = vVec.direction;
}

inline double Vector::getMod() {
	return this->length;
}

inline double Vector::getAngle() {
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

const Vector& Vector::add(const Vector &vVec) {
	double dir;
	double len;
	dir = this->direction + vVec.direction;
	if (dir>=360)
		dir-= 360;
	double n;
	n = this->between(vVec);
	len= sqrt(pow(this->length, 2) + pow(vVec.length, 2)
		+ 2 * (this->length)*(vVec.length)*cos(n));
	return Vector (len ,dir);
}

double Vector::multiply(const Vector &vVec) {
	double j;
	double n;
	n = this->between(vVec);
	j = (this->length)*(vVec.length)*cos(n);
	return j;                                                                            //向量点乘返回的值
}

const Vector& Vector::multiply(double dNum) {
	double len;
	len = this->length*dNum;
	return Vector(len, this->direction);
}

const Vector& Vector::minus(const Vector &vVec) {
	Vector vec = vVec;
	vec = this->add(~vec);
	return Vector (vec.length,vec.direction);
}

double Vector::between(const Vector &vVec) {
	double dir;
	dir = fabs(this->direction - vVec.direction);
	return dir;
}

inline bool Vector::vertical(const Vector &vVec) {
	return this->between(vVec) == 90 || this->between(vVec) == 270;
}

inline bool Vector::parallel(const Vector &vVec) {
	return this->between(vVec) == 0 || this->between(vVec) == 180;
}

inline bool Vector::equal(const Vector &vVec) {
	return this->between(vVec) == 0 && this->length == vVec.length;
}

inline const Vector& Vector::operator +(const Vector &vVec) {
	return this->add(vVec);
}

const Vector& Vector::operator ~() {
	Vector vec;
	vec = *this;
	if (vec.direction <= 180)
		vec.direction += 180;
	else vec.direction -= 180;
	return Vector(vec.length,vec.direction);
}

inline double Vector:: operator *(const Vector& vVec) {
	return this->multiply(vVec);
}

inline const Vector& Vector::operator -(const Vector &vVec) {
	return this->minus(vVec);
}

inline const Vector& Vector ::operator =(const Vector &vVec) {
	return Vector(vVec.length, vVec.direction);
}


inline bool Vector ::operator ==(const Vector &vVec) {
	return (this->equal(vVec));
}

const Vector &operator *(Vector& vVec, double dNum) {
	return vVec.multiply(dNum);                                //最后一个点乘 我不知道这个到底算不算不是友元函数的怎么调用 应该写错了 
}                                                              //但是我不会写  你看一下  就这一个地方不会 其他地方都按照你的要求改了
                                                               //如果还有错的 跟我说就行了 我继续去改。
