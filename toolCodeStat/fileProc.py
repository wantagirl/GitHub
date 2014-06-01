#coding:utf-8
import os

def line_count(fn):
	"""count lines in file with specified fn"""
	#return false if input is not a file
	if False == os.path.isfile(fn):
		print fn+" is not a file"
		return False
	#count lines in file with specified fn
	return len(open(fn).readlines())

def char_count(fn):
	"""count chars in file with specified fn"""
	#return false if input is not a file
	if False == os.path.isfile(fn):
		print fn+" is not a file"
		return False
	char = 0
	for line in open(fn).readlines():
		char += len(line.strip())
	return char

def word_count(fn):
	pass

def word_search(fn,rex):
	pass

def comment_count(fn):
	pass



if __name__ == '__main__':
	#print line_count("E:\\SourceForge\\test\\subdir1\\subdir11\\APALMml.c")
	print char_count("E:\\SourceForge\\test\\subdir1\\subdir11\\22")
