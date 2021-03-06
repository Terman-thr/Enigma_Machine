#ifndef ENIGMA_MACHINE_ROTOR_H
#define ENIGMA_MACHINE_ROTOR_H
static const int CODELOOP=62;
#include <cstdlib>
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

class Rotor{
protected:
    int* CODE; // The standard Code Alphabet 0-9 A-Z a-z total 62 chars
    int* GearCode; // The corresponding Code of one specific gear
    int Pos; // The position of the interface
    int number=0;
    static char num2code(int n); // Convert number of 1 to 62 to corresponding char
    static int code2num(char ch); // Convert corresponding char to number of 1 to 62
public:
    Rotor(char encode='0',char pos='0');
    ~Rotor();
    void Rotate();
    char getResultIn(char input);
    int getResultIn(int input);
    char getResultOut(char input);
    int getResultOut(int input);
    int getNum();
};

int Rotor::code2num(char ch) {
    if (ch>='0' && ch<='9') return (ch-'0'+1);
    else if (ch>='A' && ch<='Z') return (ch-'A'+11);
    else return (ch-'a'+37);
}

char Rotor::num2code(int n) {
    if (n<=9) return (char )(n+'0'-1);
    else if (n<=35) return (char )(n-11+'A');
    else return (char )(n-37+'a');
}

Rotor::Rotor(char encode,char pos) {
    Pos=code2num(pos); //initial position
    CODE=new int[CODELOOP];
    for (int i=0;i<CODELOOP;++i)
        CODE[i]=i+1;

    GearCode=new int[CODELOOP];
    for (int i=0;i<CODELOOP;++i)
        GearCode[i]=i+1;

    srand(code2num(encode));
    for (int i=0;i<CODELOOP;++i)
        swap(GearCode+i,GearCode+rand()%CODELOOP);

    for (int i=0;i<Pos;i++)
        Rotate();
}

Rotor::~Rotor() {
    delete [] CODE;
    delete [] GearCode;
}

void Rotor::Rotate() {
    int tmp=*(GearCode+CODELOOP-1);
    for(int i=CODELOOP-1;i>0;i--)
        *(GearCode+i)=*(GearCode+i-1);
    *GearCode=tmp;
    tmp=*(CODE+CODELOOP-1);
    for(int i=CODELOOP-1;i>0;i--)
        *(CODE+i)=*(CODE+i-1);
    *CODE=tmp;
}

int Rotor::getNum(){
    return number;
}

char Rotor::getResultIn(char input) {return num2code(*(GearCode+code2num(input)-1));}

char Rotor::getResultOut(char input) {return num2code(*(CODE+code2num(input)-1));}

int Rotor::getResultIn(int input) {return *(GearCode+input-1);}

int Rotor::getResultOut(int input) {return *(CODE+input-1);}
/*
class Plugboard: public Rotor{
public:
    Plugboard(char encode, char pos);
    ~Plugboard();
    void swap(char a,char b);
};

Plugboard::Plugboard(char encode, char pos) : Rotor(encode, pos) {

}*/

#endif //ENIGMA_MACHINE_ROTOR_H
