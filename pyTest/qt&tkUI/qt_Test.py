# !/usr/bin/python
import sys
from PyQt4.QtGui import *
class TableWidget(QMainWindow):
    def __init__(self,parent=None):
        QWidget.__init__(self,parent)
        self.setWindowTitle('TableWidget')
        self.table = QTableWidget(10,6)
        self.table.setHorizontalHeaderLabels(['SUN','MON','TUE','WED','THU','FIR','SAT'])
        
        self.setCentralWidget(self.table)
        

#insert an item        
#self.newItem = QTableWidgetItem('Item')
#self.table.setItem(1,2,self.newItem)

#clear all
#QTableWidget.clear(self)

#clear items only
#QTableWidget.clearContents(self)

#insert column
#QTableWidget.insertColumn(self, int column)

#insert row
#QTableWidget.insertRow(self, int row)

#del column
#QTableWidget.removeColumn(self, int column)

#del row
#QTableWidget.removeRow(self, int row)

#hide grid
#QTableView.setShowGrid (self, bool show)

#hide/show col/row
#hideRow(),hideColumn(),showRow(),showColumn()

#hide 1st row
#self.table.verticalHeader().setVisible(False)

#editable
#self.table.setEditTriggers(QTableWidget.NoEditTriggers)

#select row/col?
#self.table.setSelectionBehavior(QTableWidget.SelectRows)

#multi/single selection
#self.table.setSelectionMode(QTableWidget.SingleSelection)

#change color one row after another
#self.table.setAlternatingRowColors(True)

app = QApplication(sys.argv)
tb = TableWidget()
tb.show()
app.exec_()