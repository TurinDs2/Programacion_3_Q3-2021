#include "clsCarta.h"

clsCarta::clsCarta() {}

clsCarta::~clsCarta() {}

int clsCarta::getNum() {
	return num;
}

char clsCarta::getSigno() {
    return signo;
}

string clsCarta::getCarta()
{
    string Carta = "";
    Carta += std::to_string(num);
    Carta += signo;
    return Carta;
}

void clsCarta::setNum(int n) {
	num = n;
}

void clsCarta::setSigno(char s) {
	signo = s;
}

void clsCarta::Mostrar_Carta() {
    cout<<"|"<<setfill(' ')<<setw(14)<<getNum()<<getSigno()<<"|"<<endl;
}
