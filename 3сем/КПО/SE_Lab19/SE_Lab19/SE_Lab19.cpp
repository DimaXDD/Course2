#include "FST.h"
#include <iostream>

#define regularExpr FST::NODE(1, FST::RELATION('r',1)),\
                    FST::NODE(2, FST::RELATION(' ',1),FST::RELATION('b',2)),\
                    FST::NODE(2, FST::RELATION(' ',2),FST::RELATION(' ',3)),\
                    FST::NODE(2, FST::RELATION('p',4),FST::RELATION('c',4)),\
                    FST::NODE(1, FST::RELATION(';',5)),\
                    FST::NODE(3, FST::RELATION('b',2), FST::RELATION('e',7), FST::RELATION(' ',6)),\
                    FST::NODE(2, FST::RELATION('e',7),  FST::RELATION(' ',6)),\
                    FST::NODE(1, FST::RELATION(';',8)),\
                    FST::NODE()

using namespace std;


using FST::NODE; // без этого просто не работает :(
using FST::RELATION;


int main()
{
	setlocale(LC_ALL, "ru");
	
    FST::FST f1((char*)"rb c;e;", 9, regularExpr);
    FST::FST f2((char*)"r b p; e;", 9, regularExpr);
    FST::FST f3((char*)"r  b c;b c;   e;", 9, regularExpr);
    FST::FST f4((char*)"rb       p;;", 9, regularExpr);
    FST::FST f5((char*)"r  b c;b c;e;", 9, regularExpr);
    FST::FST f6((char*)"r b p;      e;", 9, regularExpr);
    FST::FST f7((char*)"r   b c;b p;      e;", 9, regularExpr);
	
    FST::FST Arr[] = { f1,f2,f3,f4,f5,f6,f7 };
    for (int i = 0; i < 7; i++)
    {
        if (FST::execute(Arr[i]))
            cout << "Цепочка " << Arr[i].string << " распознана" << endl;
        else cout << "Цепочка " << Arr[i].string << " не распознана" << endl;
    }
}