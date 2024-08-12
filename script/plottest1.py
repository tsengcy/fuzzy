import numpy as np
import matplotlib.pyplot as plt


if __name__ == "__main__":
    filename = './data/test1.txt'

    data = np.loadtxt(filename)

    plt.figure()
    plt.plot(range(data.shape[0]), data)
    plt.savefig(filename + ".png")