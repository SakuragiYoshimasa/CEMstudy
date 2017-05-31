# coding: utf-8
import os
import glob
import numpy as np
import pandas as pd
from scipy import stats
from pandas import DataFrame

if __name__ == '__main__':
    # rv = {0.5, 1.0, 1.5, 2.0};
    files = glob.glob('./Experiment/Results/ChangeRV*/0*_RV_se.csv')
    rv_50_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rv_50_data = pd.concat([rv_50_data, data])

    files = glob.glob('./Experiment/Results/ChangeRV*/1*_RV_se.csv')
    rv_100_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rv_100_data = pd.concat([rv_100_data, data])

    files = glob.glob('./Experiment/Results/ChangeRV*/2*_RV_se.csv')
    rv_150_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rv_150_data = pd.concat([rv_150_data, data])

    files = glob.glob('./Experiment/Results/ChangeRV*/3*_RV_se.csv')
    rv_200_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rv_200_data = pd.concat([rv_200_data, data])

    print('episode_num')
    print(np.mean(rv_50_data['episode_num']))
    print(np.mean(rv_100_data['episode_num']))
    print(np.mean(rv_150_data['episode_num']))
    print(np.mean(rv_200_data['episode_num']))

    f_val, p_val = stats.f_oneway(rv_50_data['episode_num'], rv_100_data['episode_num'],rv_150_data['episode_num'], rv_200_data['episode_num'])
    print('episode_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('update_params_num')
    print(np.mean(rv_50_data['update_params_num']))
    print(np.mean(rv_100_data['update_params_num']))
    print(np.mean(rv_150_data['update_params_num']))
    print(np.mean(rv_200_data['update_params_num']))

    f_val, p_val = stats.f_oneway(rv_50_data['update_params_num'], rv_100_data['update_params_num'],rv_150_data['update_params_num'], rv_200_data['update_params_num'])
    print('update_params_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('step_num')
    print(np.mean(rv_50_data['step_num']))
    print(np.mean(rv_100_data['step_num']))
    print(np.mean(rv_150_data['step_num']))
    print(np.mean(rv_200_data['step_num']))

    f_val, p_val = stats.f_oneway(rv_50_data['step_num'], rv_100_data['step_num'],rv_150_data['step_num'], rv_200_data['step_num'])
    print('step_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)
