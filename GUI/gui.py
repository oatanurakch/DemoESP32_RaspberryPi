from PyQt5 import QtCore, QtGui, QtWidgets
import sys
import serial
from pygui import Ui_MainWindow
app = QtWidgets.QApplication(sys.argv)
MainWindow = QtWidgets.QMainWindow()

ser = serial.Serial('COM3', 115200, timeout = 2)

class _myui(Ui_MainWindow):
    def __init__(self):
        super().setupUi(MainWindow)
        self.state()

        self.tmtx1 = QtCore.QTimer()
        self.tmtx1.timeout.connect(self.ReadData)
        self.tmtx1.start(1000)

        self.tmtx2 = QtCore.QTimer()
        self.tmtx2.timeout.connect(self.ReadData)
        self.tmtx2.start(500)

    
    def state(self):
        self.onsw.clicked.connect(self.write)
        self.offsw.clicked.connect(self.write0)

    def write(self):
        ser.write('1'.encode())

    def write0(self):
        ser.write('0'.encode())

    def ReadData(self):
        self.temp = ser.readline().decode().strip()
        self._humid = ser.readline().decode().strip()
        self.TempDS.setText(self.temp)
        self.humid.setText(self._humid)


obj = _myui()
MainWindow.show()
sys.exit(app.exec_())