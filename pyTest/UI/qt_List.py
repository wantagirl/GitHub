# !/usr/bin/python
import sys
from PyQt4.QtGui import *
from PyQt4 import QtCore
 
class ListWidget(QMainWindow):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setWindowTitle('ListWidget')
        self.List = QListWidget(self)
        self.List.setSortingEnabled(1)#whether sort
        item = ['OaK','Banana','Apple','Orange','Grapes','Jayesh']
        listItem = []
        for lst in item:
            listItem.append(QListWidgetItem(lst))
        for i in range(len(listItem)):
            self.List.insertItem(i+1,listItem[i])
        self.setCentralWidget(self.List)
       
app = QApplication(sys.argv)
tb = ListWidget()
tb.show()
app.exec_()