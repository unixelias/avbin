/*
 * ObjetoAp.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: Objeto de Aprendizagem
 */

#ifndef LOBJECT_H_
#define LOBJECT_H_
#include <iostream>
#include <string>
using namespace std;

class LObject {
	long identifier;
	char title[256];
	string type;
	char creator[256];
	char subject[256];

public:
	LObject();
	LObject(long identifier, char title[256], string type, char creator[256], char subject[256]);
	virtual ~LObject();
	void createLObject();
	char getCreator();
	void setCreator(char creator[256]);
	long getIdentifier();
	void setIdentifier(long identifier);
	char getSubject();
	void setSubject(char subject[256]);
	char getTitle();
	void setTitle(char title[256]);
	string& getType();
	void setType(string& type);
	void imprimeObjeto();
};

#endif /* LOBJECT_H_ */
