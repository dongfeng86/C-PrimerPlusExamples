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
	const double Rad_to_deg = 45.0 / atan(1.0);      //const���������������ڲ��ģ���˿����������ļ��ж��塣
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
		return Vector(x + b.x, y + b.y);            //ע�⣬���������
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


	//ע�⣬��Ԫ����û���޶�������������ĳ�Ա����
	Vector operator*(double n, const Vector & a)
	{
		return a*n;
	}

	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		//��ϸ�����������Ԫ��������������namespace�������������������Կ�����RECT��
		//��Ԫ������������з��ʱ���ͨ���������С����磬��Ԫ��������ֱ�ӿ�˽�г�Աx,y�ȵ�
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