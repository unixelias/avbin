/*
 * Nodo.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: nó binário com estruturas
 */

#include <stddef.h>
#include "Nodo.h"



Nodo::Nodo(ObjetoAp oa) {
	this->OA = oa;
	this->fator_bal = 0;//Necessário no TP1?
	this->pEsq = NULL;
	this->pDir = NULL;
}

int Nodo::getFatorBal(){
	return fator_bal;
}

void Nodo::setFatorBal(int fatorBal) {
	fator_bal = fatorBal;
}

ObjetoAp& Nodo::getOa(){
	return OA;
}

void Nodo::setOa(ObjetoAp& oa) {
	OA = oa;
}

Nodo*& Nodo::getDir(){
	return pDir;
}

void Nodo::setDir(Nodo*& dir) {
	pDir = dir;
}

Nodo*& Nodo::getEsq(){
	return pEsq;
}

void Nodo::setEsq(Nodo*& esq) {
	pEsq = esq;
}

Nodo::~Nodo() {
	free(this->pEsq);
	free(this->pDir);

	// TODO Auto-generated destructor stub
}

