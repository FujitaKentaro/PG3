#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <vector>

#include <iostream>
#include <list>

using namespace std;

int main() {

	std::list<const char*> yamanote = {
		"Tokyo","Kanda","Akihabara","Okatimati","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
		"Ootuka","Ikebukuro","Mejiro","Takadanobaba","shinookubo",
		"Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro",
		"Gotanda","Oosaki","Shinagawa","Tamati","Hamamatutyou",
		"Shinbasi","Yurakutyou"		
	};

	std::cout << "1970s";
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	std::cout<< "\n";

	std::cout << "2019s";
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		if (*itr == "Tabata") {
			itr = yamanote.insert(itr, "Nishinippori");
			++itr;
		}
	}
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	std::cout << "\n";

	std::cout << "2022s";
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		
		if (*itr == "Tamati") {
			itr = yamanote.insert(itr, "Takanawagetowei");
			++itr;
		}
	}
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		std::cout << *itr << "\n";
	}

	system("pause");

	return 0;
}
