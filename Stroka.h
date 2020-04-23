#include <iostream>
#include <string.h>
using namespace std;

class Stroka
{
protected:
    int len;
    char *pCh;

private:
    /* data */
public:
    ~Stroka();
    Stroka();
    Stroka(int = 0);
    Stroka(char);
    Stroka(const char *);
    Stroka(const Stroka &);
    char *GetStr(void) const { return pCh; };
    int GetLen(void) const { return len; };
    void Show(void);
};