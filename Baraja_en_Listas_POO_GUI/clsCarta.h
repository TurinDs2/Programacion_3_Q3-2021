#ifndef CLSCARTA_H
#define CLSCARTA_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <typeinfo>
using std::vector;
using std::setfill;
using std::setw;
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::ofstream;
using std::string;

class clsCarta {
	private: 
		int num;
		char signo;
	public:
		clsCarta();
		~clsCarta();
		int getNum();
		char getSigno();
        string getCarta();
		void setNum(int);
		void setSigno(char);
		void Mostrar_Carta();
};
#endif
