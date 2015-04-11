#include <iostream>
#include "tipos.h"
#include "pilha.h"

using namespace std;

void adicionaNaPilha(TPilha<char> * pilha, char simbolo){
	TElemento<char> * elemento = new TElemento<char>;
	elemento->dado = simbolo;

	push(elemento, pilha);
}

char inverso(char valor){
	switch (valor)
	{
	case '{':
		return '}';
	case '(':
		return ')';
	case '[':
		return ']';
	}

	return ' ';
}

bool isSimbolo(char caractere){
	if (caractere == '}' || caractere == ')' || caractere == ']')
	{
		return true;
	}
	return false;
}

bool empilhaSimbolos (string expressao, TPilha<char> * pilha){
	for (int i = 0; i < expressao.size(); i++)
	{
		switch (expressao.at(i))
		{
		case '{':
			adicionaNaPilha(pilha, '{');
			break;
		case '(':
			adicionaNaPilha(pilha, '(');
			break;
		case '[':
			adicionaNaPilha(pilha, '[');
			break;
		}
		if ((pilha->qtd > 0) && expressao.at(i) == inverso(pilha->topo->dado))
		{
			TElemento<char> * elemento = pop(pilha);

			cout << elemento->dado;

			delete(elemento);
		}else if(isSimbolo(expressao.at(i))){
			return false;
		}
	}

	return pilha->qtd == 0;
}

int main()
{
	TPilha<char> * pilha = new TPilha<char>;
	char * expressao = "(asd{asd[asd]ads}asdddd))))))";

	;

	if (empilhaSimbolos(expressao, pilha))
	{
		cout << "\n\n\n Expressao correta \n\n";
	}else{
		cout << "\n\n\n Expressao incorreta \n\n";
	}


	system("pause");
}
