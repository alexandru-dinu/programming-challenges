import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation
from matplotlib.colors import ListedColormap, Normalize
from scipy.signal import convolve2d


def main():
    with open("input") as fp:
        coords = np.array(
            [
                [i, j]
                for i, row in enumerate(fp.readlines())
                for j, z in enumerate(row)
                if z == "@"
            ]
        )

    rows = coords[:, 0].max() + 1
    cols = coords[:, 1].max() + 1

    mat = np.zeros((rows, cols), dtype=int)
    mat[coords[:, 0], coords[:, 1]] = 1

    p2 = 0
    hist = [(mat.copy(), p2)]

    while True:
        nei = convolve2d(mat, np.ones((3, 3)), mode="same") - 1
        rem = (mat == 1) & (nei < 4)
        if rem.sum() == 0:
            break
        mat &= nei >= 4
        p2 += rem.sum()

        hist += [(mat.copy(), p2)]

    colors = ["#00203F", "#ADEFD1"]
    fig, ax = plt.subplots(facecolor=colors[0])
    plt.axis("off")
    norm = Normalize(vmin=0, vmax=1)
    im = ax.imshow(hist[0][0], cmap=ListedColormap(colors), norm=norm)

    def update(frame):
        m, r = hist[frame]
        im.set_array(m)
        ax.set_title(f"Iteration: {frame}. Removed: {r:,d}", color=colors[1])
        return [im]

    ani = FuncAnimation(fig, update, frames=len(hist), interval=100, blit=True)
    ani.save("progress.gif", writer="pillow")


if __name__ == "__main__":
    main()
