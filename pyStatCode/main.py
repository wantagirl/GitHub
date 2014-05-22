#coding:utf-8
import pathwalk
import fileProc


def prj_stat(prj_path,*ext):
	fl = pathwalk.files(prj_path)
	#must have ext list
	if(0 == len(ext)):
		print "no ext specified"
		return
	l = pathwalk.ext_filter(fl,ext)
	lines = 0
	char = 0
	for f in l:
		lines += fileProc.line_count(f)
		char += fileProc.char_count(f)
	print "lines:",lines
	print "chars:",char

if __name__ == '__main__':
	prj_path = "E:\\linux-3.13.6"
	print "start path:",prj_path
	prj_stat(prj_path,"c","C","h","H")