/*
 * Nodo.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: nó binário com estruturas
 */

#ifndef NODO_H_
#define NODO_H_
#include "DCElement.h"

#define DCELEMENT_H_

class Nodo {
	DCElement lob;
	int bal_factor;//Necessário no TP1?
	Nodo *pLtef;
	Nodo *pRight;
public:
	Nodo();
	Nodo(DCElement newLob);
	virtual ~Nodo();
	int getBalFactor();
	void setBalFactor(int bal_factor);
	DCElement& getLob();
	void setLob(DCElement& lob);
	Nodo*& getRight();
	void setRight(Nodo*& pRight);
	Nodo*& getLeft();
	void setLeft(Nodo*& pLtef);
	void setLeftNull();
	void setRightNull();
};

#endif /* NODO_H_ */
