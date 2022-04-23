#ifndef PROSTAFORMAZYCIA_H
#define PROSTAFORMAZYCIA_H

#include "formazycia.h"

class ProstaFormaZycia : public FormaZycia
{

public:
    ProstaFormaZycia(string nazwa ="",string filePath="");
    void setRozmiar(int);

};

#endif // PROSTAFORMAZYCIA_H
