/*
 * ObjetoAp.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: Objeto de Aprendizagem
 */

#include <iostream>
#include <string>
#include <string.h>

#include "LObject.h"

LObject::LObject() {
	// Objeto vazio
}

LObject::LObject(long identifier, char title[256], string type, char creator[256], char subject[256]) {
	this->identifier = identifier;
	this->title[256] = title[256];
	this->type = type;
	this->creator[256] = creator[256];
	this->subject[256] = subject[256];
}

void LObject::createLObject() {
	cout << "Entre com os dados do Objeto de Aprendizagem" << endl;
	cout << "Identificador: ";
	cin >> identifier;
	this->identifier = identifier;
	cin.ignore();

	cout << "Título: ";
	cin.get(title, 256);
	this->title[256] = title[256];
	cin.ignore();

	cout << "Tipo de OA: ";
	cin >> type;
	this->type = type;
	cin.ignore();

	cout << "Criador: ";
	cin.get(creator, 256);
	this->creator[256] = creator[256];
	cin.ignore();

	cout << "Assunto: ";
	cin.get(subject, 256);
	this->subject[256] = subject[256];
	cin.ignore();

}

char LObject::getCreator(){
	return creator[256];
}

void LObject::setCreator(char creator[256]) {
	this->creator[256] = creator[256];
}

long LObject::getIdentifier(){
	return identifier;
}

void LObject::setIdentifier(long identifier) {
	this->identifier = identifier;
}

char LObject::getSubject(){
	return subject[256];
}

void LObject::setSubject(char subject[256]) {
	this->subject[256] = subject[256];
}

char LObject::getTitle(){
	return title[256];
}

void LObject::setTitle(char title[256]) {
	this->title[256] = title[256];
}

string& LObject::getType(){
	return type;
}

void LObject::setType(string& type) {
	this->type = type;
}

LObject::~LObject() {
	// TODO Auto-generated destructor stub
}

void LObject::imprimeObjeto() {
	cout << "************************************************" << endl;
	cout << "Identificador: " << this->identifier << endl;
	cout << "Título: " << this->title << endl;
	cout << "Tipo de OA: " << this->type << endl;
	cout << "Criador: " << this->creator << endl;
	cout << "Assunto: " << this->subject << endl;
	cout << "************************************************" << endl;
}

void LObject::testCreateLObject() {
	long index;
	srand(time(NULL));
	index = rand() % 10;
	this->identifier = index;
	strcpy(this->title, "Um título Qualquer");
	string type = ("qualquer");
	LObject::setType(type);
	strcpy(this->creator, "Fulano de tal");
	strcpy(this->subject, "Assuntamento de qq coisa");
	cout << "Dados virtuais inseridos, continuando..." << endl;
	LObject::imprimeObjeto();
}
