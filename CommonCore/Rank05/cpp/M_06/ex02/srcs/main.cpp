#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(){
    Base *t;
    
    srand(time(0));
    t = generate();
    Base &t2 = *t;
    identify(t);
    identify(t2);
    return 0;
}