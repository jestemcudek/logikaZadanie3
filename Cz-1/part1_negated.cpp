#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	if(argc!=8)
	{
		cout << "Błąd! Nie podano odpowiedniej liczby arguemtnow! Wymagana liczba argumentów (liczby całkowite): 7" << endl;
		return 0;
	}
	
	int one = atoi(argv[1]);
	int two = atoi(argv[2]);
	int three = atoi(argv[3]);
	int four = atoi(argv[4]);
	int five = atoi(argv[5]);
	int six = atoi(argv[6]);
	int seven = atoi(argv[7]);
	
	if(one>two and three>four and five <=0 and six<=0 or (one %two >=67 and seven=!one)) cout << 1 << endl;
	else cout << 0 << endl;
	
	return 0;
}
