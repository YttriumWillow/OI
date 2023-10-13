from ctypes import *  # 获取屏幕上某个坐标的颜色
from random import *
from time import *
import os

CHKNUM = 100
PERCENT = 0.8
lstgo = 0.0
canlaunch = 1
 
gdi32 = windll.gdi32
user32 = windll.user32
    
def getColor(x, y):
    hdc = user32.GetDC(None)
    pixel = gdi32.GetPixel(hdc, x, y)
    r = pixel & 0x0000ff
    g = (pixel & 0x00ff00) >> 8
    b = pixel >> 16
    return [r, g, b]

def getPixel():
    return user32.GetSystemMetrics(0), user32.GetSystemMetrics(1)

def iswhite(x, y):
    return sum(getColor(x, y)) > 730

def launch(): 
    global lstgo, canlaunch
    if canlaunch == 0:
        return
    lstgo = time()
    canlaunch = 0
    os.system("start https://ys.mihoyo.com/cloud/?autobegin=1&utm_source=default")
    os.system("start https://ys.mihoyo.com/ebd79f8e-5223-46a3-8083-81437aef62db")
    print("Genshin Impact!!!")

if __name__ == '__main__':
    size = getPixel()
    st = time()
    while True:
        hdc = user32.GetDC(None)
        cnt = 0
        
        for i in range(CHKNUM):
            x = randint(0, size[0])
            y = randint(0, size[1])
            
            pixel = gdi32.GetPixel(hdc, x, y)  # 提取RGB值
            r = pixel & 0x0000ff
            g = (pixel & 0x00ff00) >> 8
            b = pixel >> 16
            if (r + g + b > 700):
                cnt += 1
        
        if (time() - lstgo):
            canlaunch = 1
        
        fuck = cnt / CHKNUM
        print(fuck, end = ':')
        if (fuck > PERCENT):
            launch()
        else:
            print("NaN")
        sleep(0.06)