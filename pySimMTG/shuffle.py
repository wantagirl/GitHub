land = 24
nonland = 36

nl = []
for i in range(nonland):
	nl.append(0)#0=nonland
l = []
for i in range(land):
	l.append(1)#1=land
lib = []


#=======================================
#splitH: half half
#splitT: take out
#splitN: n-pile
#splitA: nonland, land, library(after game)

#merge1: put together(in order)
#merge2: insert(single, multi)
#
#=======================================
#insert: splitH+merge2
#n-pile: splitN+merge1
#out and back: splitT+merge1
#
#=======================================
#evaluate: first-hand nice, draw nice

import random

def splitH(deck):
	#func params
	lr, rr = 0.5, 2
	#
	h1Size = 0
	r = h1Size/float(len(deck)-h1Size)
	while r < lr or r > rr:
		h1Size = random.randint(1, len(deck)-1)
		r = h1Size/float(len(deck)-h1Size)
	return deck[:h1Size], deck[h1Size:]#cardinal as ordinal

#print splitH([1,2,3,4,5])

def splitT(deck):
	pass


#import matplotlib.pyplot as plt
#plt.plot(l,'ro')
#plt.show()