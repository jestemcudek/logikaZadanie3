#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char* argv[]) {

  if(argc!=7)
  {
    cout<<"Uwaga, nie podano dostatecznej ilosc argumentow (liczb calkowitch). Wymagana ilosc: 7"<<endl;
    return 0;
  }

    int one=atoi(argv[1]);
    int two=atoi(argv[2]);
    int three=atoi(argv[3]);
    int four=atoi(argv[4]);
    int five=atoi(argv[5]);
    int six=atoi(argv[6]);
    int seven=atoi(argv[7]);
    
    if(one<=two and three<=four and five >0 and six >0 or (one %two <67 and seven==one)) cout<<1<<endl;
    else cout<<0<<endl;



    return 0;
}
