import numpy as np 
import matplotlib.pyplot as plt 
import matplotlib.animation as animation

pinocho=np.loadtxt("datos.dat")

N=len(pinocho[0])

x=np.linspace(0,1,N)

fig, ax = plt.subplots()
ax.grid()
ln, = plt.plot(x,pinocho[0])

def init():  
    ax.set_xlabel("Posicion [Metros]")
    ax.set_ylabel("U")
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.5, 0.5)
    return ln,

def animate(i):
    ln.set_ydata(pinocho[i])
    ax.set_title("Tiempo: "+ str("{0:.2f}".format(2*i/(N-1)))+ " segundos")
    return ln,

ani = animation.FuncAnimation(fig, animate, init_func=init, interval=100,frames=range(N), blit=True,repeat=True)
ani.save("CINCO.gif",fps=10)



