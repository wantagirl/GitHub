# !/usr/bin/python
import sys
from PyQt4 import QtGui, QtCore

class SigSlot(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.setWindowTitle('signal & slot')
        lcd = QtGui.QLCDNumber(self)
        slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)
        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(lcd)
        vbox.addWidget(slider)
        self.setLayout(vbox)
        self.connect(slider, QtCore.SIGNAL('valueChanged(int)'), lcd, QtCore.SLOT('display(int)'))
        #sender,signal,receiver,slot
        self.resize(250, 150)

app = QtGui.QApplication(sys.argv)
qd = SigSlot()
qd.show()
sys.exit(app.exec_())