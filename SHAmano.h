#pragma once

#ifndef SHAmano_H
#define SHAmano_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <vector>
#include <bitset>

#include <fstream>

#include <chrono>

#include <random>

#include <algorithm>

using namespace std;

template<size_t N>
std::string bitset_to_string(std::bitset<N> bits) {
	static_assert(N % CHAR_BIT == 0, L"bitset size must be multiple of char");
	std::string toReturn;
	for (size_t j = 0; j < N / CHAR_BIT; ++j)
	{
		char next = 0;
		for (size_t i = 0; i < CHAR_BIT; ++i)
		{
			size_t index = N - (CHAR_BIT * j) - i - 1;
			size_t pos = CHAR_BIT - i - 1;
			if (bits[index])
				next |= (1 << pos);
		}
		toReturn.push_back(next);
	}
	return toReturn;
}

template< size_t size>
typename std::bitset<size> random_bitset(double p = 0.5) {

	typename std::bitset<size> bits;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution d(p);

	double iSecret;

	for (int n = 0; n < size; ++n) {
		iSecret = rand() % 999901 + 100;
		bits[n] = bits[n] + d(gen);
	}

	return bits;
}

#include <type_traits>

bool is_emptyy(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

#include <regex>
bool invalidChar(char c)
{
	return !(c >= 0 && c < 128);
}
void stripUnicode(string& str)
{
	str.erase(remove_if(str.begin(), str.end(), invalidChar), str.end());
}
string paverstihex(string& s)
{
	ostringstream ret;

	string pridedas = "";
	string simbolis = "";
	string tuscia = "";

	char simbolisc;

	string stringas = "kriptografija";

	int bitai;

	int skaicius;

	int dydis = s.length();

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 10000000000000);
	srand(dis(gen));
	random_shuffle(s.begin(), s.end());
	random_shuffle(stringas.begin(), stringas.end());

	if (s.length() < 66) {
		while (s.length() < 66) {
			char cch = 'a' + rand() % 26;

			s.push_back(cch);
		}
	}
	for (int i = 0; i < s.length(); i++) {
		bitset<8> bs4(s[i]);
		skaicius = rand() % 2 + 1;
		bitset<8> bar(skaicius);
		bitset<8> bs3(bs4 <<= skaicius & skaicius);
		bitset<8> bs5(bs3 <<= skaicius);
		bitset<8> rez(bs5 ^= bar);

		tuscia = bitset_to_string(rez);
		random_shuffle(tuscia.begin(), tuscia.end());
	}
	s.append(tuscia);
	s.append(stringas);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
	if (s.length() > 64) {
		while (s.length() != 64) {
			s.pop_back();
		}
	}
	return s;
}
#endif