#ifndef _VECTOR_H
#define _VECTOR_H

#include "Head.h"

namespace SUST {
	class Vector {
	public:
		Vector() :length(0.0), direction(0.0) {};
		Vector(double dLen, double dDir);
		Vector(const Vector& vVec);
		~Vector() {};
		double getMod();
		double getAngle();						          //取长度和方向角度
		bool reMod(double dLen);
		bool reAngle(double dDir);                        //判断是否输入错误
	public:
		const Vector & add(const Vector &vVec);
		const Vector &minus(const Vector &vVec);                //向量之间的加减乘除
		double multiply(const Vector &vVec);
		const Vector &multiply(double dNum);
		double between(const Vector &vVec);               //向量之间的角度
		bool vertical(const Vector &vVec);                //判断向量是否垂直
		bool parallel(const Vector &vVec);                //判断向量是否平行
		bool equal(const Vector &vVec);                   //判断向量是否相等
	public:
		const Vector & operator ~();                            //重载取反方向
		double operator *(const Vector& vVec);            //重载一个乘法取数乘
		const Vector& operator +(const Vector &vVec);           //重载一个加号
		const Vector& operator -(const Vector &vVec);           //重载一个减号
		const Vector& operator =(const Vector &vVec);
		bool operator ==(const Vector &vVec);


	private:
		double    length;                                 //长度
		double    direction;                              //方向角度
	};
	const Vector &operator *(Vector& vVec, double dNum);
};


#endif                                                    // !_VECTOR_H


