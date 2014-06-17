from PyQt4.QtGui import *  
from PyQt4.QtCore import *  
import testui  
import sys  

class TestDialog(QDialog):  
    def __init__(self,parent=None):  
        super(TestDialog,self).__init__(parent)  
          
        firstUi=testui.Ui_Dialog()  
  
    

app=QApplication(sys.argv)  
dialog=TestDialog()   
dialog.show()  
app.exec_()  