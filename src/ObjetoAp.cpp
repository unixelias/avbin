/*
 * ObjetoAp.cpp
 *
 *  Created on: 24 de nov de 2016
 *      Author: elias
 *      Tipo de objeto: Objeto de Aprendizagem
 */

#include "ObjetoAp.h"

ObjetoAp::ObjetoAp() {
	// TODO Auto-generated constructor stub
}

char ObjetoAp::getCreator(){
	return creator;
}

void ObjetoAp::setCreator(char creator) {
	this->creator = creator;
}

long ObjetoAp::getIdentifier(){
	return identifier;
}

void ObjetoAp::setIdentifier(long identifier) {
	this->identifier = identifier;
}

char ObjetoAp::getSubject(){
	return subject;
}

void ObjetoAp::setSubject(char subject) {
	this->subject = subject;
}

char ObjetoAp::getTitle(){
	return title;
}

void ObjetoAp::setTitle(char title) {
	this->title = title;
}

string& ObjetoAp::getType(){
	return type;
}

void ObjetoAp::setType(string& type) {
	this->type = type;
}

ObjetoAp::~ObjetoAp() {
	// TODO Auto-generated destructor stub
}

