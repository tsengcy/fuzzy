import numpy as np
import matplotlib.pyplot as plt


if __name__ == "__main__":
    filename = './data/test2.txt'

    data = np.loadtxt(filename)

    plt.figure(figsize=(9,3))
    plt.plot(data[:, 0], data[:, 1], label='1')
    plt.plot(data[:, 0], data[:, 2], 'g', label='2')
    plt.plot(data[:, 0], data[:, 3], 'r--', label='Tnorm')
    plt.xlim([-15, 15])
    plt.ylim([-0.05,1.2])
    plt.legend()
    plt.savefig(filename + "1.png")


    plt.figure(figsize=(9,3))
    plt.plot(data[:, 0], data[:, 3])
    plt.xlim([-15, 15])
    plt.ylim([0,1])
    plt.savefig(filename + "2.png")