"""
Tkinter's 15 Components
//
Menu	 The Menu widget is used to provide various commands to a user. These commands are contained inside Menubutton.

//
Frame	 The Frame widget is used as a container widget to organize other widgets.
Canvas	 The Canvas widget is used to draw shapes, such as lines, ovals, polygons, and rectangles, in your application.

//
Label	 The Label widget is used to provide a single-line caption for other widgets. It can also contain images.
LabelFrame	 A labelframe is a simple container widget. Its primary purpose is to act as a spacer or container for complex window layouts.

//
Button	 The Button widget is used to display buttons in your application.
Checkbutton	 The Checkbutton widget is used to display a number of options as checkboxes. The user can select multiple options at a time.
Radiobutton	 The Radiobutton widget is used to display a number of options as radio buttons. The user can select only one option at a time.
Menubutton	 The Menubutton widget is used to display menus in your application.

//
Entry	 The Entry widget is used to display a single-line text field for accepting values from a user.
Spinbox	 The Spinbox widget is a variant of the standard Tkinter Entry widget, which can be used to select from a fixed number of values.
Text	 The Text widget is used to display text in multiple lines.
Listbox	 The Listbox widget is used to provide a list of options to a user.
Scrollbar	 The Scrollbar widget is used to add scrolling capability to various widgets, such as list boxes.
Scale	 The Scale widget is used to provide a slider widget.

Message	 The Message widget is used to display multiline text fields for accepting values from a user.
tkMessageBox	 This module is used to display message boxes in your applications.

Toplevel	 The Toplevel widget is used to provide a separate window container.
PanedWindow	 A PanedWindow is a container widget that may contain any number of panes, arranged horizontally or vertically.
"""





from Tkinter import *

        
def donothing():
	pass


class StatusBar(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.label = Label(self, bd=1, relief=SUNKEN, anchor=W)
        self.label.pack(fill=X)
    def set(self, format, *args):
        self.label.config(text=format % args)
        self.label.update_idletasks()
    def clear(self):
        self.label.config(text="")
        self.label.update_idletasks()


root = Tk()
root.title("hello,world!")
root.geometry('400x300')

#Menubar and Menu
menubar = Menu(root)
menu1 = Menu(menubar, tearoff=0)#menu for menubar
menu1.add_command(label="Opt1", command=donothing)
menu1.add_separator()
menu1.add_command(label="Exit", command=root.quit)
menubar.add_cascade(label="Menu1", menu=menu1)
menu2 = Menu(menubar, tearoff=0)#menu for menubar
menu2.add_command(label="Opt2", command=donothing)
menu2.add_command(label="Opt3", command=donothing)
menubar.add_cascade(label="Menu2", menu=menu2)
root.config(menu=menubar)
#Frame, suggest not use
#Label
label = Label(root, text="123")
label.grid()


root.mainloop()
