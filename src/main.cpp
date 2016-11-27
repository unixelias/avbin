
//============================================================================
// Name        : main.cpp
// Author      : Elias Alves
// Version     : 0.0.1
// Copyright   : Apache License Version 2.0
// Description : Sistema de Organização de Objetos de Aprendizagem
//============================================================================

#include <iostream>
#include <fstream>
//#include <stdio.h>
//#include <string.h>
#include <cstddef>
#include "LObject.h"
#include "Nodo.h"
#include "Tree.h"

typedef struct Nodo * PointerNodo;
using namespace std;


int Menu();
void openFile(Tree *pTree);

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
	fstream out("docs/Teste.txt");
	if( !out.is_open() ) {
		cout << "O arquivo não pode ser aberto!";
	}

	int menu = Menu();

	while (menu != 0){
		// abre um arquivo para escrita de nome Teste.txt

		switch (menu) {
			case 1:
				cout << "Inserir Registro" << endl;
				pNewLObject = new LObject(); //Para guardar os dados que serão inseridos
				pNewLObject->testCreateLObject();
				*pNewNodo = pTree->getRoot();
				pTree->InsertsNodo(*pNewLObject, &(*pNewNodo));

				char title;
				title = pNewLObject->getTitle();
				//string type;
				//type = pNewLObject->getType();
				char creator;
				creator = pNewLObject->getCreator();
				char subject;
				subject = pNewLObject->getSubject();
				out.getline(&title, 256);
				out << pNewLObject->getIdentifier() << " " << title << " " << pNewLObject->getType() << " " << creator << " " << subject << endl;


				/*
				out << << endl;
				out << "Este é um pequeno arquivo-texto";
				cout << pNewLObject << " / " << pNewLObject->getIdentifier() << " / " << &pNewLObject << endl;
				cout << pTree->getRoot() << endl;
				cout << pTree->getRoot();
				cout << pNewNodo << " / " << *pNewNodo <<  " / " << &pNewNodo << " / " << &(*pNewNodo) << endl;*/
				break;
			case 2:
				cout << "Apagar Registro" << endl;
				break;
			case 3:
				cout << "Imprimir Registros" << endl;
				pTree->ioTraversal(pTree->getRoot());
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
	out.close();

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

void FileioTraversal(Nodo* pNodo) {
	if (pNodo == NULL) return;
	FileioTraversal(pNodo->getLeft());
	pNodo->getLob().imprimeObjeto();
	FileioTraversal(pNodo->getRight());
	pNodo->getLob().imprimeObjeto();
}


