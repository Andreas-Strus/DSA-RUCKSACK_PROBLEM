#include "sort.hpp"

using namespace std;

int main()
{
//deklaracje wst�pne
	std::string p, p2;
	int lengh, IndexLiczby, NumAlg, Mass, Pivot, i=1, j, a, vD, vZ;
	time_t CzasZ, CzasD;
	bool Prepared=false, AllQsi=false, test=true;
//pobranie warunow analizy
	std::cout<<"podaj �cierzk� pliku instancji"<<std::endl;
	std::cin>>p;
	std::cout<<"podaj �cierzk� pliku wyj�ciowego"<<std::endl;
	std::cin>>p2;
	std::cout<<"Czy instancje zawieraja stosowny wiersz wst�pny? (�adownosc statku, liczba element�w, rodzaj instancji)"<<std::endl;
	std::cin>>Prepared;
	for (j=0; j<i; j++)
	{
//otwarcie plik�w wej�cia i wyjscia
		std::fstream PlikIn, PlikOut, Pl;
		PlikIn.open(p.c_str(), std::ios::in);
		PlikOut.open(p2.c_str(), std::ios::app);
//Pobranie danych o pierwszej instancji
		if (Prepared) PlikIn >> Mass >>lengh>>NumAlg;
		else 
		{			
			std::cout<<"Wybierz warto�� nie ulegaj�c� zmianie:"<<std::endl<<"1. Ladowno�c statku"<<std::endl<<"2. liczba kontener�w"<<std::endl;
			std::cin>>NumAlg;
			std::cout<<"Podaj �adowno�� statku"<<std::endl;
			std::cin>>Mass;
			std::cout<<"Podaj liczb� rozwa�anych kontener�w"<<std::endl;
			std::cin>>lengh;
		}
		while ( lengh != 0)		//P�tla wykonawcza, powtarzana p�ki w pliku wej�cowym s� jakie� instancje do pobrania
		{
			CzasZ=0;
			CzasD=0;		
			kontener* TabGl = new kontener[lengh];
			for (IndexLiczby=0; IndexLiczby<lengh; IndexLiczby++) //P�tla pobierania danych instancji do tabeli g�ownej
			{
				PlikIn>>TabGl[IndexLiczby].size>>TabGl[IndexLiczby].value;
				TabGl[IndexLiczby].density = TabGl[IndexLiczby].value/TabGl[IndexLiczby].size;
				TabGl[IndexLiczby].lp = IndexLiczby + 1;
			}	
			CzasD = dynamiczny(TabGl, vD, lengh, Mass, NumAlg, p2);
			CzasZ = zachlanny(TabGl, vZ, vD, lengh, Mass, NumAlg, p2);
			lengh = 0;
			if (Prepared) PlikIn >> Mass >>lengh>>NumAlg;	//Pobranie danych o nast�pnej instancji
			else 
			{			
				std::cout<<"Wybierz warto�� nie ulegaj�c� zmianie:"<<std::endl<<"1. Ladowno�c statku"<<std::endl<<"2. liczba kontener�w"<<std::endl;		
				std::cout<<"Wybierz stosowany algorytm:"<<std::endl<<"1. Insertion Sort"<<std::endl<<"2. Selsction Sort"<<std::endl;
				std::cin>>NumAlg;
				std::cout<<"Podaj �adowno�� statku"<<std::endl;
				std::cin>>Mass;
				std::cout<<"Podaj liczb� rozwa�anych kontener�w"<<std::endl;
				std::cin>>lengh;
			}	
		}
		void close(void);
		system("pause");
	}
	return 0;
}
