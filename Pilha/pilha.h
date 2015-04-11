#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <iostream>

#include "tipos.h"

template <typename T>
bool push(TElemento<T> * elemento, TPilha<T> * pilha){
	pilha->inicializa();

	if (pilha == 0)
	{
		pilha->topo = NULL;
	}

	elemento->proximo = pilha->topo;
	pilha->topo = elemento;
	pilha->qtd++;

	return true;
}

template <typename T>
TElemento<T> * pop(TPilha<T> * pilha) {
	if (pilha->qtd < 1)
	{
		return NULL;
	}

	TElemento<T> * elemento = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	pilha->qtd--;

	return elemento;
}
	
#endif // !FILA_H_INCLUDED
