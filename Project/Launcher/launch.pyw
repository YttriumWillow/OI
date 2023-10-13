from ctypes import *  # 获取屏幕上某个坐标的颜色
from random import *
from time import *

CHKNUM = 100
PERCENT = 0.8


 
gdi32 = windll.gdi32
user32 = windll.user32
    
def getColor(x, y):
    hdc = user32.GetDC(None)  # 获取颜色值
    pixel = gdi32.GetPixel(hdc, x, y)  # 提取RGB值
    r = pixel & 0x0000ff
    g = (pixel & 0x00ff00) >> 8
    b = pixel >> 16
    return [r, g, b]
def getPixel():
    return user32.GetSystemMetrics(0), user32.GetSystemMetrics(1)

def newget():
    pass

def iswhite(x, y):
    return sum(getColor(x, y)) > 730

def launch():
    print("Genshin Impact!!!")

if __name__ == '__main__':
    pixel = getPixel()
    while True:
        hdc = user32.GetDC(None)
        for i in range(CHKNUM):
            cnt = 0
            x = randint(0, pixel[0])
            y = randint(0, pixel[1])
            pixel = gdi32.GetPixel(hdc, x, y)  # 提取RGB值
            r = pixel & 0x0000ff
            g = (pixel & 0x00ff00) >> 8
            b = pixel >> 16
            if (r + g + b > 730):
                cnt += 1
            if (cnt / CHKNUM > PERCENT):
                launch()
        sleep(0.1)