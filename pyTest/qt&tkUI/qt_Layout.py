# !/usr/bin/python
 
import sys
from PyQt4 import QtGui
 
class BoxLayout(QtGui.QWidget):
    def __init__(self,parent=None):
        QtGui.QWidget.__init__(self,parent)

        ok = QtGui.QPushButton('OK')
        cancel = QtGui.QPushButton('Cancel')
 
        hbox = QtGui.QHBoxLayout()
        hbox.addStretch(100)#stretch factor???
        hbox.addWidget(ok)
        hbox.addWidget(cancel)
 
        vbox = QtGui.QVBoxLayout()
        vbox.addStretch(100)#stretch factor???
        vbox.addLayout(hbox)
 
        self.setLayout(vbox)
        self.resize(300,150)
        self.setWindowTitle('boxlayout')

class GridLayout(QtGui.QWidget):
    def __init__(self,parent=None):
        QtGui.QWidget.__init__(self,parent)
  
        names = ['Cls','Bck','Close','7','8','9','/',
                 '4','5','6','#','1','2','3','-','0',
                 '.','=','+']
        grid = QtGui.QGridLayout()
        j = 0
        pos = [
            (0,0),(0,1),(0,2),(0,3),
            (1,0),(1,1),(1,2),(1,3),
            (2,0),(2,1),(2,2),(2,3),
            (3,0),(3,1),(3,2),(3,3),
            (4,0),(4,1),(4,2),(4,3)
            ]
        for i in names:
            button = QtGui.QPushButton(i)
            if j == 2:
                grid.addWidget(QtGui.QLabel(''),0,2)
            else:
                grid.addWidget(button,pos[j][0],pos[j][1])
            j = j+1
        self.setLayout(grid)
        self.setWindowTitle('grid layout')

class GridLayout2(QtGui.QWidget):#a component of multi-lines
    def __init__(self,parent=None):
        QtGui.QWidget.__init__(self,parent)
 
        self.setWindowTitle('grid layout2')
 
        title = QtGui.QLabel('Tltle')
        author = QtGui.QLabel('Author')
        review = QtGui.QLabel('Review')
 
        titleEdit = QtGui.QLineEdit()
        authorEdit = QtGui.QLineEdit()
        reviewEdit = QtGui.QTextEdit()
 
        grid = QtGui.QGridLayout()
        grid.setSpacing(10) #unit: pixel
 
        grid.addWidget(title,1,0)
        grid.addWidget(titleEdit,1,1)
 
        grid.addWidget(author,2,0)
        grid.addWidget(authorEdit,2,1)
 
        grid.addWidget(review,3,0)
        grid.addWidget(reviewEdit,3,1,5,1)  #multi-line component
 
        self.setLayout(grid)
        self.resize(350,300)
        
app = QtGui.QApplication(sys.argv)
#qb = BoxLayout()
qb = GridLayout2()
qb.show()
sys.exit(app.exec_())
