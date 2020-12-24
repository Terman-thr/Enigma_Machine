#include <iostream>
#include <cstdlib>
#include "Rotor.h"
int main(){
    using namespace std;
    Rotor a('1','2');
    for (int i=1;i<=62;i++)
        cout<<a.getResultIn(i)<<endl;

}