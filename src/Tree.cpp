/*
 * Arvore.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#include <cstddef>

#include "Tree.h"

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

void Tree::SearchIdentificador(LObject *pLObject, Nodo **pNodo) {
	if (*pNodo == NULL){
		cout << "Erro: Registro não está presente na Árvore/n";
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
	else (*pNodo)->setLob(*pLObject);
}

void Tree::InsertsNodo(LObject pLObject, Nodo **pNodo) {
	if (&(*pNodo) == NULL){
		*pNodo = (Nodo*)malloc(sizeof(Nodo));
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
	else cout << "Erro: Objeto já existe na Árvore\n";
}
