Lista jednokierunkowa w C++
Opis projektu

Projekt przedstawia implementację listy jednokierunkowej w języku C++, której elementy przechowują dane tekstowe odczytane z pliku.

Program wczytuje zawartość pliku dane.txt, tworzy listę jednokierunkową, wyświetla jej elementy w konsoli, a następnie zapisuje dane do pliku wynik.txt.

Funkcjonalności
Odczytywanie danych linia po linii z pliku tekstowego.
Dynamiczne tworzenie elementów listy jednokierunkowej.
Dodawanie nowych elementów na koniec listy.
Wyświetlanie zawartości listy w konsoli.
Zapisywanie danych do pliku wynikowego.
Zwalnianie pamięci zajmowanej przez elementy listy.
Obsługa sytuacji, w której nie można otworzyć pliku wejściowego.
Technologie
Język: C++
Biblioteki: iostream, fstream, string
Struktury danych: lista jednokierunkowa
Pamięć: dynamiczna alokacja i zwalnianie pamięci (new, delete)
Struktura projektu
text
lista-jednokierunkowa/
├── main.cpp
├── dane.txt
├── wynik.txt
└── README.md

main.cpp – kod źródłowy programu.
dane.txt – plik wejściowy zawierający tekst do odczytania.
wynik.txt – plik wynikowy, do którego zapisywana jest zawartość listy.
README.md – dokumentacja projektu.
Jak uruchomić program?
Sklonuj repozytorium lub pobierz pliki projektu.
Utwórz plik dane.txt w katalogu programu i wpisz do niego przykładowe dane, każdą linię oddzielając znakiem nowej linii.
Skompiluj program za pomocą kompilatora C++:
bash
g++ main.cpp -o lista

Uruchom program:

Windows:

bash
lista.exe


Linux:

bash
./lista

Przykład działania

Zawartość pliku dane.txt:

text
Ala ma kota
Programowanie w C++
Lista jednokierunkowa


Wynik wyświetlony w konsoli:

text
Ala ma kota
Programowanie w C++
Lista jednokierunkowa


Taka sama zawartość zostanie zapisana w pliku wynik.txt.

Zastosowane funkcje
wczytajListe() – wczytuje dane z pliku i tworzy listę jednokierunkową.
wyswietliIZapiszListe() – wyświetla elementy listy i zapisuje je do pliku wynikowego.
usunListe() – usuwa wszystkie elementy listy i zwalnia zajmowaną pamięć.
main() – odpowiada za wywołanie poszczególnych funkcji programu.
Cel projektu

Celem projektu jest praktyczne poznanie działania list jednokierunkowych, obsługi plików tekstowych oraz zarządzania pamięcią dynamiczną w języku C++.

Autor

Projekt edukacyjny – C++.
