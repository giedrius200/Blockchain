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

#include <type_traits>

bool is_emptyy(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

//template<typename T, typename P>
//T remove_if(T beg, T end, P pred)
//{
//	T dest = beg;
//	for (T itr = beg; itr != end; ++itr)
//		if (!pred(*itr))
//			*(dest++) = *itr;
//	return dest;
//}

string paverstihex(string& s)
{
	ostringstream ret;

	string pridedas = "";
	string simbolis = "";
	string tuscia = "";

	char simbolisc;

	string stringas = "kriptografija";

	//string pridedass = stringas;

	int bitai;
	/*for (int i = 0; i < 64; i++) {
		if (s.length() > 64) {
			break;
		}
		s.append(pridedas);
		stringas.append(pridedass);

	}*/

	int skaicius;

	int dydis = s.length();

	/*while (s.length() > stringas.length()) {

		stringas.append(pridedass + s);

	}*/
	srand(time(0));
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
		bitset<8> bs5(bs3 <<= skaicius );
		bitset<8> rez(bs5 ^= bar);

		tuscia = bitset_to_string(rez);
		random_shuffle(tuscia.begin(), tuscia.end());
	}
	s.append(tuscia);
	s.append(stringas);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
	//s.pop_back();
	/*if (s.length() < 66) {
		while (s.length() < 66) {
			char cch = 'a' + rand() % 26;

			s.push_back(cch);
		}
	}*/
	if (s.length() > 64) {
		while (s.length() != 64) {
			s.pop_back();
		}
	}
	/*static const char hex_skaiciai[] = "0123456789ABCDEF";

	std::string output;
	output.reserve(s.length() * 2);
	for (unsigned char c : s)
	{
		output.push_back(hex_skaiciai[c >> 4]);
		output.push_back(hex_skaiciai[c & 15]);
	}
	if (output.length() > 64) {
		while (output.length() != 64) {
			output.pop_back();
		}
	}*/
	return s;
}
#endif