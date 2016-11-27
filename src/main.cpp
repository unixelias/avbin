
//============================================================================
// Name        : main.cpp
// Author      : Elias Alves
// Version     : 0.0.1
// Copyright   : Apache License Version 2.0
// Description : Sistema de Organização de Objetos de Aprendizagem
//============================================================================

#include <iostream>
//#include <stdio.h>
//#include <string.h>
#include <cstddef>
#include "LObject.h"
#include "Nodo.h"
#include "Tree.h"

typedef struct Nodo * PointerNodo;
using namespace std;


int Menu();

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"Portuguese"); //Para uso de caracteres em utf-8

	// inicializar a árvore

	Tree *pTree;
	pTree = new Tree();//Arvore de registros
	LObject *pNewLObject;
	Nodo *pNodo;
	pNodo = new Nodo();
	pTree->setRoot(pNodo);
	PointerNodo *pNewNodo;
	pNewNodo = new PointerNodo();


	int menu = Menu();

	while (menu != 0){

		switch (menu) {
			case 1:
				cout << "Inserir Registro" << endl;
				pNewLObject = new LObject(); //Para guardar os dados que serão inseridos
				pNewLObject->testCreateLObject();
				*pNewNodo = pTree->getRoot();
				pTree->InsertsNodo(*pNewLObject, &(*pNewNodo));
/*				cout << pNewLObject << " / " << pNewLObject->getIdentifier() << " / " << &pNewLObject << endl;
				cout << pTree->getRoot() << endl;
				cout << pTree->getRoot();
				cout << pNewNodo << " / " << *pNewNodo <<  " / " << &pNewNodo << " / " << &(*pNewNodo) << endl;*/
				break;
			case 2:
				cout << "Apagar Registro" << endl;
				break;
			case 3:
				cout << "Imprimir Registros" << endl;
				break;
			case 4:
				cout << "Busca por Nome" << endl;
				break;
			case 5:
				long identifier;
				cout << "Busca por Chave" << endl;
				cout << "Entre com indice desejado: ";
				cin >> identifier;
				pNewLObject = new LObject(); //Para guardar os dados que serão inseridos
				*pNewNodo = pTree->getRoot();
				pNewLObject->setIdentifier(identifier);
				pTree->SearchIdentificador(pNewLObject, &(*pNewNodo));
				pNewLObject->imprimeObjeto();
				break;
			case 6:
				cout << "Sair";
				break;
			default:
				cout << "Tente novamente com uma opção válida"  << endl;
				return 0;
		}
		menu = Menu();
	};


	return 0;
};

int Menu(){
	int menu;
	cout << "******************  Menu de ações  *************" << endl;
	cout << "* 1 - Inserir Registro   | 4 - Busca por Nome  *" << endl;
	cout << "* 2 - Apagar Registro    | 5 - Busca por Chave *" << endl;
	cout << "* 3 - Imprimir Registros | 0 - Sair            *" << endl;
	cout << "* Escolha uma opção: ";
	cin>>menu;
	return menu;
};

