from pylab import *

t = arange(0, 10, 0.1)


s1 = 6000
s2 = 8000

ss1 = s1*1.2**t
ss2 = s2*1.2**t

plot(t, ss1, linewidth=1.0)
plot(t, ss2, linewidth=1.0)

xlabel('time (year)')
ylabel('salary (rmb)')
grid(True)
show()
