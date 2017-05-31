#include "EasyEnv.hpp"

const std::vector<double>& EasyEnv::reset(){

    mt = *new std::mt19937(rnd());
    rand = *new std::uniform_real_distribution<>(-1.0, 1.0);

    obs = new std::vector<double>{rand(mt)};
    prev_obs = obs->at(0);
    step_count = 0;
    return *obs;
}

int EasyEnv::obs_dim(){
    return 1;
}

EnvResponse EasyEnv::step(Action action){
    step_count++;
    EnvResponse response = *new EnvResponse();
    obs->at(0) = rand(mt);
    response.observation = obs;
    response.reward = action * prev_obs;
    response.isFinished = step_count >= 10;

    prev_obs = response.observation->at(0);
    return response;
}

EasyEnv::EasyEnv(){};
EasyEnv::~EasyEnv(){};
