#include "IdentStr.h"

IdentStr::IdentStr(int val) : Stroka(val)

{

    cout << "IdentStr::IdentStr(int val):Stroka(val),val=" << val << endl;
}

IdentStr::IdentStr(char Ch) : Stroka(Ch)

{

    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))

    {

        cout << "Bad Simvol; pCh[0]" << pCh[0] << endl;

        if (pCh)
            delete[] pCh;

        len = 0;

        pCh = new char[len + 1];

        pCh[0] = '\0';

        return;
    }

    cout << "IdentStr::IdentStr(char Ch):Stroka(Ch)" << endl;
}

IdentStr::IdentStr(const char *Str) : Stroka(Str)

{

    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))

    {

        cout << "Bad Simvol,pCh[0]=" << pCh[0] << endl;

        if (pCh)
            delete[] pCh;

        len = 0;

        pCh = new char[len + 1];

        pCh[0] = '\0';

        return;
    }

    for (int i = 1; i < len; i++)

    {

        if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))

        {

            cout << "Bad stroka, pCh[" << i << "]=" << pCh[i] << endl;

            if (pCh)
                delete[] pCh;

            len = 0;

            pCh = new char[len + 1];

            pCh[0] = '\0';

            return;
        }
    }

    cout << "IdentStr::IdentStr(char* Str):Stroka(Str)" << endl;
}

IdentStr::IdentStr(const IdentStr &from) : Stroka(from)

{

    cout << "IdentStr::IdentStr(const IdentStr& from): Stroka(from)" << endl;
}

IdentStr::~IdentStr()

{

    cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr &IdentStr::operator=(const IdentStr &S)

{

    if (&S != this)

    {

        delete[] pCh;

        len = strlen(S.pCh);

        pCh = new char[len + 1];

        strcpy(pCh, S.pCh);
    }

    cout << "IdentStr& IdentStr::operator=(const IdentStr& S)" << endl;

    return *this;
}

char &IdentStr::operator[](int index)

{

    if (index >= 0 && index < len)

    {

        cout << "char& IdentStr::operator[](int index)" << endl;

        return pCh[index];
    }

    return pCh[0];

    //}
}

IdentStr IdentStr::operator~()

{

    int i, j;

    char tmp;

    for (i = 0, j = len - 1; i < len / 2; i++, j--)

    {

        tmp = pCh[i];

        pCh[i] = pCh[j];

        pCh[j] = tmp;
    }

    cout << "IdentStr IdentStr::operator ~ ()" << endl;

    return *this;
}

IdentStr operator+(const IdentStr &pobj1, const IdentStr &pobj2)

{

    //IdentStr tmp(pobj1);

    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());

    //strcpy_s(tmp.pCh,tmp.len+1, pobj1.GetStr());

    int i = 0, j = 0;

    while (tmp.pCh[i++] = pobj1.pCh[j++])
        ;

    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());

    --i; //i = pobj1.GetLen();

    j = 0;

    while (tmp.pCh[i++] = pobj2.pCh[j++])
        ;

    cout << "IdentStr operator + (const IdentStr pobj1,const IdentStr pobj2)" << endl;

    return tmp;
}

IdentStr operator+(const IdentStr &pobj1, const char *pobj2)

{

    //IdentStr tmp(pobj1);

    IdentStr tmp1(pobj2);

    //if (tmp1.len == 0)

    //{

    // IdentStr tmp(pobj1.GetLen());

    // int i = 0, j = 0; //i = pobj1.GetLen();

    // while (tmp.pCh[i++] = pobj1.pCh[j++]);

    // cout << "IdentStr operator + ( const IdentStr& pobj1,const char* pobj2,)" << endl;

    // return tmp;

    //}

    //else

    //{

    IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());

    //IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));

    int i = 0, j = 0;

    while (tmp.pCh[i++] = pobj1.pCh[j++])
        ;

    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());

    --i; //i = pobj1.GetLen();

    j = 0;

    //while (tmp.pCh[i++] = *pobj2++);

    while (tmp.pCh[i++] = tmp1.pCh[j++])
        ;

    cout << "IdentStr operator + (const IdentStr& pobj1,const char* pobj2)" << endl;

    return tmp;

    //}

    //IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));

    //strcpy_s(tmp.pCh,tmp.len+1, pobj1.GetStr());

    //int i = 0, j = 0;

    //while (tmp.pCh[i++] = pobj1.pCh[j++]);

    //strcat_s(tmp.pCh,tmp.len+1, pobj2);

    //--i; //i = pobj1.GetLen();

    //j = 0;

    //while (tmp.pCh[i++] = pobj2[j++]);

    //while (tmp.pCh[i++] = *pobj2++);

    //cout << "IdentStr operator + (const IdentStr pobj1,const char* pobj2)" << endl;

    //return tmp;
}

IdentStr operator+(const char *pobj1, const IdentStr &pobj2)

{

    IdentStr tmp1(pobj1);

    if (tmp1.len == 0)

    {

        IdentStr tmp(pobj2.GetLen());

        int i = 0, j = 0; //i = pobj1.GetLen();

        while (tmp.pCh[i++] = pobj2.pCh[j++])
            ;

        cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << endl;

        return tmp;
    }

    else

    {

        IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());

        int i = 0, j = 0;

        while (tmp.pCh[i++] = *pobj1++)
            ;

        //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());

        --i; //i = pobj1.GetLen();

        //j = 0;

        while (tmp.pCh[i++] = pobj2.pCh[j++])
            ;

        cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << endl;

        return tmp;
    }

    //IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());

    //strcpy_s(tmp.pCh,tmp.len+1, pobj1);

    //int i = 0, j = 0;

    //while (tmp.pCh[i++] = *pobj1++);

    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());

    //--i; //i = pobj1.GetLen();

    //j = 0;

    //while (tmp.pCh[i++] = pobj2.pCh[j++]);

    //cout << "IdentStr operator + (const char* pobj2, const IdentStr pobj1)" << endl;

    //return tmp;
}