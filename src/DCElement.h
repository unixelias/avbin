/*
 * DCElement.h
 *
 *  Created on: 29 de nov de 2016
 *      Author: elias
 */

#ifndef DCELEMENT_H_
#define DCELEMENT_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>


class DCElement {
	long identifier;
	std::string title;
	std::string creator;
	std::string subject;
	std::string description;
	std::string publisher;
	std::string contributor;
	time_t date;
	std::string type;
	std::string format;
	std::string source;
	std::string language;
	std::string relation;
	std::string coverage;
	std::string rights;
	/*Aqui entram demais metadados com os possíveis pesos ou demais tags de identificação*/
public:
	DCElement();
	DCElement(long identifier, std::string title, std::string type, std::string creator, std::string subject);
	virtual ~DCElement();

	void teste() {
		date = time(NULL);
	}

	const std::string& getContributor() const;
	void setContributor(const std::string& contributor);
	const std::string& getCoverage() const;
	void setCoverage(const std::string& coverage);
	const std::string& getCreator() const;
	void setCreator(const std::string& creator);
	time_t getDate() const;
	void setDate(time_t date);
	const std::string& getDescription() const;
	void setDescription(const std::string& description);
	const std::string& getFormat() const;
	void setFormat(const std::string& format);
	const long& getIdentifier() const;
	void setIdentifier(const long& identifier);
	const std::string& getLanguage() const;
	void setLanguage(const std::string& language);
	const std::string& getPublisher() const;
	void setPublisher(const std::string& publisher);
	const std::string& getRelation() const;
	void setRelation(const std::string& relation);
	const std::string& getRights() const;
	void setRights(const std::string& rights);
	const std::string& getSource() const;
	void setSource(const std::string& source);
	const std::string& getSubject() const;
	void setSubject(const std::string& subject);
	const std::string& getTitle() const;
	void setTitle(const std::string& title);
	const std::string& getType() const;
	void setType(const std::string& type);
	std::string printDateTime();
	void createTestElement();
	void createElement();
	void printElement();
};


#endif /* DCELEMENT_H_ */
