#include <iostream>
#include "CEM.hpp"

int main(int argc, const char * argv[]) {

    CEM* cem = new CEM();
    cem->init(new CartPoleEnv());
    cem->learn();
    cem->writeResult();
    cem->writeSampleEfficiency();
    cem->quit();

    return 0;
}
