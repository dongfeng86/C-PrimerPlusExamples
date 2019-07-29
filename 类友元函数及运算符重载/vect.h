//vect.h
#pragma once

#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode{RECT,POL};	      //注意这个枚举值，不是作用域枚举类型，作用域需要加class或者struce
		//RECT for rectangular,POL for Polar modes
	private:
		double x;
		double y;
		double mag;                  //极坐标中的模量
		double ang;
		Mode mode;
		//private methods
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }           //const表明这个函数不会改变调用他的函数
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();

		//operator overloading 
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		//友元函数,仅仅在声明的时候加上friend
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}

