#! /usr/bin/env python
#coding=utf-8

import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class FontPropertiesDlg_Modal(QDialog):
    def __init__(self, parent=None):
        super(FontPropertiesDlg_Modal, self).__init__(parent)
        FontStyleLabel = QLabel("Font:")
        FontSizeLabel = QLabel("Size:")
        self.FontstyleComboBox = QComboBox()       #+self for external access
        self.FontstyleComboBox.addItems(["Arial", "Yahei", "NTR", "Courier"])
        self.FontSizeSpinBox = QSpinBox()
        self.FontSizeSpinBox.setRange(0, 90)
        self.FontEffectCheckBox =QCheckBox("Effect")
        okButton = QPushButton("Ok")
        cancelButton = QPushButton("Cancel")
        
        buttonLayout = QHBoxLayout()
        buttonLayout.addStretch()
        buttonLayout.addWidget(okButton)
        buttonLayout.addWidget(cancelButton)
        layout = QGridLayout()
        layout.addWidget(FontStyleLabel, 0, 0)
        layout.addWidget(self.FontstyleComboBox, 0, 1)
        layout.addWidget(FontSizeLabel, 1, 0)
        layout.addWidget(self.FontSizeSpinBox, 1, 1)
        layout.addWidget(self.FontEffectCheckBox,1,2)
        layout.addLayout(buttonLayout, 2,0)
        self.setLayout(layout)
        self.setWindowTitle("FontPropertiesDlg")
        #standard
        self.connect(okButton,SIGNAL("clicked()"),self,SLOT("accept()"))
        self.connect(cancelButton,SIGNAL("clicked()"),self,SLOT("reject()"))

class FontPropertiesDlg_Modalless(QDialog):
    def __init__(self,format,parent=None):
        super(FontPropertiesDlg_Modalless, self).__init__(parent)
        self.format=format
        FontStyleLabel = QLabel("Font:")
        FontSizeLabel = QLabel("Size:")
        self.FontstyleComboBox = QComboBox()       #+self for external access
        self.FontstyleComboBox.addItems(["Arial", "Yahei", "NTR", "Courier"])
        self.FontSizeSpinBox = QSpinBox()
        self.FontSizeSpinBox.setRange(0, 90)
        self.FontEffectCheckBox =QCheckBox("Effect")
        okButton = QPushButton("Ok")
        cancelButton = QPushButton("Cancel")
        
        buttonLayout = QHBoxLayout()
        buttonLayout.addStretch()
        buttonLayout.addWidget(okButton)
        buttonLayout.addWidget(cancelButton)
        layout = QGridLayout()
        layout.addWidget(FontStyleLabel, 0, 0)
        layout.addWidget(self.FontstyleComboBox, 0, 1)
        layout.addWidget(FontSizeLabel, 1, 0)
        layout.addWidget(self.FontSizeSpinBox, 1, 1)
        layout.addWidget(self.FontEffectCheckBox,1,2)
        layout.addLayout(buttonLayout, 2,0)
        self.setLayout(layout)
        self.setWindowTitle("FontPropertiesDlg")
        #standard
        self.connect(okButton,SIGNAL("clicked()"),self.apply)
        self.connect(cancelButton,SIGNAL("clicked()"),self,SLOT("reject()"))
    def apply(self):
        self.format["fontstyle"] = self.FontstyleComboBox.currentText()
        self.format["fontsize"] = self.FontSizeSpinBox.value()
        self.format["fonteffect"] = self.FontEffectCheckBox.isChecked()
        self.emit(SIGNAL("changed"))


class FontPropertiesDlg_Live(QDialog):
    def __init__(self,format,callback,parent=None):
        super(FontPropertiesDlg_Live, self).__init__(parent)
        self.format = format
        self.callback = callback
        FontStyleLabel = QLabel("Font:")
        FontSizeLabel = QLabel("Size:")
        self.FontstyleComboBox = QComboBox()       #+self for external access
        self.FontstyleComboBox.addItems(["Arial", "Yahei", "NTR", "Courier"])
        self.FontSizeSpinBox = QSpinBox()
        self.FontSizeSpinBox.setRange(0, 90)
        self.FontEffectCheckBox =QCheckBox("Effect")
            
        layout = QGridLayout()
        layout.addWidget(FontStyleLabel, 0, 0)
        layout.addWidget(self.FontstyleComboBox, 0, 1)
        layout.addWidget(FontSizeLabel, 1, 0)
        layout.addWidget(self.FontSizeSpinBox, 1, 1)
        layout.addWidget(self.FontEffectCheckBox,1,2)
        self.setLayout(layout)
 
        self.connect(self.FontstyleComboBox,SIGNAL("itemSelected"),self.apply)  #uncatchable?
        self.connect(self.FontEffectCheckBox,SIGNAL("toggled(bool)"), self.apply)
        self.connect(self.FontSizeSpinBox,SIGNAL("valueChanged(int)"), self.apply)
        self.setWindowTitle("FontPropertiesDlg")
 
    def apply(self):
        self.format["fontstyle"] = self.FontstyleComboBox.currentText()
        self.format["fontsize"] = self.FontSizeSpinBox.value()
        self.format["fonteffect"] = self.FontEffectCheckBox.isChecked()
        self.callback()

class MainDialog(QDialog):
    def __init__(self,parent=None):
        super(MainDialog,self).__init__(parent)
        self.FontPropertiesDlg=None
        self.format=dict(fontstyle="Arial",fontsize=1,fonteffect=False)
        FontButton1 = QPushButton("Set Font(Modal)")
        FontButton2 = QPushButton("Set Font(Modalless)")
        FontButton3 = QPushButton("Set Font(Live)")
        self.label = QLabel("Default")
        layout = QGridLayout()
        layout.addWidget(FontButton1,0,0)
        layout.addWidget(FontButton2,0,1)
        layout.addWidget(FontButton3,0,2)
        layout.addWidget(self.label)
        self.setLayout(layout)
        self.connect(FontButton1,SIGNAL("clicked()"),self.FontModalDialog)
        self.connect(FontButton2,SIGNAL("clicked()"),self.FontModallessDialog)
        self.connect(FontButton3,SIGNAL("clicked()"),self.FontLiveDialog)
        
        self.setWindowTitle("Modal and Modalless Dialog")
        self.updataData()
 
    def updataData(self):
        self.label.setText("Font:%s<br>Size:%d<br>Effect:%s" %(self.format["fontstyle"],self.format["fontsize"],self.format["fonteffect"]))#<br> \n
    
    def FontModalDialog(self):
        dialog = FontPropertiesDlg_Modal(self)
        dialog.exec_()
        #if dialog.exec_():  #protect
            #print dialog.exec_()
        self.format["fontstyle"] = dialog.FontstyleComboBox.currentText()
        self.format["fontsize"] = dialog.FontSizeSpinBox.value()
        self.format["fonteffect"] = dialog.FontEffectCheckBox.isChecked()
        self.updataData()
        
    def FontModallessDialog(self):
        dialog = FontPropertiesDlg_Modalless(self.format,self)
        self.connect(dialog,SIGNAL("changed"),self.updataData)
        dialog.show()
    
    def FontLiveDialog(self):
        if self.FontPropertiesDlg is None:
            self.FontPropertiesDlg = FontPropertiesDlg_Live(self.format,self.updataData,self)
        self.FontPropertiesDlg.show()
        self.FontPropertiesDlg.raise_()
        self.FontPropertiesDlg.activateWindow()
 
app = QApplication(sys.argv)
font= MainDialog()
font.show()
app.exec_()

#smart

