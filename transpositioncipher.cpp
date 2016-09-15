/*
 * transpositioncipher.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: hnnguyen
 */

#include "transpositioncipher.h"

transpositioncipher::transpositioncipher(const std::string& KeySecret) {
//	log("Constructor");

	mKeySecret = removeDuplicates(KeySecret);
//	for (char c = 'a'; c <= 'z'; ++c) {
//		mapOriginAlphabet[c] = mKeySecret.find(c) == std::string::npos;
//		std::size_t found = mKeySecret.find(c);
//		if (found != std::string::npos) {
//			mapOriginAlphabet[c] = false;
//		} else {
//			mapOriginAlphabet[c] = true;
//		}
//	}
	createSubstitution(mKeySecret);
	reverseSubstitution();
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


//source from
//http://codereview.stackexchange.com/questions/126756/removing-duplicate-characters-from-a-string
void transpositioncipher::createOrder(std::vector<int>& vecOrder) {
//	log("createOrder");
	std::set<char> chars { mKeySecret.begin(), mKeySecret.end() };

	std::string strTemp = std::string(chars.begin(), chars.end());

	for (auto& x : strTemp) {
		std::size_t found = mKeySecret.find(x);

		vecOrder.push_back(found);
	}

}


void transpositioncipher::createSubstitution(std::string strKeySecret) {
//	log("createSubstitution");

	std::vector<int> vecOrder;
	createOrder(vecOrder);

	std::map<char,bool> mapOriginAlphabet;
	for (char c = 'a'; c <= 'z'; ++c) {
			mapOriginAlphabet[c] = mKeySecret.find(c) == std::string::npos;
	}
	int iCols = mKeySecret.length();
	int iRows = ALPHABET_SIZE / iCols + 1;



	std::vector<std::vector<char>> vecTemp;

	std::vector<char> vecFirstRow;
	for (auto& x : mKeySecret) {
		vecFirstRow.push_back(x);
	}
	vecTemp.push_back(vecFirstRow);

//	int index = 97;
	int iNumRow = 0;
	char c = 'a';

	while (iNumRow < iRows) {
		std::vector<char> row;
		int iNumCol = 0;
		while (iNumCol < iCols) {
			if (mapOriginAlphabet[c]) {
				row.push_back(c);
				iNumCol++;
			}
//			index++;
			c++;
//			if (index > 123) {
//				break;
//			}
			if (c > 'z')
				break;
		}
		vecTemp.push_back(row);
		iNumRow++;
	}

	c = 'a';
//	index = 97;
	for (auto& indexCol: vecOrder) {
		for (auto& vec: vecTemp) {
			if (indexCol < vec.size()){
				mapAlphabet[c] = vec.at(indexCol);
				c++;
//				mapAlphabet[(char)index] = vec.at(indexCol);
//				index ++;
			}
		}
	}
}

std::string transpositioncipher::encrypt(const std::string& strOrigin) {
	std::string ret;
	for (auto& x: strOrigin) {
		try {
			ret += mapAlphabet[x];
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return ret;
}

void transpositioncipher::reverseSubstitution() {
	for (auto& x: mapAlphabet) {
		mapReverseAlphabet[x.second] = x.first;
	}
}

std::string transpositioncipher::decrypt(const std::string& strOrigin) {
	std::string ret;
	for (auto& x: strOrigin) {
		try {
			ret += mapReverseAlphabet[x];
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		}
	return ret;
}
