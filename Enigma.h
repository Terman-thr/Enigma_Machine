#ifndef ENIGMA_MACHINE_ENIGMA_H
#define ENIGMA_MACHINE_ENIGMA_H
#include "Rotor.h"
class Enigma{
private:
    Rotor *rotors;
    Rotor reflect;

public:
    Enigma();
    ~Enigma();

};
#endif //ENIGMA_MACHINE_ENIGMA_H
