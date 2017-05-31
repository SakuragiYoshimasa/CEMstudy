#ifndef CEM_test_CPP
#define CEM_test_CPP
#include "./../include/CEM.hpp"

int main(int argc,char **argv){
    CEM* cem = new CEM();
    cem->init(new EasyEnv());
    cem->test1cycle();
    cem->writeResult();
    return 0;
}
#endif
