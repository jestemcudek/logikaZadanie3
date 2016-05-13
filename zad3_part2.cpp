#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

string _or,_not,_and,impl;
int Play();

void clearScreen()
{
	printf("\033[2J"); // Czyści ekran
	printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}


//pokazuje opcje w menu głównym gry
void showOptions(){
    cout<<"1. Rozpocznij gre"<<endl;
    cout<<"2. Pokaz pomoc"<<endl;
    cout<<endl;
    cout<<"Q - wyjscie"<<endl;

}

//napisy koncowe
void endCredits()
{
    clearScreen();
    cout<<"Dziekuje za gre. Do zobaczenia"<<endl;

}

//komunikat w razie wcisniecia złej opcji w menu głównym
void wrongOptionButton(){
    cout<<"Podano niepoprawny klawisz. Dla przypomnienia"<<endl;
    showOptions();


}

//pomoc dla gry
void showHelp(){
    cout << "Zasady tej gry logicznej sa proste."<<endl;
	cout << "Twoim zadaniem jest odpowiedziec poprawnie na 5 zagadek o charaketrze logicznym z logika trojwartosciowa" << endl;
	cout << "Odpowiadasz na nie wpisujac kolejno: " << endl;
	cout << "1 - jesli uwazasz ze zdanie jest prawdziwe" << endl;
	cout << "0 - jesli uwazasz ze zdanie jest falszywe" << endl;
	cout << "Lub X - jesli uwazasz, ze zdaniu nie mozna przyporzadkowac wartosci logicznej. Uwaga, wielkosc znaku ma tutaj znaczenie" << endl;
	cout << "Jesli odpowiesz poprawnie, grasz dalej. Uwazaj! Jesli udzielisz blednej odpowiedzi, przegrywasz"<<endl;
	cout << "Powodzenia!"<<endl;

}

//sprawdzanie wyniku dla or, and lub implikacji
char checkResult(const string & file, char a, char b)
{
	string line;
	fstream valueLogicFile;
	char result;
	valueLogicFile.open(file.c_str());
    while(getline(valueLogicFile, line)!=NULL)
    {
		if(line[0]==a and line[2]==b)
		{
			result = line[4];
			return result;
		}
	}
	return ' ';
}

//sprawdzanie wyniku dla negacji
char checkNegationResult(const string & file, char a)
{
	string line;
	fstream valueLogicFile;
	char result;
	valueLogicFile.open(file.c_str());
    while(getline(valueLogicFile, line)!=NULL)
    {
		if(line[0]==a)
		{
			result = line[2];
			return result;
		}
	}
	return ' ';
}

//wyswietlanie koncowych statystyk
void showGameResult(int score){
    if(score==7)
        cout<< "Gratulacje! Ukonczyles gre w calosci z wynikiem 7 punktow"<<endl;
    else
        cout<<"Przegrales! Uzyskales "<<score<<" punktow"<<endl;

}

int main(int argc, char **argv)
{

    string argms[argc+1];

    if(argc!=9)
    {
        cout<<"Podano nieodpowiednia ilosc argumentow. Wymagana ilosc wynosi 8"<<endl;
        return 0;
    }

    for(int i=1;i<argc;i++)
	{
		argms[i]=argv[i];
	}

	for(int i=1; i<argc;i+=2)
	{
		if(argms[i]=="--not") _not = argms[i+1];
		if(argms[i]=="--or") _or = argms[i+1];
		if(argms[i]=="--and") _and = argms[i+1];
		if(argms[i]=="--impl") impl = argms[i+1];
	}

    cout << "Witaj, wybierz nastepujace opcje" << endl;
    char option;
    int score=0;

    do{
        showOptions();
        cin>>option;
        switch(option){
            case '1':   score=Play();
                        showGameResult(score);
                        break;
            case '2': showHelp();
                        break;
            case 'q': endCredits();
                        break;
            default: wrongOptionButton();
                        break;
        }
    }
    while(option!='q');
    endCredits();
    return 0;
}


int Play(){
    int score=0;
    char answer;

    cout<<"Zagadka 1"<<endl;
    cout<<"Wszystkie siostry Kamila maja tylko jednego brata, a jego kolega, Alek ma siostrê. Czy obaj maja braci?"<<endl;
    do{
        cin>>answer;
        if(answer!='1' and answer!='0' and answer!='X')
            cout<<"Podano nieprawidlowy znak. Dozwolone znaki to: 1,0 lub X"<<endl;
    }while(answer!='1' and answer!='0' and answer!='X');
    char Kamil='0';
    char Alek='X';

    if (answer==checkResult(_and,Kamil,Alek)) score++;
    else return score;

    cout << "Zagadka 2" << endl;
	cout << "Marcin lubi psy, a Andrzej ich nie lubi. Monika nigdy nie mia³a psa. Czy mozna powiedziec, ze albo Andrzej lub Monika lubi¹ kpsy albo, ¿e nie prawda jest ze Andrzej i Marcin lubi¹ psy?" << endl;
	do{
        cin>>answer;
        if(answer!='1' and answer!='0' and answer!='X')
            cout<<"Podano nieprawidlowy znak. Dozwolone znaki to: 1,0 lub X"<<endl;
    }while(answer!='1' and answer!='0' and answer!='X');
	char Ma = '1';
	char Mo = 'X';
	char A = '0';

	if(answer==checkResult(_or, checkResult(_or, A, Mo), checkNegationResult(_not, checkResult(_and, A, Ma)))) score++;
	else return score;


	cout<<"Zagadka 3"<<endl;
	cout <<"Jeżeli 3>1, to 2<1. Jaka jest wartosc logiczna tego zdania?"<<endl;
	do{
        cin>>answer;
        if(answer!='1' and answer!='0' and answer!='X')
            cout<<"Podano nieprawidlowy znak. Dozwolone znaki to: 1,0 lub X"<<endl;
    }while(answer!='1' and answer!='0' and answer!='X');
	char r1='0';
	char r2='1';
	if(answer==checkResult(impl,r1,r2)) score++;
    else return score;

	cout << "Zagadka 4" << endl;
	cout << "Kobiety bardzo czesto wszczynaja kłótnie. Czy z tego wynika że brak kobiety to brak kłótni?" << endl;
	do{
        cin>>answer;
        if(answer!='1' and answer!='0' and answer!='X')
            cout<<"Podano nieprawidlowy znak. Dozwolone znaki to: 1,0 lub X"<<endl;
    }while(answer!='1' and answer!='0' and answer!='X');
	char women = '1';
	char quarrel = '1';

    if(answer==checkResult(impl, checkResult(impl, women, quarrel), checkResult(impl, checkNegationResult(_not, women), checkNegationResult(_not, women)))) score++;
	else return score;

    cout<<"Zagadka 5"<<endl;
    cout<<"Wielka Brytania jest czlonkiem Unii Europejskiej. Czy z tego mozna wywnioskowac, ze obowiazujaca waluta w UK jest Euro?"<<endl;
    do{
        cin>>answer;
        if(answer!='1' and answer!='0' and answer!='X')
            cout<<"Podano nieprawidlowy znak. Dozwolone znaki to: 1,0 lub X"<<endl;
    }while(answer!='1' and answer!='0' and answer!='X');
	char uk = '1';
	char currency = '0';
    if(answer==checkResult(impl,uk,currency)) score++;

    return score;
}
