/*
 * Arvore.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#ifndef ARVORE_H_
#define ARVORE_H_
#include "Nodo.h"

class Arvore {
	Nodo *pRaiz;
public:
	Arvore();
	virtual ~Arvore();
	Nodo *getRaiz();
	void setRaiz(Nodo*);
};

#endif /* ARVORE_H_ */
