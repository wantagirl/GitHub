import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *
 
class MainWindow(QMainWindow):
    def __init__(self,parent=None):
        super(MainWindow,self).__init__(parent)
        self.status = self.statusBar()
        self.status.showMessage("This is StatusBar",5000)
        self.setWindowTitle("PyQt MianWindow")
      
def main():
    app = QApplication(sys.argv)
    #app.setWindowIcon(QIcon("./images/icon.png"))
    form = MainWindow()
    form.show()
    app.exec_()

main()