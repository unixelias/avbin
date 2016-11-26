/*
 * Arvore.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#include <stddef.h>
#include "Arvore.h"

Arvore::Arvore() {
	pRaiz = NULL;
}

Arvore::~Arvore() {
	delete[] pRaiz;
}

Nodo *Arvore::getRaiz(){
	return pRaiz;
};

void Arvore::setRaiz(Nodo* nodo){
	pRaiz = nodo;
};
