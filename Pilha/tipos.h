#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct TElemento
{
	T dado;
	TElemento<T> * proximo;
};

template <typename T>
struct TPilha
{
	TElemento<T> * topo;
	int qtd;
	
	void inicializa(){
		if (qtd < 1)
		{
			qtd = 0;
		}
	}
};

struct Pessoa
{
	string nome;
	int idade;
};

#endif // !TIPOS_H_INCLUDED
