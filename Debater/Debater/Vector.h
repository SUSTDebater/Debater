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
		void getAngle(double dDir);						  //ȡ���Ⱥͷ���Ƕ�
		bool reMod(unsigned int uLen);
		bool reAngle(double dDir);                        //�ж��Ƿ��������
	public:
		Vector &add(const Vector &vVec);
		Vector &minus(const Vector &vVec);                     //����֮��ļӼ��˳�
		double &multiply(const Vector &vVec);
		double between(const Vector &vVec);               //����֮��ĽǶ�
		bool vertical(const Vector &vVec);                //�ж������Ƿ�ֱ
		bool parallel(const Vector &vVec);                //�ж������Ƿ�ƽ��
		bool equal(const Vector &vVec);                   //�ж������Ƿ����
	public:
		Vector& operator ~();                             //����ȡ������
		Vector& operator *(int n);                        //����һ���˷�ȡ����
		Vector& operator +(const Vector &vVec);           //����һ���Ӻ�
		Vector& operator -(const Vector &vVec);           //����һ������


	private:
		unsigned int    length;                           //����
		double          direction;                        //����Ƕ�
	};
}

#endif                                                    // !_VECTOR_H


