
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
#include "Nodo.h"
#include "Tree.h"



typedef struct Nodo * PointerNodo;
using namespace std;


int Menu();
//void openFile(Tree *pTree);

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"Portuguese"); //Para uso de caracteres em utf-8


    time_t agora;
    char datahora[100];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    agora = time(NULL);

    /* Formata a data e a hora da forma desejada */
    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );

    printf( "Data/Hora: %s\n", datahora );

    DCElement *DCElemento;
    DCElemento = new DCElement();

    DCElemento->setContributor(datahora);
    DCElemento->setDate(agora);

    cout << DCElemento->getContributor() << endl;
    cout << DCElemento->getDate() << endl;
    cout << DCElemento->printDateTime() << endl;



	// inicializar a árvore

	Tree *pTree;
	pTree = new Tree();//Arvore de registros
	DCElement *pDCElement;
	Nodo *pNodo;
	pNodo = new Nodo();
	pTree->setRoot(pNodo);
	PointerNodo *pNewNodo;


	ofstream out("Teste.txt");
	if (pNewNodo == NULL) cout << &pNewNodo;

	int menu = Menu();

	while (menu != 0){
		// abre um arquivo para escrita de nome Teste.txt

		switch (menu) {
			case 1:{
				cout << "Inserir Registro" << endl;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				pDCElement->createTestElement();

				// inserir o nó na árvore com um objeto complementar dce
				// em seguida inserir o DCE dentro do nó
				pNewNodo = new PointerNodo();
				(*pNewNodo) = pTree->getRoot();
				pTree->InsertsNodo(*pDCElement, &(*pNewNodo));

				break;
			}
			case 2:{
				cout << "Apagar Registro" << endl;
				break;
			}
			case 3:{
				cout << "Imprimir Registros" << endl;
				pTree->ioTraversal(pTree->getRoot());
				break;
			}
			case 4:{
				cout << "Busca por Nome" << endl;
				break;
			}
			case 5:{
				long identifier;
				cout << "Busca por Chave" << endl;
				cout << "Entre com indice desejado: ";
				cin >> identifier;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				pNewNodo = new PointerNodo();
				*pNewNodo = pTree->getRoot();
				pDCElement->setIdentifier(identifier);
				pTree->SearchIdentificador(pDCElement, &(*pNewNodo));
				pDCElement->printElement();
				break;
			}
			case 6:{
				cout << "Sair";
				break;
			}
			default:{
				cout << "Tente novamente com uma opção válida"  << endl;
				return Menu();
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

void FileioTraversal(Nodo* pNodo) {
	if (pNodo == NULL) return;
	FileioTraversal(pNodo->getLeft());
	pNodo->getLob().printElement();
	FileioTraversal(pNodo->getRight());
	pNodo->getLob().printElement();
}


