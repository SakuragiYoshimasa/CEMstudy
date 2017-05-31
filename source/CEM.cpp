#include "CEM.hpp"

bool compareIncomes(std::pair<int, double> p1, std::pair<int, double> p2){
    return p1.second > p2.second;
}

void CEM::init(Env* _env, int _N, double _rho, double _random_variance, bool _update_random_variance){
    //Initialize Enviroment
    if(_env != NULL) env = _env;
    N = _N;
    rho = _rho;
    learned = false;
    episode_num = 0;
    update_params_num = 0;
    step_num = 0;
    random_variance = _random_variance;
    update_random_variance = _update_random_variance;

    //Initialize Random generator
    std::random_device seed_gen;
    engine = *new std::default_random_engine(seed_gen());
    dist = *new std::normal_distribution<double>(random_mean, random_variance);

    //Initialize LinearModel
    std::vector<double> initial_params = *new std::vector<double>(env->obs_dim());
    for(double& param: initial_params) param = dist(engine);
    model = new LinearModel(initial_params);
    std::cerr << "CEM:initialized." << std::endl;
}

void CEM::init(int _N, double _rho, double _random_variance, bool _update_random_variance){
    init(NULL, _N, _rho, _random_variance, _update_random_variance);
}

void CEM::learn(){
    std::cerr << "CEM:learn start." << std::endl;
    std::cerr <<"variance:" <<random_variance << std::endl;
    std::cerr <<"rho:" <<rho << std::endl;
    while(!learned){
        update();
    }
    std::cerr << "CEM:learn end." << std::endl;
}

void CEM::quit(){
    env->end();
};

void CEM::test1cycle(){
    update();
}

//routine for 100 episode
void CEM::update(){
    std::vector<double> diff_params = *new std::vector<double>(env->obs_dim());
    std::vector<LinearModel*> new_models = *new std::vector<LinearModel*>(0);
    std::vector<std::pair<int, double>> incomes = *new std::vector<std::pair<int, double>>(0);

    for(int n = 0; n < N; n++){
        new_models.push_back(new LinearModel(model->getParams()));
        incomes.push_back(std::make_pair(n, 0));
    }

    for(int n = 0; n < N; n++){
        //StartNewEpisode
        obs = env->reset();
        episode_num++;

        //theta = theta + epsilon
        for(double& param: diff_params) param = dist(engine);
        new_models[n]->updateParams(diff_params);
        double income = 0;
        bool isFinished = false;

        while(!isFinished){
            //Get response from environment with step.
            EnvResponse response = env->step(new_models[n]->action(obs));
            obs = *response.observation;
            income += response.reward;
            isFinished = response.isFinished;
            step_num++;
        }
        //Update incomes
        incomes[n].first = n;
        incomes[n].second = income;
    }

    /*Evaluate all incomes and update model
     *valuate 95th elements of imcome vector,
     *because I assume sorted_incomes is sorted by income values.
     */
    std::sort(incomes.begin(), incomes.end(), compareIncomes); //very slow...
    if(eval(incomes)){
        learned = true;
        return;
    }

    std::vector<double> new_params = update_params(new_models, incomes);

    if(update_random_variance) update_rv(new_params, new_models, incomes);

    model->replaceParams(new_params);
    update_params_num++;
}

std::vector<double> CEM::update_params(std::vector<LinearModel*>& new_models, std::vector<std::pair<int, double>>& incomes){
    double superior_model_num = double(N) * rho;
    std::vector<double> new_params = *new std::vector<double>(env->obs_dim(), 0);
    for(int i = 0; i < superior_model_num; i++){
        int index = incomes[i].first;
        for(int j = 0; j < env->obs_dim(); j++) new_params[j] += new_models[index]->getParams()[j] / superior_model_num;
    }
    return new_params;
}

void CEM::update_rv(std::vector<double>& new_params, std::vector<LinearModel*>& new_models, std::vector<std::pair<int, double>>& incomes){
    double superior_model_num = double(N) * rho;
    double new_rv = 0;
    for(int i = 0; i < superior_model_num; i++){
        int index = incomes[i].first;
        for(int j = 0; j < env->obs_dim(); j++){
            double diff = (new_models[index]->getParams()[j] - new_params[j]);
            new_rv += diff * diff / (superior_model_num * double(env->obs_dim()));
        }
    }
    random_variance = new_rv > 0.2 ? new_rv : 0.2;
    dist = *new std::normal_distribution<double>(random_mean, random_variance);
    std::cerr <<"variance:" <<random_variance << std::endl;
}

bool CEM::eval(std::vector<std::pair<int, double>>& sorted_incomes){
    int evalIndex = int(double(N) * evalate_percentage) - 1;
    std::cerr << "NowScore:";
    std::cerr << sorted_incomes[0].second;
    std::cerr << "," << sorted_incomes[evalIndex/2].second;
    std::cerr << "," << sorted_incomes[evalIndex].second << std::endl;

    double average = 0;
    for(std::pair<int, double> p:sorted_incomes) average += p.second / double(N);
    std::cerr << "Average:" << average << std::endl;

    return sorted_incomes[evalIndex].second == 500;
}

void CEM::writeResult(std::string file){
    std::vector<double> result_params = model->getParams();
    std::ofstream fs;
    fs.open(file, std::ios::out);

    for(double param: result_params){
        std::cerr << param << std::endl;
        fs << param << std::endl;
    }
    fs.close();
}

void CEM::writeSampleEfficiency(std::string file){
    std::ofstream fs;
    fs.open(file, std::ios::out);
    fs << "N rho random_variance episode_num update_params_num step_num" << std::endl;
    fs << N << " ";
    fs << rho << " ";
    fs << random_variance << " ";
    fs << episode_num << " ";
    fs << update_params_num << " ";
    fs << step_num << std::endl;
    fs.close();
}

LinearModel& CEM::getModel(){
    return *model;
}

CEM::CEM(){
    env = new EasyEnv();
}
CEM::~CEM(){}
