
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
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/parser.h>
#include <time.h>
#include "DCElement.h"
#include "Nodo.h"
#include "Tree.h"



typedef struct Nodo * PointerNodo;
using namespace std;


int Menu();
void openFile(Tree *pTree);

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
	pNewNodo = new PointerNodo();
	ofstream out("Teste.txt");


	int menu = Menu();

	while (menu != 0){
		// abre um arquivo para escrita de nome Teste.txt

		switch (menu) {
			case 1:
				cout << "Inserir Registro" << endl;
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				pDCElement->createTestElement();
				*pNewNodo = pTree->getRoot();
				pTree->InsertsNodo(*pDCElement, &(*pNewNodo));
				if( !out.is_open() ) {
					out.open("Teste.txt");
				}
				if( !out.is_open() ) {
						cerr << " copy.out não pode ser aberto para saída\n";
						exit(-1);
					}
					out.write( (char *)&pDCElement, sizeof(DCElement));

//					out.operator <<(identifier);
//					out << " " << this->type << endl;
//					long tamanho = strlen(title);
//					out.write(title, tamanho);
//					out << endl;
//					tamanho = strlen(subject);
//					out.write(subject, tamanho);
//					out << endl;
//					tamanho = strlen(creator);
//					out.write(creator, tamanho);
//					out << endl;
					out.close();



				/*
				out << << endl;
				out << "Este é um pequeno arquivo-texto";
				cout << pDCElement << " / " << pDCElement->getIdentifier() << " / " << &pDCElement << endl;
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
				pDCElement = new DCElement(); //Para guardar os dados que serão inseridos
				*pNewNodo = pTree->getRoot();
				pDCElement->setIdentifier(identifier);
				pTree->SearchIdentificador(pDCElement, &(*pNewNodo));
				pDCElement->printElement();
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

void FileioTraversal(Nodo* pNodo) {
	if (pNodo == NULL) return;
	FileioTraversal(pNodo->getLeft());
	pNodo->getLob().printElement();
	FileioTraversal(pNodo->getRight());
	pNodo->getLob().printElement();
}


