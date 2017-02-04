//
//  classes.h
//  Intermediate
//
//  Created by Pedro Data on 2/4/17.
//  Copyright © 2017 Pedro Data. All rights reserved.
//

#ifndef classes_h
#define classes_h


class MinhaExecpcao : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Algo se passou";
    }
};

class Test {
public:
    void algoSePassa(){
        throw MinhaExecpcao();
    }
};

class CorreMalAssim {
public:
    CorreMalAssim(){
        char *pMemory = new char[999];
        delete [] pMemory;
    }
};


void execpcoes() {
    try {
        Test corre;
        corre.algoSePassa();
    } catch(MinhaExecpcao &e) {
        std::cout << "Aanha a execpcao: " << e.what() << std::endl;
    }
    
    
    Cat *an = new Cat();
    an->speak();
    delete an;
    
    std::cout << "a correr ... " << std::endl;
    
}


#endif /* classes_h */
