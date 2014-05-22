#!/usr/bin/env python
#coding=utf-8
 
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *                    
 
class MainWindow(QMainWindow):
    def __init__(self,parent=None):
        super(MainWindow,self).__init__(parent)
        fileNewAction=QAction(QIcon("./filenew.png"),"&New",self)   #underline N
        fileNewAction.setToolTip("ToolTip:Create a new file")
        fileNewAction.setStatusTip("SB:Create a new file")
        self.connect(fileNewAction,SIGNAL("triggered()"),self.fileNew)
        
        fileNewAction.setShortcut(QKeySequence.New)     #key
 
        fileMenu = self.menuBar().addMenu("&File") #menu
        fileMenu.addAction(fileNewAction)
 
        filetoolbar = self.addToolBar("File")   #button
        filetoolbar.addAction(fileNewAction)
        #    
        self.status = self.statusBar()
        self.status.showMessage("This is StatusBar",5000)
        self.setWindowTitle("PyQt MianWindow")
      
    def fileNew(self):
        self.status.showMessage("You have created a new file!",9000)
    #use funcs like this to encapsule QAction: def createAction(self,slot=None,shortcut=None,icon=None,tip=None,checkable=False,text,signal="triggered()")

def main():
    app = QApplication(sys.argv)
    app.setApplicationName("PyQt MianWindow")
    #app.setWindowIcon(QIcon("./images/icon.png"))
    form = MainWindow()
    form.show()
    app.exec_()
 
main()