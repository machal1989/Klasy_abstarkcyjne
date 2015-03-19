// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class CWielokat {
protected:
	int szerokosc, wysokosc;
public:
	void ustaw_wartosci ( int a, int b)
	{
		szerokosc = a;
		wysokosc = b;
	}
	virtual int pole () = 0;
};

class CProstokat: public CWielokat {
public:
	int pole ()
	{
		return (szerokosc * wysokosc);
	}
};

class CTrojkat: public CWielokat {
public: 
	int pole ()
	{
		return (wysokosc * szerokosc/2);
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	CProstokat prostakat1;
	CTrojkat troj1;

	CWielokat* wsk1 = &prostakat1;
	CWielokat* wsk2 = &troj1;

	wsk1->ustaw_wartosci(5,5);
	wsk2->ustaw_wartosci(6,4);

	cout << wsk1->pole() << endl;
	cout << wsk2->pole() << endl;

	system("pause");
	return 0;
}

