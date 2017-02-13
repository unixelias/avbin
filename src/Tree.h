/*
 * Arvore.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 */

#ifndef TREE_H_
#define TREE_H_
#include <string>
#include "DCElement.h"

typedef struct Nodo * PointerNodo;

class Tree {
public:
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
private:
	Tree::Nodo *pRoot;
	Tree::Nodo **pNewNodo;
public:
	Tree();
	virtual ~Tree();
	Tree::Nodo* getRoot();
	Tree::Nodo** getNewNodo();
	void setRoot(Tree::Nodo*);
	bool SearchIdentificator(DCElement *pLObject, Tree::Nodo **pNodo);
	bool SearchName(std::string nome, Tree::Nodo* pNodo);
	void InsertsNodo(DCElement pLObject,  Tree::Nodo **pNodo);
	void ioTraversal(Tree::Nodo *pNodo);
};

#endif /* TREE_H_ */
