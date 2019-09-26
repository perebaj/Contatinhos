#include "interpreter.h"

int main(int argc, char**argv){
    string in;

    if(argc > 1)
        in = "cin";

    interpreter inter(in);
    inter.exec();
    return 0;
}