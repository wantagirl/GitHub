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

def dirs_under(path):
	"""show sub-paths under input path, not recursively"""
	#return false if input is not a path
	if False == os.path.isdir(path):
		print path+" is not a path"
		return False
	#return list of paths
	for i in os.walk(path):
		if i[0] == path:
			return i[1]

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

def files_under(path):
	"""show files under input path, not recursively"""
	#return false if input is not a path
	if False == os.path.isdir(path):
		print path+" is not a path"
		return False
	#return list of paths
	for i in os.walk(path):
		if i[0] == path:
			return i[2]

def ext_filter(fl,ext):
	"""return fn in fl with specified extension name, case sensitive"""
	l = []
	for i in fl:
		if i.split(".")[-1] in ext:
			l.append(i)
	return l

if __name__ == '__main__':
	path = "E:\\linux-3.13.6"
	print dirs_under(path)
	print files_under(path)
	#print ext_filter(["12.c","22.d"],"c","s")