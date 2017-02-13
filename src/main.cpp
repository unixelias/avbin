
//============================================================================
// Name        : main.cpp
// Author      : Elias Alves
// Version     : 0.0.1
// Copyright   : Apache License Version 2.0
// Description : Sistema de Organização de Objetos de Aprendizagem
//============================================================================

#include <iostream>
#include <new>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/parser.h>
#include <time.h>
#include "DCElement.h"
#include "Tree.h"


using namespace std;


int Menu();
//void openFile(Tree *pTree);

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"Portuguese"); //Para uso de caracteres em utf-8

	// inicializar a árvore

	Tree *pTree;
	pTree = new Tree();//Arvore de registros
	string nome = "";
	long identifier;

	//ofstream out("Teste.txt");

	int menu = Menu();

	while (menu != 0){
		// abre um arquivo para escrita de nome Teste.txt

		switch (menu) {
			case 1:{
				cout << "Inserir Registro" << endl;
				DCElement *pDCElement;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				pDCElement->createTestElement();
				pTree->InsertsNodo(*pDCElement, pTree->getNewNodo());

				break;
			}
			case 2:{
				cout << "Apagar Registro" << endl;
				cout << "Entre com indice desejado: ";
				cin >> identifier;
				pTree->RemovesNodo(identifier,  pTree->getNewNodo());


				break;
			}
			case 3:{
				cout << "Imprimir Registros" << endl;
				pTree->ioTraversal(pTree->getRoot());
				break;
			}
			case 4:{
				cout << "Busca por Nome" << endl;
				cout << "Digite a chave de busca: ";
				cin >> nome;
				DCElement *pDCElement;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				pTree->SearchName(nome, pTree->getRoot());
				//pDCElement->printElement();
				break;
			}
			case 5:{
				cout << "Busca por Chave" << endl;
				cout << "Entre com indice desejado: ";
				cin >> identifier;
				DCElement *pDCElement;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos

				pDCElement->setIdentifier(identifier);
				if (pTree->SearchIdentificator(pDCElement, pTree->getNewNodo()))
				pDCElement->printElement();
				break;
			}
			case 6:{
				cout << "Sair";
				break;
			}
			default:{
				cout << "Tente novamente com uma opção válida"  << endl;
				break;
			}
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



