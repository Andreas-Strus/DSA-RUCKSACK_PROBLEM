//Plik: sort.hpp
#ifndef sort_hpp
#define sort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <math.h>
#include <cstdlib>




struct kontener
{
	short size;
	int value;
	double density;
	int lp;
	
};
class stos
{
	private: int *S;
	private: unsigned int Size, MaxSize;
	private:
		void Resize();
	public:
		void dodaj(int a);
		int pobierz();
		void print();
		bool pusty();
		stos();
};
int part (kontener tab[], int first, int last, int p=3);
time_t qsi (kontener tab[], int lengh, int piv = 3);
void print_tab (int tab[], int lengh);
void zamien (kontener tab[], int a, int b);
time_t dynamiczny (kontener tab[], int & vD, int N, int B,int NumAlg, std::string p2);
time_t zachlanny (kontener tab[],int & vZ, int vD, int N, int B,int NumAlg, std::string p2);





#endif
