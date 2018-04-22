#include "sort.hpp"

using namespace std;

int main()
{
//deklaracje wstêpne
	std::string p, p2;
	int lengh, IndexLiczby, NumAlg, Mass, Pivot, i=1, j, a, vD, vZ;
	time_t CzasZ, CzasD;
	bool Prepared=false, AllQsi=false, test=true;
//pobranie warunow analizy
	std::cout<<"podaj œcierzkê pliku instancji"<<std::endl;
	std::cin>>p;
	std::cout<<"podaj œcierzkê pliku wyjœciowego"<<std::endl;
	std::cin>>p2;
	std::cout<<"Czy instancje zawieraja stosowny wiersz wstêpny? (³adownosc statku, liczba elementów, rodzaj instancji)"<<std::endl;
	std::cin>>Prepared;
	for (j=0; j<i; j++)
	{
//otwarcie plików wejœcia i wyjscia
		std::fstream PlikIn, PlikOut, Pl;
		PlikIn.open(p.c_str(), std::ios::in);
		PlikOut.open(p2.c_str(), std::ios::app);
//Pobranie danych o pierwszej instancji
		if (Prepared) PlikIn >> Mass >>lengh>>NumAlg;
		else 
		{			
			std::cout<<"Wybierz wartoœæ nie ulegaj¹c¹ zmianie:"<<std::endl<<"1. Ladownoœc statku"<<std::endl<<"2. liczba kontenerów"<<std::endl;
			std::cin>>NumAlg;
			std::cout<<"Podaj ³adownoœæ statku"<<std::endl;
			std::cin>>Mass;
			std::cout<<"Podaj liczbê rozwa¿anych kontenerów"<<std::endl;
			std::cin>>lengh;
		}
		while ( lengh != 0)		//Pêtla wykonawcza, powtarzana póki w pliku wejœcowym s¹ jakieœ instancje do pobrania
		{
			CzasZ=0;
			CzasD=0;		
			kontener* TabGl = new kontener[lengh];
			for (IndexLiczby=0; IndexLiczby<lengh; IndexLiczby++) //Pêtla pobierania danych instancji do tabeli g³ownej
			{
				PlikIn>>TabGl[IndexLiczby].size>>TabGl[IndexLiczby].value;
				TabGl[IndexLiczby].density = TabGl[IndexLiczby].value/TabGl[IndexLiczby].size;
				TabGl[IndexLiczby].lp = IndexLiczby + 1;
			}	
			CzasD = dynamiczny(TabGl, vD, lengh, Mass, NumAlg, p2);
			CzasZ = zachlanny(TabGl, vZ, vD, lengh, Mass, NumAlg, p2);
			lengh = 0;
			if (Prepared) PlikIn >> Mass >>lengh>>NumAlg;	//Pobranie danych o nastêpnej instancji
			else 
			{			
				std::cout<<"Wybierz wartoœæ nie ulegaj¹c¹ zmianie:"<<std::endl<<"1. Ladownoœc statku"<<std::endl<<"2. liczba kontenerów"<<std::endl;		
				std::cout<<"Wybierz stosowany algorytm:"<<std::endl<<"1. Insertion Sort"<<std::endl<<"2. Selsction Sort"<<std::endl;
				std::cin>>NumAlg;
				std::cout<<"Podaj ³adownoœæ statku"<<std::endl;
				std::cin>>Mass;
				std::cout<<"Podaj liczbê rozwa¿anych kontenerów"<<std::endl;
				std::cin>>lengh;
			}	
		}
		void close(void);
		system("pause");
	}
	return 0;
}
