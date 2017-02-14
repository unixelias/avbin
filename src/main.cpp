
//============================================================================
// Name        : main.cpp
// Author      : Elias Alves
// Version     : 0.0.1
// Copyright   : Apache License Version 2.0
// Description : Sistema de Organização de Objetos de Aprendizagem
//============================================================================

#include <new>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/parser.h>
#include "DCElement.h"
#include "Tree.h"


using namespace std;


int Menu();


int main(int argc, char *argv[]){

	// inicializar a árvore

	Tree *pTree;
	pTree = new Tree();//Arvore de registros
	DCElement *pDCElement;
	string nome = "";
	long identifier;
	bool testes;

	/*fstream fio("Teste.txt"); // Abre arquivo para gravação
	 //em modo texto
	 char ch;
	 cout << "Digite um texto ";
	 cout << "\nPressione CTRL_Z para encerrar ";
	 cin.get(ch); // Lê um caracter do teclado
	 fio.put(ch); // Grava o caracter no arquivo
	 fio.close();*/

	cout << "Digite 0 se você deseja criar regitros de teste" << endl;
	cout << "Digite 1 se você deseja criar registros reais" << endl;
	cin >> testes;

	int menu = Menu();

	while (menu != 0){
		// abre um arquivo para escrita de nome Teste.txt

		switch (menu) {
			case 1:{
				cout << "Inserir Registro" << endl;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				if (testes){
					pDCElement->createElement();
				}else{
					pDCElement->createTestElement();
				}
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
				pTree->SearchName(nome, pTree->getRoot());
				break;
			}
			case 5:{
				cout << "Busca por Chave" << endl;
				cout << "Entre com indice desejado: ";
				cin >> identifier;
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



