#ifndef Env_hpp
#define Env_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

enum Action {
    A = 1, B = -1
};

struct EnvResponse {
    std::vector<double>* observation;
    double reward;
    bool isFinished;
};

class Env {
public:
    virtual const std::vector<double>& reset()=0;
    virtual int obs_dim()=0;
    virtual EnvResponse step(Action action)=0;
    virtual void end()=0;
    Env(){};
    ~Env(){};
};

#endif /* Env_hpp */
