/*
 * ObjetoAp.h
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: Objeto de Aprendizagem
 */

#ifndef OBJETOAP_H_
#define OBJETOAP_H_
#include <iostream>
#include <string>
using namespace std;

class ObjetoAp {
	long identifier;
	char title;
	string type;
	char creator;
	char subject;

public:
	ObjetoAp();
	virtual ~ObjetoAp();
	char getCreator();
	void setCreator(char creator);
	long getIdentifier();
	void setIdentifier(long identifier);
	char getSubject();
	void setSubject(char subject);
	char getTitle();
	void setTitle(char title);
	string& getType();
	void setType(string& type);
};

#endif /* OBJETOAP_H_ */
