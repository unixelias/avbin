/*
 * Arvore.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#ifndef TREE_H_
#define TREE_H_
#include "Nodo.h"

class Tree {
	Nodo *pRoot;
public:
	Tree();
	virtual ~Tree();
	Nodo *getRoot();
	void setRoot(Nodo*);
	void SearchIdentificador(LObject *pLObject, Nodo **pNodo);
	void InsertsNodo(LObject pLObject,  Nodo **pNodo);
	void ioTraversal(Nodo *pNodo);
};

#endif /* TREE_H_ */
