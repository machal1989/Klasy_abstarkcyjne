// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class CWielokat {
public:
	virtual int pole () = 0;
	virtual int obwod (int a, int b) 
	{
		return( a + b );
	}
};

class CProstokat: public CWielokat {
	int szerokosc, wysokosc;
public:
	CProstokat(int a, int b): szerokosc(a), wysokosc(b){};
	int pole ()
	{
		return (szerokosc * wysokosc);
	}
};

class CTrojkat: public CWielokat {
	int szerokosc, wysokosc;
public: 
	CTrojkat(int a, int b): szerokosc(a), wysokosc(b){};
	int pole ()
	{
		return (wysokosc * szerokosc/2);
	}
};



class Czlowiek {
public:
	virtual void pij(int a) = 0;
	virtual string przedstaw_sie() = 0;

};


class Student: public Czlowiek {
	string imie, nazwisko, d;
	int NrIndeksu;
public:
	Student( string a, string b, int c): imie(a), nazwisko(b), NrIndeksu(c) {};
	string przedstaw_sie()
	{
		return imie + "   " + nazwisko + "   " + to_string(NrIndeksu);
	}
	void pij(int a)
	{
		if(a<=4)
			d = " drinki";
		else
			d = " drinkow";
		cout << "Jestem studentem moge pic do porzygu, wypije wszystkie " << a << d  << endl;
	}
};

class Pracownik: public Czlowiek {
	string imie, nazwisko;
public:
	Pracownik( string a, string b): imie(a), nazwisko(b) {};
	string przedstaw_sie()
	{
		return imie + "   " + nazwisko;
	}
	void pij(int a)
	{
		if(a<=4)
			cout << "Wypilem " << a << " drinkow" << endl;
		else
			cout << "Moge wypic tylko 4 drinki, pozostale " << (a-4) << " przekazuje mojemu koledze z kolejki" << endl;
	}
};


string przedtsawienie(Czlowiek* obj)
{
	return obj->przedstaw_sie();
}

void wypij(Czlowiek* obj, int a)
{
	obj->pij(a);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int dlugosc;
	CProstokat prostakat1(3,12);
	CTrojkat troj1(12,5);
	Czlowiek* wsk3;

	CWielokat* wsk1 = &prostakat1;
	CWielokat* wsk2 = &troj1;

	

	cout << wsk1->pole() << endl;
	cout << wsk2->pole() << endl;

	cout << "Podaj dlugosc kolejki" << endl;
	cin >> dlugosc;
	Czlowiek **wsk = new Czlowiek*[dlugosc];

	for (int i=0; i<dlugosc; i++)
	{
		int zmienna_obiektu;
		cout << "Jesli chcesz wprowadzic studenta wcisnij 0, jezeli pracownika wcisnij 1" << endl;
		cin >> zmienna_obiektu;
		string imie;
		string nazwisko;
		int nr_ind;
		if (zmienna_obiektu)
		{
			cout << "Podaj imie" << endl;
			cin >> imie;
			cout << "Podaj nazwisko" << endl;
			cin >> nazwisko;
			Czlowiek *wsk_prac = new Pracownik(imie, nazwisko);
			*(wsk + i) = wsk_prac;
		}
		else 
		{
			cout << "Podaj imie" << endl;
			cin >> imie;
			cout << "Podaj nazwisko" << endl;
			cin >> nazwisko;
			cout << "Podaj nr indeksu" << endl;
			cin >> nr_ind;
			Czlowiek *wsk_prac = new Student(imie, nazwisko, nr_ind);
			*(wsk + i) = wsk_prac;
		}
	}
	cout << "A teraz wszyskie osoby w kolejce przedstawia sie " << endl;


	
	for (int i=0; i<dlugosc; i++)
	{
		cout << (*(wsk+1))->przedstaw_sie() << endl; 
		//string n = przedtsawienie(*(wsk+1));
	}



	system("pause");
	return 0;
}

