#ifndef INHERITANCE_FACTORYBUFFER_H
#define INHERITANCE_FACTORYBUFFER_H

class Pieces;

class FactoryBuffer{
public:
    FactoryBuffer(){
        createBuffer();
    };
    Pieces *buffer[8][8]{nullptr};
    void createBuffer();
};

#endif //INHERITANCE_FACTORYBUFFER_H
