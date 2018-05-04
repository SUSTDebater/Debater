#ifndef _VECTOR_H
#define _VECTOR_H

#include "Head.h"

namespace SUST {
	class Vector {
	public:
		Vector() {};
		Vector(unsigned int uLen, double dDir);
		~Vector() {};
		void getMod(unsigned int uLen);
		void getAngle(double dDir);						  //取长度和方向角度
		bool reMod(unsigned int uLen);
		bool reAngle(double dDir);                        //判断是否输入错误
	public:
		Vector &add(const Vector &vVec);
		Vector &minus(const Vector &vVec);                     //向量之间的加减乘除
		double &multiply(const Vector &vVec);
		double between(const Vector &vVec);               //向量之间的角度
		bool vertical(const Vector &vVec);                //判断向量是否垂直
		bool parallel(const Vector &vVec);                //判断向量是否平行
		bool equal(const Vector &vVec);                   //判断向量是否相等
	public:
		Vector& operator ~();                             //重载取反方向
		Vector& operator *(int n);                        //重载一个乘法取数乘
		Vector& operator +(const Vector &vVec);           //重载一个加号
		Vector& operator -(const Vector &vVec);           //重载一个减号


	private:
		unsigned int    length;                           //长度
		double          direction;                        //方向角度
	};
}

#endif                                                    // !_VECTOR_H


