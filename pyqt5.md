_*multithread in pyqt5*_
```python
class MyWindow(QWidget):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("demo")
        self.resize(400,200)
        self.lable =QLabel("这是一个标签",self)
        self.lable.move(150,100)
        self.sum = Sum()    #实例化Sum类
        self.sum.start()    #开启线程
        self.show()

class Sum(QThread):
    def __init__(self):
        super().__init__()
        self.m = 0

    def run(self):
        while self.m < 100:
            self.m+=1
            print(self.m)
            time.sleep(1)
if __name__ == '__main__':
    app =QApplication(sys.argv)
    win = MyWindow()
    sys.exit(app.exec())
    
```
