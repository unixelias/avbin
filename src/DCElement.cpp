/*
 * DCElement.cpp
 *
 *  Created on: 29 de nov de 2016
 *      Author: elias
 */

#include <string>
#include <string.h>
#include <iostream>
#include <time.h>
#include "DCElement.h"


DCElement::DCElement() {
	// TODO Auto-generated constructor stub

}
DCElement::DCElement(long identifier, std::string title, std::string type, std::string creator, std::string subject){
	this->identifier = identifier;
	this->title = title;
	this->type = type;
	this->creator = creator;
	this->subject = subject;
}

const std::string& DCElement::getContributor() const {
	return contributor;
}

void DCElement::setContributor(const std::string& contributor) {
	this->contributor = contributor;
}

const std::string& DCElement::getCoverage() const {
	return coverage;
}

void DCElement::setCoverage(const std::string& coverage) {
	this->coverage = coverage;
}

const std::string& DCElement::getCreator() const {
	return creator;
}

void DCElement::setCreator(const std::string& creator) {
	this->creator = creator;
}

time_t DCElement::getDate() const {
	return date;
}

void DCElement::setDate(time_t date) {
	this->date = date;
}

const std::string& DCElement::getDescription() const {
	return description;
}

void DCElement::setDescription(const std::string& description) {
	this->description = description;
}

const std::string& DCElement::getFormat() const {
	return format;
}

void DCElement::setFormat(const std::string& format) {
	this->format = format;
}

const long& DCElement::getIdentifier() const {
	return identifier;
}

void DCElement::setIdentifier(const long& identifier) {
	this->identifier = identifier;
}

const std::string& DCElement::getLanguage() const {
	return language;
}

void DCElement::setLanguage(const std::string& language) {
	this->language = language;
}

const std::string& DCElement::getPublisher() const {
	return publisher;
}

void DCElement::setPublisher(const std::string& publisher) {
	this->publisher = publisher;
}

const std::string& DCElement::getRelation() const {
	return relation;
}

void DCElement::setRelation(const std::string& relation) {
	this->relation = relation;
}

const std::string& DCElement::getRights() const {
	return rights;
}

void DCElement::setRights(const std::string& rights) {
	this->rights = rights;
}

const std::string& DCElement::getSource() const {
	return source;
}

void DCElement::setSource(const std::string& source) {
	this->source = source;
}

const std::string& DCElement::getSubject() const {
	return subject;
}

void DCElement::setSubject(const std::string& subject) {
	this->subject = subject;
}

const std::string& DCElement::getTitle() const {
	return title;
}

void DCElement::setTitle(const std::string& title) {
	this->title = title;
}

const std::string& DCElement::getType() const {
	return type;
}

void DCElement::setType(const std::string& type) {
	this->type = type;
}

DCElement::~DCElement() {
	// TODO Auto-generated destructor stub
}

std::string DCElement::printDateTime() {
	char tempDateString[100];
	strftime( tempDateString, sizeof(tempDateString), "%d.%m.%Y - %H:%M:%S", localtime( &date ) );
	return tempDateString;
}

void DCElement::createElement() {
		std::cout << "Entre com os dados do Objeto de Aprendizagem" << std::endl;
		std::cout << "Identificador: ";
		std::cin >> this->identifier;
		std::cout << "Título: ";
		std::cin >> this->title;
		std::cout << "Tipo de OA: ";
		std::cin >> this->type;
		std::cout << "Criador: ";
		std::cin >> this->creator;
		std::cout << "Assunto: ";
		std::cin >> this->subject;
}

void DCElement::createTestElement() {
	// Seta a codificação
	setlocale(LC_ALL,"Portuguese"); //Para uso de caracteres em utf-8
	//Gera um índice aleatório
	long index;
	srand(time(NULL));
	index = 1+rand()%(101-1);
	//Preenche as informações
	this->identifier = index;
	this->title = "Um título Qualquer";
	this->type = "Um tipo qualquer";
	this->creator = "Fulano de tal";
	this->subject = "Assuntamento de qq coisa";
	std::cout << "Dados " << index << " virtuais inseridos, continuando..." << std::endl;
	DCElement::printElement();
}

void DCElement::printElement() {
	std::cout << "************************************************" << std::endl;
	std::cout << "Identificador: " << this->identifier << std::endl;
	std::cout << "Título: " << this->title << std::endl;
	std::cout << "Tipo de OA: " << this->type << std::endl;
	std::cout << "Criador: " << this->creator << std::endl;
	std::cout << "Assunto: " << this->subject << std::endl;
	std::cout << "************************************************" << std::endl;
}

