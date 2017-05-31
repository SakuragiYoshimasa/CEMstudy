#include "CartPoleEnv.hpp"

#pragma region Interface

const std::vector<double>& CartPoleEnv::reset(){
    obs = new std::vector<double>(obs_dim(), 0);
    step_count = 0;
    reset_host();
    get_observation();
    return *obs;
}

int CartPoleEnv::obs_dim(){
    return 4;
}

EnvResponse CartPoleEnv::step(Action action){

    std::cout << "s " << action << std::endl;
    get_observation();
    step_count++;

    EnvResponse response = *new EnvResponse();
    response.observation = obs;
    response.reward = 1;
    response.isFinished = step_count >= MAX_STEP;

    return response;
}

void CartPoleEnv::end(){
    quit_host();
}
#pragma endregion //Interface

#pragma region Lapper

void CartPoleEnv::reset_host(){
    std::cout << "r" << std::endl;
}

void CartPoleEnv::quit_host(){
    std::cout << "q" << std::endl;
}

void CartPoleEnv::get_observation() {

    std::string stat;
    std::cin >> stat;

    if (stat == "obs") {
        for (int i = 0; i < obs_dim(); ++i) std::cin >> obs->at(i);
    } else if (stat == "done") {
        step_count = MAX_STEP; //Force to reset;
    }
}

#pragma endregion //Lapper
