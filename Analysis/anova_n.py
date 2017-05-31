# coding: utf-8
import os
import glob
import numpy as np
import pandas as pd
from scipy import stats
from pandas import DataFrame
import matplotlib.pyplot as plt

if __name__ == '__main__':

    #N ={50, 100, 150, 200};
    files = glob.glob('./Experiment/Results/ChangeN*/0*_N_se.csv')
    n_50_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        n_50_data = pd.concat([n_50_data, data])

    files = glob.glob('./Experiment/Results/ChangeN*/1*_N_se.csv')
    n_100_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        n_100_data = pd.concat([n_100_data, data])

    files = glob.glob('./Experiment/Results/ChangeN*/2*_N_se.csv')
    n_150_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        n_150_data = pd.concat([n_150_data, data])

    files = glob.glob('./Experiment/Results/ChangeN*/3*_N_se.csv')
    n_200_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        n_200_data = pd.concat([n_200_data, data])

    print('episode_num')
    print(np.mean(n_50_data['episode_num']))
    print(np.mean(n_100_data['episode_num']))
    print(np.mean(n_150_data['episode_num']))
    print(np.mean(n_200_data['episode_num']))

    f_val, p_val = stats.f_oneway(n_50_data['episode_num'], n_100_data['episode_num'],n_150_data['episode_num'], n_200_data['episode_num'])
    print('episode_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('update_params_num')
    print(np.mean(n_50_data['update_params_num']))
    print(np.mean(n_100_data['update_params_num']))
    print(np.mean(n_150_data['update_params_num']))
    print(np.mean(n_200_data['update_params_num']))

    f_val, p_val = stats.f_oneway(n_50_data['update_params_num'], n_100_data['update_params_num'],n_150_data['update_params_num'], n_200_data['update_params_num'])
    print('update_params_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('step_num')
    print(np.mean(n_50_data['step_num']))
    print(np.mean(n_100_data['step_num']))
    print(np.mean(n_150_data['step_num']))
    print(np.mean(n_200_data['step_num']))

    f_val, p_val = stats.f_oneway(n_50_data['step_num'], n_100_data['step_num'],n_150_data['step_num'], n_200_data['step_num'])
    print('step_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)


    fig, axs = plt.subplots(ncols=3, figsize=(12,3))
    labels = ['episode_num', 'update_params_num', 'step_num']
    x = [50, 100, 150, 200]
    for ax, label in zip(axs, labels):
        y = [np.mean(n_50_data[label]), np.mean(n_100_data[label]), np.mean(n_150_data[label]), np.mean(n_200_data[label])]
        ax.plot(x, y, color='red', marker='o')
        ax.set_xlabel('N')
        ax.set_ylabel('mean of ' + label)

    fig.subplots_adjust(left=0.075, bottom=0.15, right=0.95, top=0.95, wspace=0.4, hspace=0.3)

    plt.show()
