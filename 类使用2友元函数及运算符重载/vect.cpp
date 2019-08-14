#include<cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);      //const常量的链接性是内部的，因此可以在所有文件中定义。
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
			ang = atan2(y, x);
	}
	void Vector::set_x()
	{
		x = mag*cos(ang);
	}
	void Vector::set_y()
	{
		y = mag*cos(ang);
	}
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (mode == POL)
		{
			mag = n1;
			ang = n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "incorrec 3rd argument to vector()--";
			cout << "vector set to 0\n";
			Vector();
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "incorrect 3rd argument to vector()--";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);            //注意，这个可以用
	}

	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n*x, n*y);
	}


	//注意，友元函数没有限定符，他不是类的成员函数
	Vector operator*(double n, const Vector & a)
	{
		return a*n;
	}

	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		//仔细看这里，由于友元函数的作用域是namespace，而不是类作用域，所以看不到RECT；
		//友元函数对类的所有访问必须通过类对象进行。比如，友元函数不能直接看私有成员x,y等等
		if (v.mode == Vector::RECT)
			os << "(x,y)" << "x=" << v.x << ";y=" << v.y << std::endl;
		else if (v.mode == Vector::POL)
		{
			os << "(m,a)" << "m=" << v.mag << ";a=" << v.ang*Rad_to_deg << std::endl;
		}
		else
			os << "vector object mode is invalid";
		return os;
	}
}