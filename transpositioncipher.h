/*
 * transpositioncipher.h
 *
 *  Created on: 14 sept. 2016
 *      Author: hnnguyen
 */

#ifndef TRANSPOSITIONCIPHER_H_
#define TRANSPOSITIONCIPHER_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define log(s) std::cout << s << std::endl

class transpositioncipher {
private:
	std::map<char,bool> mapOriginAlphabet;
	std::map<char,char> mapAlphabet;
	std::map<char,char> mapReverseAlphabet;
	std::vector<int> vecOrder;
	std::string mKeySecret;

	std::string removeDuplicates(const std::string strOrigin);
	void createOrder();
	void createSubstitution();
	void reverseSubstitution();

public:
	transpositioncipher(std::string KeySecret);
	virtual ~transpositioncipher();

	std::string encrypt(const std::string strOrigin);
	std::string decrypt(const std::string strOrigin);
	void print();
};

#endif /* TRANSPOSITIONCIPHER_H_ */
