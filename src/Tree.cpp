/*
 * Arvore.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#include <cstddef>
#include <iostream>
#include <new>
#include "DCElement.h"
#include "Tree.h"
#include "Nodo.h"

//using pNodo = Nodo *;

Tree::Tree() {
	pRoot = NULL;
}

Tree::~Tree() {
	delete[] pRoot;
}

Nodo *Tree::getRoot(){
	return pRoot;
};

void Tree::setRoot(Nodo* nodo){
	pRoot = nodo;
}
;

void Tree::SearchIdentificador(DCElement *pLObject, Nodo **pNodo) {
	if (*pNodo == NULL){
		std::cout << "Erro: Registro não está presente na Árvore" << std::endl;
		return;
	}
	if (pLObject->getIdentifier() < (*pNodo)->getLob().getIdentifier()){
		SearchIdentificador(pLObject, &(*pNodo)->getLeft());
		return;
	}
	if (pLObject->getIdentifier() > (*pNodo)->getLob().getIdentifier()){
		SearchIdentificador(pLObject, &(*pNodo)->getRight());
		return;
	}
	else {
		(*pLObject) = (*pNodo)->getLob();
		return;
	}
}

void Tree::InsertsNodo(DCElement pLObject, Nodo **pNodo) {
	if ((*pNodo) == NULL){
		(*pNodo) = new Nodo();
		(*pNodo)->setLob(pLObject);
		(*pNodo)->setRightNull();
		(*pNodo)->setLeftNull();
		return;
	}else if (pLObject.getIdentifier() < (*pNodo)->getLob().getIdentifier()){

		Tree::InsertsNodo(pLObject, &(*pNodo)->getLeft());
		return;
	}else if (pLObject.getIdentifier() > (*pNodo)->getLob().getIdentifier()){
		Tree::InsertsNodo(pLObject, &(*pNodo)->getRight());
		return;
	}else{
		std::cout << "Erro: Objeto já existe na Árvore" << std::endl;
		return;
	}

}

void Tree::ioTraversal(Nodo* pNodo) {
	if (pNodo) std::cout << pNodo->getLob().getIdentifier() << "\n";
	std::cout << pNodo << "\n";
	std::cout << (pNodo) << "\n";
	std::cout << &(pNodo) << "\n";
	std::cout << &pNodo << "\n";
	if (pNodo == NULL) return;
	ioTraversal(pNodo->getLeft());
	ioTraversal(pNodo->getRight());
	pNodo->getLob().printElement();
}
