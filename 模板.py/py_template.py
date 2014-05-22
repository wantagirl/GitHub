import numpy as np

import matplotlib.pyplot as plt
import matplotlib.cm as cm



#draw bitmap
#random data: how to calculate pi, darker
X = np.random.rand(10,20)
X[0,0] = 10
plt.imshow(X, cmap=cm.gray, interpolation = 'nearest')
plt.show()
