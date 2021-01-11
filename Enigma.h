#ifndef ENIGMA_MACHINE_ENIGMA_H
#define ENIGMA_MACHINE_ENIGMA_H
#include "Rotor.h"
#include <string>
class Enigma{
private:
    Rotor *rotors;
    Rotor *plug;
    Rotor *reflect;
public:
    Enigma(const std::string& str);
    ~Enigma();

};

Enigma::Enigma(const std::string& str){
    rotors=new Rotor[str.size()];
    plug=rotors+str.size()-1;
    reflect=rotors+str.size();


}

Enigma::~Enigma() {
    delete rotors;
}


#endif //ENIGMA_MACHINE_ENIGMA_H
