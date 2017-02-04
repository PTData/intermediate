#ifndef Polimorphism_h
#define Polimorphism_h


class Animal {
public:
    virtual void speak() = 0;
    virtual                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ~Animal() {}
};

class Cat : public Animal {
public:
    void speak()  {
        std::cout << "Grrr" << std::endl;
    }
    ~Cat(){}
};

class HouseCat : public Cat {
public:
    void speak()  {
        std::cout << "Meowww" << std::endl;
    }
    ~HouseCat() {}
};

#endif /* Polimorphism_h */
