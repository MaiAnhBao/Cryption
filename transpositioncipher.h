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
#define NUMBER_ALPHABET 26

class transpositioncipher {
private:
	static constexpr int ALPHABET_SIZE = 26;

	std::map<char,char> mapAlphabet;
	std::map<char,char> mapReverseAlphabet;
	std::string mKeySecret;

	std::string removeDuplicates(const std::string strOrigin);
	void createOrder(std::vector<int>&);
	void createSubstitution(std::string);
	void reverseSubstitution();

public:
	transpositioncipher(const std::string& KeySecret);
	virtual ~transpositioncipher() = default;

	std::string encrypt(const std::string& strOrigin);
	std::string decrypt(const std::string& strOrigin);
	void print();
};

#endif /* TRANSPOSITIONCIPHER_H_ */
