import sys

from PyQt4.QtCore import *
from PyQt4.QtGui import *
from PyQt4 import *#can not import this first


class MainWindow(QMainWindow):
    def __init__(self,parent=None):
        super(MainWindow,self).__init__(parent)
        #textedit
        self.textedit = QTextEdit()
        self.textedit.setText("This is a TextEdit!")
        #listwidget
        self.listwidget = QListWidget()
        self.listwidget.addItem("This\nis\na\nListWidget!")
        #treewidget
        self.treewidget = QTreeWidget()
        self.treewidget.setHeaderLabels(['This','is','a','TreeWidgets!'])
        
        #container
        splitter = QSplitter(self)
        splitter.addWidget(self.textedit)
        splitter.addWidget(self.listwidget)
        splitter.addWidget(self.treewidget)
        splitter.setOrientation(Qt.Vertical)
        self.setCentralWidget(splitter)


app = QtGui.QApplication(sys.argv)
sw = MainWindow()
sw.show()
app.exec_()