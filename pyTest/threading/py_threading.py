import threading
import time

def f(tn):
	count = 0
	while count < 5:
		print tn
		time.sleep(1)
		count += 1
def mk_thread(tn):
	return threading.Thread(name=tn,target=f,args=(tn,))


t0 = mk_thread('t0')
t1 = mk_thread('t1')

t1.setDaemon(True)
t0.start()
time.sleep(3)
t1.start()


#print 't0 alive:',t0.isAlive()
#print 't1 alive:',t1.isAlive()