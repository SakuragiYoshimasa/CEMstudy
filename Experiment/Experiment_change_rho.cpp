#include <iostream>
#include "./../include/CEM.hpp"

int main(int argc, const char * argv[]) {

    constexpr int sampling_num = 4;
    double rho[sampling_num] = {0.5, 0.1, 0.15, 0.2};

    CEM* cem = new CEM();
    cem->init(new CartPoleEnv(), 100, 0.1, 1.0); //InitEnv

    for(int i = 0; i < sampling_num; i++){
      for(int j = 0; j < 10; j++){

          cem->init(100, rho[i], 1.0);
          cem->learn();
          std::string seFileName = "se.csv";
          seFileName = "_Rho_" + seFileName;
          seFileName = std::to_string(j) + seFileName;
          seFileName = std::to_string(i) + seFileName;
          seFileName = "./Experiment/Results/ChangeRho/" + seFileName;
          cem->writeSampleEfficiency(seFileName);
          std::cerr << "Finish" << i << j << std::endl;
        }
    }
    cem->quit();
    return 0;
}
