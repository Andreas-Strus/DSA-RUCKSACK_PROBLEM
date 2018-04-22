//Plik: sort.cpp

#include "sort.hpp"

using namespace std;


void zamien (kontener tab[], int a, int b)
{
	kontener c;
	c=tab[a];
	tab[a]=tab[b];
	tab[b]=c;
}

int part (kontener tab[], int first, int last, int p)
//Partition
{
	srand(time(NULL));
	int a, b, c, piv;
	switch (p)
	{
		case 1:
			piv=last;
		break;
		case 2:
			piv=first;
		break;
		case 4:
			piv=(std::rand() % (last - first)) + first;
		break;		
		case 3:
			piv=(first+last)/2;
		break;
	}
	a=first;
	zamien(tab, piv, last);
	b= first;
	for (a = first; a < last; a++)
	{
		if (tab[a].density>tab[last].density)
		{
			zamien(tab, a, b);
			b++;
		}
	}
	zamien (tab, b, last);
	return b;
}


time_t qsi (kontener tab[], int lengh, int piv)
{
	int last=lengh - 1, first = 0, q=0;
	time_t start, stop, tim;
	start = clock();
	stos stos;
	while (first<last || !stos.pusty())
	{
			if(first<last)
			{
				q=part(tab, first, last, piv);
				stos.dodaj(last);
				last = q - 1;
			}
			else
			{
				first = last + 2;
				last = stos.pobierz();	
			}
		}	
	stop = clock();
	tim = (stop - start);
	return tim;
}

void print_tab (int tab[], int lengh)
{
	int i=0;
	for (i = 0; i<lengh; i++)
	{
		std::cout<<tab[i]<<"	";
	}
	std::cout<<std::endl<<std::endl;
}

time_t dynamiczny (kontener tab[], int & vD, int N, int B, int NumAlg, std::string p2)
{
	
	std::fstream PlikOut;
	PlikOut.open(p2.c_str(), std::ios::app);
	int value = 0;
	int suma_wag = 0;
	int awag = 0;
	int aval = 0;
	int a;
	stos lista;
	double suma_wartosci = 0;
	time_t stop = 0, start = clock();
	int** TabPom = new int* [N+1];
	for (int i = 0 ; i <= N; i++) TabPom[i] = new int [B+1];	
	for(int i = 0; i<=N; i++)
	{
		if (i != 0)
		{			
			awag = tab[i-1].size;
		 	aval = tab[i-1].value;
		 	suma_wartosci += aval;
		 	suma_wag += awag;
		}
		for(int j=0; j<=B;j++)
		{
			if (i == 0 || j ==0)
			{
				TabPom[i][j] = 0;
			}
			else
			{
				if (j < awag)
				{
					TabPom[i][j] = TabPom[i-1][j];
				}
				else
				{
					if (TabPom[i-1][j]>(TabPom[i-1][j-awag]+aval))
					{
						TabPom[i][j] = TabPom[i-1][j];
					}
					else
					{
						if (j>suma_wag) TabPom[i][j] = suma_wartosci;
						else TabPom[i][j] = (TabPom[i-1][j-awag]+aval);
					}
				}
			}
		}
	}
	value =TabPom[N][B];
	int n = N;
	int b = B;
	for(int i = 0; i<=N;i++) 
	{
		print_tab(TabPom[i], B+1);
		cout<<endl;
	}
	while (n > 0 && b>0)
	{
		while (TabPom[n][b] == TabPom[n][b-1])
		{
			b--;
		}
		while (TabPom[n][b] == TabPom[n-1][b])
		{
			n--;
		}
		lista.dodaj(n);
		b -= tab[n-1].size;
		n--;
	}
	stop = clock()-start;
	vD=value;
	PlikOut<<"Dynamiczny	"<<NumAlg<<"	"<<B<<"	"<<N<<"	"<<stop<<"	"<<vD<<"	";	//Zapis d³ugoœci instancji i œredniego czasu jej sortowania
		while (!lista.pusty())
			{
				a = lista.pobierz();
				PlikOut<<a<<"	";
			}
		PlikOut<<std::endl;
	void close(void);
	for (int i = 0 ; i >= N; i++) delete[] TabPom[i];
	delete[] TabPom;
	return stop;
}

time_t zachlanny (kontener tab[],int & vZ, int vD, int N, int B,int NumAlg, std::string p2)
{
	int a;
	std::fstream PlikOut;
	PlikOut.open(p2.c_str(), std::ios::app);
	time_t czas, start = clock();
	qsi(tab, N);
	int i = 0;
	int value = 0;
	int b = 0;
	stos lista;
	while (i<N && b < B )
	{
		if (tab[i].size <= (B-b))
		{
			lista.dodaj(tab[i].lp);
			b = b + tab[i].size;
			value = value + tab[i].value;
		}
		i++;
	}
	czas = clock() - start;
	vZ=value;
	PlikOut<<"Zach³anny	"<<NumAlg<<"	"<<B<<"	"<<N<<"	"<<czas<<"	"<<vZ<<"	";	//Zapis d³ugoœci instancji i œredniego czasu jej sortowania
	double jakosc = (vZ*100)/vD;
	PlikOut<<"jakoœæ: "<<jakosc<<"	";
	while (!lista.pusty())
	{
		a = lista.pobierz();
		PlikOut<<a<<"	";
	}
	PlikOut<<std::endl;
	void close(void);
	return czas;
}

void stos::Resize()  
// zmienia maksymalny rozmiar stosu
{
	MaxSize *= 10;
	int *Temp = new int[MaxSize]; 	
	for( unsigned int i = 0; i < Size; ++i ) Temp[i] = S[i];
		S = Temp;
	//delete[] Temp;
}
 
void stos::dodaj( int a ) 
// dodaje do stosu
{
	if( Size == MaxSize ) Resize();
	S[Size] = a;
	++Size;
}
 
int stos::pobierz()  
// pobiera ze stosu
{
	 --Size;
	 return S[Size];
}

void stos::print()
{
	for(int x=0; x<Size; x++) std::cout<<x<<"	"<<S[x]<<std::endl;
}

bool stos::pusty()    
// Sprawdza czy stos zawiera jakieœ elementy
{
	if(Size == 0 ) return true;
	else return false;
}

stos::stos()     
	// generator stosu
{
	MaxSize = 1;
	Size = 0;
	Resize();
}
