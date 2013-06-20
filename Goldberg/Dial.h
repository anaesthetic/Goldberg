#ifndef DIAL_
#define DIAL_
/* algorytm Diala jako parametr wczytuje graf o krawedziach z wagami
 * CALKOWITYMI i wykonuje algorytm SSSP z zadanego zrodla s.
 * Dodatkowym wymaganiem jest ograniczenie na dlugosc najkrotszej sciezki
 * <= N
 * Wtedy algorytm dziala liniowo (M+N)
 */
 
class Dial{

public:
	//konstruktor z zadana referencja do grafu oraz zrodlem (default NULL)
	Dial(Graph& G, node source = 0);
	
	//byc moze bedziemy chcieli miec tylko jeden obiekt Dial ktory
	//dla roznych grafow bedize wykonywac algorytm SSSP. Dlatego
	//warto zapewnic metode ktora pozwala "zrestartowac" algorytm
	//DIALA.
	void reaload(G, node source = 0);
	
	//ta funkcja ma zwracac referencje do tablicy z wartosciami 
	//najkrotszych sciezek dla wierzcholkow G.
	NodeArray < int > & getD(){
		return m_d;
	}
	
	//ta funkcja ma zwracac referencejt o tablicy z poprzednikami
	//w najkrotszych sciezkach
	NodeArray < int > & getPreds(){
		return m_preds;
	}

private:

	//wskaznik na tablice z kubelkami uzytymi do znalezienia najkrotszych
	//sciezek. Kazdy kubelek to lista < node >.
	DoubleList < node > * m_buckets;
	
	//tablica przechowujaca wynik algorytmu: wartosci najkrotszych 
	//sciezek
	NodeArray < int > m_d;
	
	//tablica przechowujaca wynik algorytmu: wskaznik na poprzednika
	//w najkrotszej sciezce
	NodeArray < node > m_preds;
};
#endif
