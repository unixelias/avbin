/*
 * Arvore.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

//#include <cstddef>
#include <iostream>
#include <new>
#include "DCElement.h"
#include "Tree.h"
#include "Nodo.h"

//using pNodo = Nodo *;

Tree::Tree() {
	pRoot = nullptr;
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
	if (*pNodo == nullptr){
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
	}
}

void Tree::InsertsNodo(DCElement pLObject, Nodo **pNodo) {
	if ((*pNodo) == nullptr){
		(*pNodo) = (Nodo*)malloc(sizeof(Nodo));
		(*pNodo)->setLob(pLObject);
		(*pNodo)->setRightNull();
		(*pNodo)->setLeftNull();
		return;
	}
	if (pLObject.getIdentifier() < (*pNodo)->getLob().getIdentifier()){
		Tree::InsertsNodo(pLObject, &(*pNodo)->getLeft());
		return;
	}
	if (pLObject.getIdentifier() > (*pNodo)->getLob().getIdentifier())
		Tree::InsertsNodo(pLObject, &(*pNodo)->getRight());
	else std::cout << "Erro: Objeto já existe na Árvore" << std::endl;
}

void Tree::ioTraversal(Nodo* pNodo) {
	if (pNodo == nullptr) return;
	ioTraversal(pNodo->getLeft());
	pNodo->getLob().printElement();
	ioTraversal(pNodo->getRight());
	pNodo->getLob().printElement();
}
