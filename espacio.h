#ifndef ESPACIO_H
#define ESPACIO_H


class Espacio
{
private:
    char signo;
public:
    Espacio();
    Espacio(char s);
    char getSigno() const;
    void setSigno(char newSigno);
};

#endif // ESPACIO_H
