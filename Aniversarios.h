//
//  Aniversarios.h
//  Intermediate
//
//  Created by Pedro Data on 2/4/17.
//  Copyright © 2017 Pedro Data. All rights reserved.
//

#ifndef Aniversarios_h
#define Aniversarios_h
#include <fstream>

const int MAX_NAME = 20;
const int MAX_IGNORE = 256;

struct PersonBirthday {
    char name[MAX_NAME];
    unsigned int day, month, year;
};

void escreverAniversario() {
    
    //unsigned daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    ofstream aniversarios("aniversario.dat", ios::binary);
    
    if(!aniversarios) {
        // se nao existe pode criar
        std::cout << "nao pode abrir ficheiro. " <<  std::endl;
    }
    
    char ch;
    
    do {
        PersonBirthday person;
        
        std::cout << "Nome - " ; cin.getline(person.name, MAX_NAME);
        
        std::cout << "Data de nascimento(dia mes e ano) - ";
        cin >> person.day >> person.month >> person.year;
        
        aniversarios.write(( char *) &person, sizeof(person));
        
        std::cout << "Pretende introduzir mais aniversarios? (S/N)" << std::flush;
        cin >> ch;
        cin.ignore(MAX_IGNORE, '\n');
        
    } while(toupper(ch) == 'S');
}

void lerAniversarios() {
    unsigned daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    ifstream aniversarios("aniversario.dat", ios::binary);
    
    PersonBirthday person;
    
    if(!aniversarios) {
        // se nao existe pode criar
        std::cout << "nao pode abrir ficheiro. " <<  std::endl;
    }
    
    unsigned int day, month;
    
    do {
        
        std::cout << "Data de aniversario (dia mes) ?  " << std::flush;
        cin >> day >> month;
        
    } while(month < 1 || month > 12 || day < 1 || day > daysOfMonth[month-1]);
    
    while(aniversarios.read((char *) & person, sizeof(person))) {
        if(person.day == day && person.month == month) {
            std::cout << person.name << std::endl;
        }
    }
}

#endif /* Aniversarios_h */
