/*
 * transpositioncipher.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: hnnguyen
 */

#include "transpositioncipher.h"

transpositioncipher::transpositioncipher(std::string KeySecret) {
//	log("Constructor");
	mKeySecret = removeDuplicates(KeySecret);
	createOrder();
	for (int i = 97; i < 123; ++i) {
		char c = (char) i;
		std::size_t found = mKeySecret.find(c);
		if (found != std::string::npos) {
			mapOriginAlphabet[c] = false;
		} else {
			mapOriginAlphabet[c] = true;
		}
	}
	createSubstitution();
	reverseSubstitution();
}

transpositioncipher::~transpositioncipher() {
}

//source from
//http://codereview.stackexchange.com/questions/126756/removing-duplicate-characters-from-a-string
std::string transpositioncipher::removeDuplicates(const std::string strOrigin) {
//	log("removeDuplicates");
	std::set<char> moved;
	std::string result;
	result.reserve(strOrigin.size());

	//Only copy one character of each type to the new string
//	std::copy_if(std::begin(strOrigin), std::end(strOrigin),
//			std::back_inserter(result),
//			[&moved](const auto& value) {return moved.insert(value).second;});
	result += strOrigin[0];
	for (auto& x: strOrigin) {
		if (result.find(x) !=  std::string::npos) {
			continue;
		} else {
			result += x;
		}
	}
	return result;
}


void transpositioncipher::print() {

}

//source from
//http://codereview.stackexchange.com/questions/126756/removing-duplicate-characters-from-a-string
void transpositioncipher::createOrder() {
//	log("createOrder");
	std::set<char> chars { mKeySecret.begin(), mKeySecret.end() };

	std::string strTemp = std::string(chars.begin(), chars.end());

	for (auto& x : strTemp) {
		std::size_t found = mKeySecret.find(x);

		vecOrder.push_back(found);
	}

}


void transpositioncipher::createSubstitution() {
//	log("createSubstitution");

	int iCols = mKeySecret.length();
	int iRows = 26 / iCols + 1;

	std::vector<std::vector<char>> vecTemp;

	std::vector<char> vecFirstRow;
	for (auto& x : mKeySecret) {
		vecFirstRow.push_back(x);
	}
	vecTemp.push_back(vecFirstRow);

	int index = 97;
	int iNumRow = 0;

	while (iNumRow < iRows) {
		std::vector<char> row;
		int iNumCol = 0;
		while (iNumCol < iCols) {
			if (mapOriginAlphabet[(char) index]) {
				row.push_back((char) index);
				iNumCol++;
			}
			index++;
			if (index > 123) {
				break;
			}
		}
		vecTemp.push_back(row);
		iNumRow++;
	}

	index = 97;
	for (auto& indexCol: vecOrder) {
		for (auto& vec: vecTemp) {
			if (indexCol >= vec.size())
				continue;
			else {
				mapAlphabet[(char)index] = vec.at(indexCol);
				index ++;
			}
		}
	}
}

std::string transpositioncipher::encrypt(const std::string strOrigin) {
	std::string ret;
	for (auto& x: strOrigin) {
		ret += mapAlphabet[x];
	}

	return ret;
}

void transpositioncipher::reverseSubstitution() {
	for (auto& x: mapAlphabet) {
		mapReverseAlphabet[x.second] = x.first;
	}
}

std::string transpositioncipher::decrypt(const std::string strOrigin) {
	std::string ret;
	for (auto& x: strOrigin) {
			ret += mapReverseAlphabet[x];
		}
	return ret;
}
