#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// definicja struktury reprezentuj¹cej pojedynczy element listy
struct Element {
    string dane;
    Element* nastepny; // wskaŸnik na kolejny element
};

/*
 * Nazwa funkcji: wczytajListe
 * Opis dzia³ania: Wczytuje dane linia po linii z pliku tekstowego i tworzy z nich
 *                 listê jednokierunkow¹, dopisuj¹c kolejne elementy na jej koniec.
 * Parametry:
 *   - nazwaPliku: const string& - nazwa pliku wejœciowego, z którego pobierane s¹ dane
 * Zwracana wartoœæ: Element* - wskaŸnik na pierwszy element (g³owê) utworzonej listy lub nullptr w przypadku b³êdu.
 */
Element* wczytajListe(const string& nazwaPliku) {
    Element* pierwszy = nullptr;
    string linia;
    ifstream plikWe(nazwaPliku);

    if (!plikWe.is_open()) {
        return nullptr;
    }

    while (getline(plikWe, linia)) {
        Element* nowy = new Element{linia, nullptr};

        if (!pierwszy) {
            pierwszy = nowy; // jeœli lista by³a pusta, nowy staje siê pierwszym
        }
        else {
            Element* temp = pierwszy;

            while (temp->nastepny) {
                temp = temp->nastepny; // dotarcie do koñca listy
            }

            temp->nastepny = nowy; // dopisanie na koniec
        }
    }

    plikWe.close();
    return pierwszy;
}

/*
 * Nazwa funkcji: wyswietliIZapiszListe
 * Opis dzia³ania: Przechodzi przez ca³¹ listê, wypisuj¹c zawartoœæ ka¿dego elementu
 *                 na konsolê oraz zapisuj¹c j¹ do pliku wynikowego.
 * Parametry:
 *   - pierwszy: Element* - wskaŸnik na pierwszy element listy
 *   - nazwaPlikuWy: const string& - nazwa pliku, do którego zostan¹ zapisane dane
 * Zwracana wartoœæ: Brak (funkcja typu void).
 */
void wyswietliIZapiszListe(Element* pierwszy, const string& nazwaPlikuWy) {
    ofstream plikWy(nazwaPlikuWy);
    Element* aktualny = pierwszy;

    while (aktualny) {
        cout << aktualny->dane << endl;
        if (plikWy.is_open()) {
            plikWy << aktualny->dane << endl;
        }
        aktualny = aktualny->nastepny;
    }

    if (plikWy.is_open()) {
        plikWy.close();
    }
}

/*
 * Nazwa funkcji: usunListe
 * Opis dzia³ania: Iteracyjnie zwalnia pamiêæ przydzielon¹ dynamicznie dla wszystkich
 *                 elementów listy, zapobiegaj¹c wyciekom pamiêci.
 * Parametry:
 *   - pierwszy: Element*& - referencja do wskaŸnika na pierwszy element listy
 * Zwracana wartoœæ: Brak (funkcja typu void).
 */
void usunListe(Element*& pierwszy) {
    while (pierwszy) {
        Element* doUsuniecia = pierwszy;
        pierwszy = pierwszy->nastepny;
        delete doUsuniecia;
    }
}

int main() {
    // Wczytanie listy z pliku dane.txt
    Element* pierwszy = wczytajListe("dane.txt");

    // Przetworzenie listy (wyœwietlenie i zapis do pliku wynik.txt)
    wyswietliIZapiszListe(pierwszy, "wynik.txt");

    // Zwolnienie pamiêci zajmowanej przez listê
    usunListe(pierwszy);

    return 0;
}
