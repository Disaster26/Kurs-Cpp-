#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
typedef int64_t int64;

bool czyPierwsza (int64 liczba)
{
    int temp=liczba;
    if(liczba<2)
        return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹
    for(int i=2; i<=sqrt(temp); i++)
        if(liczba%i==0)
            return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
    return true;

}

int64 StringToInt64(string wejscie)
{
    int64 liczba=0;
    string zakres="-9223372036854775808";
    try
    {
        for(int i=0;i<wejscie.size();i++){
                if(i==wejscie.size()-1){
                    if(wejscie==zakres){
                        liczba=liczba*10;
                        break;
                }}
                if(wejscie.at(i)=='-'){ if(i!=wejscie.size()-1) i++;} /// na wypadek gdyby np. 13123-
                int64 cyfra=wejscie.at(i);
                if(cyfra>=48 && cyfra<=57){ /// kody ascii od 0 do 9
                    liczba=liczba*10;
                    liczba=liczba+cyfra-'0';
                }
                else throw invalid_argument("Bledny argument2");
        }
        if(wejscie.at(0)=='-') liczba=liczba*(-1);
        if(wejscie==zakres) liczba=liczba-(wejscie.at(wejscie.size()-1)-'0');
        return liczba;
    }
    catch (const invalid_argument )
    {
        cerr << "Bledny argument";
        exit(0);
    }
}

vector <int64> Czynniki(int64 liczba)
{
    vector <int64> odp;
    if(liczba<0)
    {
        cout << "-1*";
        liczba=liczba*-1;
    }
    while (liczba%2 == 0)
    {
        odp.push_back(2);
        liczba = liczba/2;
    }
    for (int64 i = 3; i <= sqrt(liczba); i = i+2)
    {
        while (liczba%i == 0)
        {
            odp.push_back(i);
            liczba = liczba/i;
        }
    }
    if (liczba > 2) odp.push_back(liczba);
    return odp;
}

int main(int argc, char * argv[])
{
    if(argc<2)
    {
        cout << "Wpisz liczbe z przedzialu [-9,223,372,036,854,775,808 ; 9,223,372,036,854,775,807] ";
        return 0;
    }
    int64 liczba=StringToInt64(argv[1]);
    if(liczba==-1 || liczba==1 || liczba ==0)
    {
        cout <<liczba << " = " <<liczba;
        return 0;
    }
    cout <<liczba<<" = ";
    vector <int64> odp=Czynniki(liczba);
    for(unsigned int i=0; i<odp.size(); i++)
    {
        cout<<odp[i];
        if(i!=odp.size()-1) cout << "*";
    }
    return 0;
}
