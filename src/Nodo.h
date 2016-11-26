/*
 * Nodo.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: nó binário com estruturas
 */

#ifndef NODO_H_
#define NODO_H_
#include "ObjetoAp.h"

class Nodo {
	ObjetoAp OA;
	int fator_bal;//Necessário no TP1?
	Nodo *pEsq;
	Nodo *pDir;
public:
	Nodo(ObjetoAp oa);
	virtual ~Nodo();
	int getFatorBal();
	void setFatorBal(int fatorBal);
	ObjetoAp& getOa();
	void setOa(ObjetoAp& oa);
	Nodo*& getDir();
	void setDir(Nodo*& dir);
	Nodo*& getEsq();
	void setEsq(Nodo*& esq);
};

#endif /* NODO_H_ */
