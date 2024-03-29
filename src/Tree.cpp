/*
 * Tree.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#include <cstddef>
#include <iostream>
#include <string>
#include <new>
#include "DCElement.h"
#include "Tree.h"

typedef struct Nodo * PointerNodo;
//using pNodo = Nodo *;

Tree::Tree() {
	pRoot = new Tree::Nodo();
	pRoot = NULL;
	pNewNodo = &pRoot;
};

Tree::Nodo::Nodo(){

};

Tree::Nodo::Nodo(DCElement newLob) {
	this->lob = newLob;
	this->pLtef = NULL;
	this->pRight = NULL;
};


Tree::Nodo* Tree::getRoot(){
	return pRoot;
};
Tree::Nodo** Tree::getNewNodo(){
	//(*pNewNodo) = new Tree::Nodo();
	pNewNodo = &pRoot;
	return pNewNodo;
};

void Tree::setRoot(Tree::Nodo* nodo){
	pRoot = nodo;
};

bool Tree::SearchIdentificator(DCElement *pLObject, Tree::Nodo **pNodo) {
	if ((*pNodo) == NULL){
		std::cout << "Erro: Registro não está presente na Árvore" << std::endl;
		return false;
	}else if (pLObject->getIdentifier() < (*pNodo)->getLob().getIdentifier()){
		Tree::SearchIdentificator(pLObject, &(*pNodo)->getLeft());
	}else if (pLObject->getIdentifier() > (*pNodo)->getLob().getIdentifier()){
		Tree::SearchIdentificator(pLObject, &(*pNodo)->getRight());
	}else {
		(*pLObject) = (*pNodo)->getLob();
		return true;
	}
};

bool Tree::SearchName(std::string nome, Tree::Nodo* pNodo) {
	if (pNodo == NULL) return false;
	Tree::ioTraversal(pNodo->getLeft());
	if (pNodo->getLob().getCreator() == nome){
		pNodo->getLob().printElement();
		return true;
	}
	Tree::ioTraversal(pNodo->getRight());
};

void Tree::InsertsNodo(DCElement pLObject, Tree::Nodo **pNewNodo) {
	if ((*pNewNodo) == NULL){
		(*pNewNodo) = new Tree::Nodo();
		(*pNewNodo)->setLob(pLObject);
		(*pNewNodo)->setRightNull();
		(*pNewNodo)->setLeftNull();
	}else if (pLObject.getIdentifier() < (*pNewNodo)->getLob().getIdentifier()){
		Tree::InsertsNodo(pLObject, &(*pNewNodo)->getLeft());
	}else if (pLObject.getIdentifier() > (*pNewNodo)->getLob().getIdentifier()){
		Tree::InsertsNodo(pLObject, &(*pNewNodo)->getRight());
	}else{
		std::cout << "Erro: Objeto já existe na Árvore" << std::endl;
	}

};

Tree::Nodo** Tree::Predecessor (Tree::Nodo *pNodoQ, Tree::Nodo **pNodoR){
	if ((*pNodoR)->getRight() != NULL){
		(*pNodoR)->setRight((*Tree::Predecessor(pNodoQ, &(*pNodoR)->getRight())));
	}else {
		pNodoQ = (*pNodoR);
		(*pNodoR) = (*pNodoR)->getRight();
	}
	return pNodoR;

};

void Tree::RemovesNodo(long identifier,  Tree::Nodo **pNewNodo){
	if ((*pNewNodo) == NULL){
		std::cout << "Erro: Registro não está presente na Árvore" << std::endl;
	}else if (identifier < (*pNewNodo)->getLob().getIdentifier()){
		Tree::RemovesNodo(identifier, &(*pNewNodo)->getLeft());
	}else if (identifier > (*pNewNodo)->getLob().getIdentifier()){
		Tree::RemovesNodo(identifier, &(*pNewNodo)->getRight());
	}else{
		if ((*pNewNodo)->getRight() == NULL){
			(*pNewNodo) = (*pNewNodo)->getLeft();

		}else if ((*pNewNodo)->getLeft() == NULL){
			(*pNewNodo) = (*pNewNodo)->getRight();

		}else {
			(*pNewNodo)->setLeft((*Tree::Predecessor((*pNewNodo), &(*pNewNodo)->getRight())));
		}
		std::cout << "Item removido com sucesso" << std::endl;
	}

};

void Tree::ioTraversal(Tree::Nodo* pNodo) {
	if (pNodo == NULL) return;
	Tree::ioTraversal(pNodo->getLeft());
	pNodo->getLob().printElement();
	Tree::ioTraversal(pNodo->getRight());
};


DCElement& Tree::Nodo::getLob(){
	return lob;
}

void Tree::Nodo::setLob(DCElement& lob) {
	this->lob = lob;
};

Tree::Nodo*& Tree::Nodo::getRight(){
	return pRight;
};

void Tree::Nodo::setRight(Nodo*& pRight) {
	this->pRight = pRight;
};

Tree::Nodo*& Tree::Nodo::getLeft(){
	return pLtef;
};

void Tree::Nodo::setLeft(Nodo*& pLtef) {
	this->pLtef = pLtef;
};

void Tree::Nodo::setLeftNull() {
	this->pLtef = NULL;
};

void Tree::Nodo::setRightNull() {
	this->pRight = NULL;
}


Tree::~Tree() {
	delete[] pRoot;
};

Tree::Nodo::Nodo::~Nodo() {
	free(this->pLtef);
	free(this->pRight);

	// TODO Auto-generated destructor stub
}
