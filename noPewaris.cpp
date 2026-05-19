#include <iostream>
using namespace std;

class baseClass final{
public:
    virtual void perkenalan() {
        cout << "Hallo saya Function dari base class";
    }    
};
class baseClass1 {
public:
    virtual void perkenalan() {
        cout << "Hallo saya Functioonal dari base class";
    }    
};
class darivedClass : public baseClass1 {
public:
    void perkenalan() {
        cout << "Hallo saya function dari darived Class";
    }    
};
