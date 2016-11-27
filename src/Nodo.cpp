/*
 * Nodo.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: nó binário com estruturas
 */

#include <cstddef>
#include "Nodo.h"


Nodo::Nodo(){
//	LObject *gambLob = new LObject();
//	this->lob = *gambLob;
//	this->bal_factor = 0;//Necessário no TP1?
//	this->pLtef = NULL;
//	this->pRight = NULL;
}

Nodo::Nodo(LObject newLob) {
	this->lob = newLob;
	this->bal_factor = 0;//Necessário no TP1?
	this->pLtef = NULL;
	this->pRight = NULL;
}

int Nodo::getBalFactor(){
	return bal_factor;
}

void Nodo::setBalFactor(int bal_factor) {
	this->bal_factor = bal_factor;
}

LObject& Nodo::getLob(){
	return lob;
}

void Nodo::setLob(LObject& lob) {
	this->lob = lob;
}

Nodo*& Nodo::getRight(){
	return pRight;
}

void Nodo::setRight(Nodo*& pRight) {
	this->pRight = pRight;
}

Nodo*& Nodo::getLeft(){
	return pLtef;
}

void Nodo::setLeft(Nodo*& pLtef) {
	this->pLtef = pLtef;
}

void Nodo::setLeftNull() {
	this->pLtef = NULL;
}

void Nodo::setRightNull() {
	this->pRight = NULL;
}

Nodo::~Nodo() {
	free(this->pLtef);
	free(this->pRight);

	// TODO Auto-generated destructor stub
}
