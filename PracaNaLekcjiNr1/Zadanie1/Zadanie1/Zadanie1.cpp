#include <iostream>
#include <string>
using namespace std;

// Funkcja 'check' sprawdza czy podany tekst jest zapisany z małych liter
bool check(string tekst)
{	
	for (int i = 0; i < tekst.length(); i++)
	{
		if ((tekst[i] > 96 && tekst[i] < 123) || tekst[i] == 32)
			continue;
		else
			return false;

		return true;
	}
}

int main()
{
	string tekst;

	cout << "Podaj tekst do szyfrowania (Uzyj jedynie malych liter!)\n";
	while (true)
	{
		getline(cin, tekst);

		if (!check(tekst))
			cout << endl << "Podaj poprawny tekst!" << endl;
		else
			break;
	}
}
