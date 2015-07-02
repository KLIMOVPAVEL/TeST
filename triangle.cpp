#pragma warning(disable:4715)
#pragma warning(disable:4716)


#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class Triangle
{
protected:
	double a, b,d;

public:

	Triangle::Triangle(double a1, double b1, double d1)
		{
			a = a1;
			b = b1;
			d = d1;
		}
	virtual double AreaSR()=0;
	virtual double PerimetrP()=0;
	virtual void printe()=0;


};




//Класс коллекции для хранения данных
template < typename SimpoleType> 
class Sekvester
{
private:

	SimpoleType* mas;
	int size;

public:
	void setValue(int index, SimpoleType value)
	{
		if (index < size)
			mas[index] = value;
		else
			cout << "Ne dopustimoe znach" << endl;
	}
	Sekvester(int n = 5)
	{
		size = n;
		mas = new SimpoleType[n];
	}
	~Sekvester()
	{
		delete[] mas;

	}
	SimpoleType getSize()
	{
		return size;
	}
	SimpoleType getValue(int index)
	{
		if (index < size)
			return mas[index];
		else
		{
			cout << "Ne dopustimoe znach" << endl;

		}

	}
};

class RavnoTria :public Triangle
{
public:
	//RavnoTria() :Triangle()
	//{}
	RavnoTria(int sidea, int sideb, int angle):Triangle(sidea,sideb,angle)
	{
		a = sidea;
		b = sideb;
		d = angle;
	};
	virtual double AreaSR()
	{
		
		double h,s;
		h = sqrt(a*a - (a*a) / 4);
		if (a != 0)
		{
			s = (a*h) / 2;
			return s;
		}
		else
		{
			cout << "Area not aviable!" << endl;
		}
	}
	virtual double PerimetrP()
	{
		double p ;
		if (a != 0)
		{
			p = 3 * a;
			return p;
		}
		else
		{
			cout << "Perimetr not aviable!" << endl;
		}
	}
	virtual void printe()
	{
		cout << "Area Ravnostorontr:" << endl;
		cout << (a*sqrt(a*a - (a*a) / 4)) / 2 << endl;
		cout << "Perimetr Ravnostorontr:" << endl;
		cout << 3 * a << endl;
	}
};

class RavnobedTria : public Triangle
{

public:
	//RavnobedTria():Triangle()
	//{};

	RavnobedTria(int sidea, int sideb, int angle) :Triangle(sidea, sideb, angle)
	{
		a = sidea;//side naklona treug
		b = sideb;//osnovanie treyg
		d = angle;//ugol 
	};

	virtual double AreaSR()
	{
		double h;
		h = sqrt(a*a - (b*b) / 4);
		if ((a != 0) && (b != 0))
		{
			double s = (b*h) / 2;
			return s;
		}
		else
			cout << "Area not aviable!" << endl;

	}

	virtual double PerimetrP()
	{
		double p;

		if ((a != 0) && (b != 0))
		{
			p = 2 * a + b;
			return p;
		}
		else
			cout << "Perimetr not aviable!" << endl;

	}
	virtual void printe()
	{
		cout << "Area Ravnobed:" << endl;
		cout << (b*sqrt(a*a - (b*b) / 4)) / 2 << endl;
		cout << "Perimetr Ravnobed:" << endl;
		cout << 2 * a + b << endl;
	}
};

class PryamoTria : public Triangle
{

public:
	//PryamoTria():Triangle()
	//{};

	PryamoTria(int sidea, int sideb, int angle):Triangle(sidea,sideb,angle)
	{
		a = sidea;
		b = sideb;
		d = angle;
	};

	virtual double AreaSR()
	{
		if ((a != 0) && (b != 0))
		{
			double s = (a * b) / 2;
			return s;
		}
		else
		{
			cout << "Area not aviable!" << endl;
		}
	}

	virtual double PerimetrP()
	{
		double p, h, c;
		h = sqrt(a*a - (b*b) / 4);
		c = sqrt(h*h + (b*b) / 4);
		if ((a != 0) && (b != 0) && (c != 0))
		{
			p = a + b + c;
			return p;
		}
		else
			cout << "Perimetr not aviable!" << endl;
	}
	virtual void printe()
	{
		cout << "Area Pryamoug:" << endl;
		cout << (a * b) / 2 << endl;
		cout << "Perimetr Pryamoug:" << endl;
		cout << a + b + sqrt((sqrt(a*a - (b*b) / 4))*(sqrt(a*a - (b*b) / 4)) + (b*b) / 4) << endl;
	}
};

typedef Sekvester< Triangle* > Collection;

class Series
{
private:
	Collection* series;
public:
	Series(int size)
	{
		series = new Collection[size];
	}
	void setValue(int index, Triangle* value)
	{
		series->setValue(index, value);
	}
	double getValue(int n)
	{
		return series->getValue(n)->AreaSR();
		//return series->getValue(n)->PerimetrP();
	}
	void printes(int n)
	{
	return series->getValue(n)->printe();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	
	RavnobedTria* rt = new RavnobedTria(3, 4,1);
	PryamoTria* pt = new PryamoTria(7, 2,1);
	RavnoTria* pr = new RavnoTria(3,3,1);
	Series series(3);
	series.setValue(0, rt);
	series.setValue(1, pt);
	series.setValue(2, pr);
	series.printes(2);
	
	system("pause");
	// виртуальные функции и шаблон класса
}
