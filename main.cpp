#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_file("instrukcje.txt");
    // ifstream in_file("przyklad.txt");



    string polecenie;
    char znak;

    string napis = "";

    int ile_dopisz = 0;
    int ile_zmien = 0;
    int ile_usun = 0;
    int ile_przesun = 0;

    int maksymalny_ciag = 0;
    string rodzaj_instrukcji = "";

    int tablica_liter[100];  // czy bêd¹ zera
    for(int i = 0; i < 100; i++){
        tablica_liter[i] = 0;
    }

    while( in_file >> polecenie >> znak){

            cout << polecenie << " " << znak << endl;

            if (polecenie == "DOPISZ"){
                napis += znak;

                ile_dopisz++;
                ile_zmien = 0;
                ile_usun = 0;
                ile_przesun = 0;

                int indeks = char(znak);
                cout << indeks << endl;
                tablica_liter[indeks]++;
            }

            if (polecenie == "ZMIEN")
            {
                int last_index = napis.length();
                napis[last_index-1] = znak;

                ile_dopisz = 0;
                ile_zmien++;
                ile_usun = 0;
                ile_przesun = 0;
            }

            if (polecenie == "USUN")
            {
                int length = napis.length();
                napis.erase(length-1);

                ile_dopisz = 0;
                ile_zmien = 0;
                ile_usun++;
                ile_przesun = 0;
            }


            if (polecenie == "PRZESUN")
            {
                int index = napis.find(znak);

                // cout << "index: " << index << endl;

                char c = (char)napis[index];

                // cout << "znak: " << c << endl;

                if ( c == 'Z' )
                {
                    c = 'A';
                }
                else
                {
                    c = c + 1;
                }
                napis[index] = c;

                ile_dopisz = 0;
                ile_zmien = 0;
                ile_usun = 0;
                ile_przesun++;
            }

            // cout << napis << endl << endl;

            if (ile_dopisz > maksymalny_ciag)
            {
                maksymalny_ciag = ile_dopisz;
                rodzaj_instrukcji = polecenie;
            }

            if (ile_zmien > maksymalny_ciag)
            {
                maksymalny_ciag = ile_zmien;
                rodzaj_instrukcji = polecenie;
            }

            if (ile_usun > maksymalny_ciag)
            {
                maksymalny_ciag = ile_usun;
                rodzaj_instrukcji = polecenie;
            }

            if (ile_przesun > maksymalny_ciag)
            {
                maksymalny_ciag = ile_przesun;
                rodzaj_instrukcji = polecenie;
            }
    }

    ofstream wyniki("wyniki4.txt");
    wyniki << "4.1 " << napis.length() << endl;

    wyniki << "4.2 " << rodzaj_instrukcji << " " << maksymalny_ciag << endl;

    // zadanie 4.3
    int maks = 0;
    int indeks = 0;
    char litera;

    cout << tablica_liter[0] << endl;
    for(int i=0; i < 100; i++){
        cout << tablica_liter[i] << " ";
        if( tablica_liter[i] > maks)
        {
            maks = tablica_liter[i];
            indeks = i;
        }
    }
    cout << endl;
    litera = char(indeks);

    wyniki << "4.3 " << litera << " " << maks << endl;

    wyniki << "4.4 " << napis << endl;




    return 0;
}
