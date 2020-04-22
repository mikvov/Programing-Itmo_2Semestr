#include "Stroka.h"

class DecStr : public Stroka

{

public:
    DecStr(int = 0);

    //DecStr(char);

    DecStr(const char *);

    DecStr(const DecStr &);

    ~DecStr();

    DecStr &operator=(const DecStr &);

    friend DecStr operator+(const DecStr &, const DecStr &);

    //friend DecStr operator +(const DecStr& pobj1, const int obj2);

    //friend DecStr operator - (const DecStr&,const DecStr&);

    //friend int operator == (const DecStr&,const DecStr&);
};