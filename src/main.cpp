
//============================================================================
// Name        : main.cpp
// Author      : Elias Alves
// Version     : 0.0.1
// Copyright   : Apache License Version 2.0
// Description : Sistema de Organização de Objetos de Aprendizagem
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "ObjetoAp.h"
#include "Arvore.h"
#include "Nodo.h"
using namespace std;


int Menu();
void PesquisaIdentificador(ObjetoAp *pObjeto, Nodo* pNodo);


int main(void){
	setlocale(LC_ALL,"Portuguese"); //Para uso de caracteres em utf-8
	int menu;
	Arvore *pArvore = new Arvore();//Arvore de registros
	ObjetoAp *pObjeto = new ObjetoAp(); //Para guardar os dados que serão inseridos
	Nodo *pNodo = new Nodo(*pObjeto);

	Menu();

	return 0;
};


int Menu(){
	int menu;
	cout << "1 - Inserir Registro\n";
	cout << "2 - Imprimir Registros\n";
	cout << "3 - Apagar Registro\n";
	cout << "4 - Busca por Chave\n";
	cout << "5 - Busca por Nome\n";
	cout << "0 - Sair\n";
	cout << "Escolha uma opção: ";
	cin>>menu;
	return menu;
};


inline void PesquisaIdentificador(ObjetoAp *pObjeto, Nodo *pNodo) {
	if (pNodo == NULL){
		cout << "Erro: Registro não está presente na Árvore/n";
		return;
	}
	if (pObjeto->getIdentifier() < pNodo->getOa().getIdentifier()){
		PesquisaIdentificador(pObjeto, &*pNodo->getEsq());
		return;
	}
	if (pObjeto->getIdentifier() > pNodo->getOa().getIdentifier()){
		PesquisaIdentificador(pObjeto, &*pNodo->getDir());
		return;
	}
	else pNodo->setOa(*pObjeto);
}
