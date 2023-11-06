#include "espacio.h"

char Espacio::getSigno() const
{
    return signo;
}

void Espacio::setSigno(char newSigno)
{
    signo = newSigno;
}

Espacio::Espacio()
{
    signo='N';
}

Espacio::Espacio(char s)
{
    signo=s;
}
