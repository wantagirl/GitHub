#coding:utf-8
import os

def dirs(path):
	"""show input path and show its sub-paths recursively"""
	#return false if input is not a path
	if False == os.path.isdir(path):
		print path+" is not a path"
		return False
	#return list of paths
	l = []
	for i in os.walk(path):
		l.append(i[0])
	return l

def files(path):
	"""show all files under input path(include its sub-paths)"""
	#return false if input is not a path
	if False == os.path.isdir(path):
		print path+" is not a path"
		return False
	#return list of files
	l = []
	for i in os.walk(path):
		for f in i[2]:
			l.append(i[0]+os.sep+f)
	return l

def ext_filter(fl,ext):
	"""return fn in fl with specified extension name, case sensitive"""
	l = []
	for fn in fl:
		if os.path.splitext(fn)[1] == ext:
			l.append(fn)
	return l

def is_fn_repeat(fl):
	l = []
	for fn in fl:
		f = os.path.basename(fn)
		if f not in l:
			l.append(f)
		else:
			print f+" exists!"
			return True
	return False

#**********************************
#environment
cc = "mingw32-make.exe"

#paths
base_path = os.getcwd()
src_path = os.getcwd()+os.sep+"src"
prj_path = os.getcwd()+os.sep+"prj"
tmp_path = os.getcwd()+os.sep+"tmp"

#target
target = "main.exe"

#**********************************
#clean tmp folder
for fn in os.listdir(tmp_path): 
	os.remove(os.path.join(tmp_path, fn))

#exit if there is no repeat file name
src = files(src_path)
src = ext_filter(src,".c") + ext_filter(src,".h")
if True == is_fn_repeat(src):
	print "repeat fn, abort"
	exit()

#copy src files and prj files into tmp folder
for fn in os.listdir(prj_path):
	open(os.path.join(tmp_path, fn), "wb").write(open(os.path.join(prj_path, fn), "rb").read())
for fn in src:
	open(os.path.join(tmp_path, os.path.basename(fn)), "wb").write(open(fn, "rb").read())

#make
os.chdir(tmp_path)
os.system(cc)
