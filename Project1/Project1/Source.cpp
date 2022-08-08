#include <iostream>
#include <conio.h>
#include <crtdbg.h>
#include "timeHeader.h"
#include "harmonogramHeader.h"

int main()
{
	Harmonogram mySchedule;
	mySchedule.addToSchedule(52);
	mySchedule.addToSchedule(525);
	mySchedule.addToSchedule(5227);
	mySchedule.addToSchedule(22221);
	mySchedule.addToSchedule(215112);
	mySchedule.addToSchedule(272);
	mySchedule.addToSchedule(2154632);
	mySchedule.addToSchedule(16846);
	char choice = '0';
	system("cls");
	while (choice != 'x')
	{
		std::cout << "Aby wyjsc z programu wcisnij 'x'." << std::endl;
		std::cout << "0) Wyswietlenie czasow w harmonogramie." << std::endl;
		std::cout << "1) Wyswietlenie pierwszych n czasow z harmonogramu." << std::endl;
		std::cout << "2) Wyswietlenie tyle pierwszych czasow z harmonogramu, w ktorych suma miesci sie w podanym przez uzytkownika zakresie." << std::endl;
		std::cout << "3) Zwiekszanie wybranego czasu z harmonogramu o dana ilosc sekund." << std::endl;
		choice = _getch();
		switch (choice)
		{
		case '0': //wyswietlenie czasow na ekran
		{
			system("cls");
			mySchedule.viewSchedule();
			break;
		}
		case '1': //wyswietla pierwsze n czasow w harmonogramie
		{
			system("cls");
			int n = 0;
			std::cout << "Wprowadz liczbe n czasow do wyswietlenia: ";
			std::cin >> n;
			Harmonogram schedule1(mySchedule);
			schedule1.nSchedules(n);
			schedule1.viewSchedule();
			break;
		}
		case '2': //wyswietla czasy z harmonogramu zawierajace sie w zakresie
		{
			system("cls");
			Time zakres;
			zakres.timeInput();
			Harmonogram schedule2(mySchedule);
			schedule2.rangeSchedule(zakres);
			schedule2.viewSchedule();
			break;
		}
		case '3':
		{
			system("cls");
			mySchedule.viewSchedule();
			int index = 0;
			int add = 0;
			std::cout << "Wprowadz indeks czasu do ktorego zostana dodane sekundy: ";
			std::cin >> index;
			std::cout << "Wprowadz o ile sekund zwiekszyc wybrany czas: ";
			std::cin >> add;
			index -= 1;
			mySchedule.addTime(add, index);
			break;
			
		}
		case 'x':
		{
			break;
		}
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}