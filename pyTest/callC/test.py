from ctypes import *

test = CDLL('test.so')

print test.proc_num(1,2)
#print test.proc_num(c_int(1),c_int(2))	#standard way

#modify buf method 1
print c_char_p(test.proc_str1("vcx")).value
#modify buf method 2
s = create_string_buffer("xcv")
test.proc_str2(s)
print s.value