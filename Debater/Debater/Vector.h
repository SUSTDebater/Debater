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
		double getAngle();						          //ȡ���Ⱥͷ���Ƕ�
		bool reMod(double dLen);
		bool reAngle(double dDir);                        //�ж��Ƿ��������
	public:
		Vector & add(const Vector &vVec);
		Vector &minus(const Vector &vVec);                //����֮��ļӼ��˳�
		double multiply(const Vector &vVec);
		Vector &multiply(double dNum);
		double between(const Vector &vVec);               //����֮��ĽǶ�
		bool vertical(const Vector &vVec);                //�ж������Ƿ�ֱ
		bool parallel(const Vector &vVec);                //�ж������Ƿ�ƽ��
		bool equal(const Vector &vVec);                   //�ж������Ƿ����
	public:
		Vector & operator ~();                            //����ȡ������
		double operator *(const Vector& vVec);            //����һ���˷�ȡ����
		Vector& operator +(const Vector &vVec);           //����һ���Ӻ�
		Vector& operator -(const Vector &vVec);           //����һ������
		Vector& operator =(const Vector &vVec);
		bool operator ==(const Vector &vVec);


	private:
		double    length;                                 //����
		double    direction;                              //����Ƕ�
	};
}

Vector &operator *(const Vector& vVec, double dNum);

#endif                                                    // !_VECTOR_H


