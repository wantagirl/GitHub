from xml.dom import minidom
xmldoc = minidom.parse('test.xml') 

#print xmldoc
#print xmldoc.toxml()
#print xmldoc.childNodes
#print xmldoc.childNodes[0].childNodes	#\r\n:text element
print xmldoc.firstChild.childNodes[1].childNodes[1]

print '\xf1'.encode('latin-1')
