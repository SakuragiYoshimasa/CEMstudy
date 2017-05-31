#include <iostream>
#include "./../include/CEM.hpp"

int main(int argc, const char * argv[]) {

    //Update random_variance
    CEM* cem = new CEM();
    cem->init(new CartPoleEnv(), 100, 0.1, 1.0, true); //InitEnv

    for(int i = 0; i < 20; i++){
        cem->init(100, 0.1, 1.0, true);
        cem->learn();
        std::string seFileName = "se.csv";
        seFileName = "_RV_" + seFileName;
        seFileName = std::to_string(i) + seFileName;
        seFileName = "./Experiment/Results/UpdateRV/" + seFileName;
        cem->writeSampleEfficiency(seFileName);
        std::cerr << "Finish" << i << std::endl;
    }
    cem->quit();

    return 0;
}
