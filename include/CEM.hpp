#ifndef CEM_hpp
#define CEM_hpp

#include "CartPoleEnv.hpp"
#include "LinearModel.hpp"
#include "EasyEnv.hpp"
#include <random>
#include <string>
#include <iostream>
#include <fstream>

class CEM {
public:
    void init(Env* _env, int _N = 100, double _rho = 0.1, double _random_variance = 1.0, bool _update_random_variance = false);
    void init(int _N = 100, double _rho = 0.1, double _random_variance = 1.0, bool _update_random_variance = false);
    void learn();
    void update();
    void writeResult(std::string file = "test.csv");
    void writeSampleEfficiency(std::string file = "se.csv");
    void test1cycle();
    void quit();

    LinearModel& getModel();

    CEM();
    ~CEM();

private:
    bool eval(std::vector<std::pair<int, double>>& sorted_incomes);
    std::vector<double> update_params(std::vector<LinearModel*>& new_models, std::vector<std::pair<int, double>>& incomes);
    void update_rv(std::vector<double>& new_params, std::vector<LinearModel*>& new_models, std::vector<std::pair<int, double>>& incomes);

    //Parameters
    int N = 100;
    bool update_random_variance = false;
    double rho = 0.1;
    double random_mean = 0.0;
    double random_variance = 1.0;
    double evalate_percentage = 0.95;

    //Data
    bool learned;
    long long step_num;
    long long episode_num;
    long long update_params_num;
    LinearModel* model;
    Env* env;
    std::vector<double> obs;
    std::normal_distribution<double> dist;
    std::random_device seed_gen;
    std::default_random_engine engine;
};

#endif /* CEM_hpp */
