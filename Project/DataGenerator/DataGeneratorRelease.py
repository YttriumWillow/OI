import os
import sys
import time
import random
import threading as thr
import subprocess as subpcs
import multiprocessing as mulpsc
from threading import Thread

from math import *

globalCompileOptions = ["-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456"]
    
class Commander:                    # 命令执行器, 通过 Commader(mainProcess, *para) 构造, 传入 主程序 和 附加参数, 通过 perform 方法执行
    mainProcess = ""
    parameter = []
    def __init__(self, _mainProcess, *para):
        self.mainProcess = _mainProcess
        self.parameter = para
    def getCmd(self):
        return self.mainProcess + " " + " ".join(self.parameter)
    def summary(self, info):
        if len(info) > 60:
            return info[0:60] + "..."
        else:
            return info
    def perform(self):
        cmd = self.getCmd()
        INFO("Performed a Command: " + self.summary(cmd))
        runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
        return runResult.communicate()[0].decode("GBK")
class ComplieCommander(Commander):  # 特定的编译命令执行器, 通过 ComplieCommander(fileName, *para) 构造, 编译 fileName.cpp 文件
    fileName = ""
    def __init__(self, _fileName, *para):
        self.mainProcess = "g++"
        self.fileName = _fileName
        basicLine = [_path + _fileName + ".cpp", "-o", _path + _fileName]
        basicLine.extend(para)
        self.parameter = basicLine

class TestPoint:                    # 测试点, 传入测试点编号和数据构造参数(若 Generator 可传参数), 通过以下提供的方法生成测试文件
    case = 0
    runArgs = ""
    def __init__(self, _case, _args):
        self.case = _case
        self.runArgs = _args
    def genData(self):          # 生成数据命令
        cmd = "gen " + self.runArgs + " > " + probName + str(self.case) + ".in" 
        runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
        
        INFO("Generated #" + str(self.case) + " -args=\"" + self.runArgs + "\"")
        response = runResult.communicate()[0].decode("GBK")
        if response != "":
            WARNING("#" + str(self.case) + "'s generator has found an unexpected response: " + response) 
    def genAnswer(self):        # 生成答案命令
        startTick = time.time()
        cmd = probName + " < " + probName + str(self.case) + ".in" + " > " + probName + str(self.case) + ".ans"
        runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
        endTick = time.time()
        useTime = float(endTick - startTick) * 1000.0
        
        response = runResult.communicate()[0].decode("GBK")
        INFO("Answered #" + str(self.case) + " Time: {:.1f} ms".format(useTime))
        if response != "":
            WARNING("#" + str(self.case) + "'s answer program has found an unexpected response: " + response)
        return useTime
    def genCase(self):    # 调用数据生成器，生成一组样例 {fileName}_{case}.in 和 {fileName}_{case}.ans
        self.genData()
        self.genAnswer()
    def genInvalid(self):
        startTick = time.time()
        cmd = "invsol < " + probName + str(self.case) + ".in" + " > " + probName + str(self.case) + ".out"
        runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
        endTick = time.time()
        useTime = float(endTick - startTick) * 1000.0
        
        response = runResult.communicate()[0].decode("GBK")
        INFO("Checked #" + str(self.case) + " Time: {:.1f} ms".format(useTime))
        if response != "":
            WARNING("#" + str(self.case) + "'s check program has found an unexpected response: " + response)
        return useTime
    def checkValidity(self):        # [Unfixed Feature]比较已经生成的答案和其他校验代码生成的答案
        self.genCase()
        self.genInvalid()
        runResult = subpcs.Popen("fc " + probName + str(self.case) + ".out " + probName + str(self.case) + ".ans", stdout=subpcs.PIPE, shell=True)
        response = runResult.communicate()[0].decode("GBK")
        return (not "未找到差异" in response)


def WARNING(info, end="\n"):
    print("[WARNING]", time.strftime("[%H:%M:%S]", time.localtime()), info, end=end)
def INFO(info, end="\n"):
    print("[INFO]", time.strftime("[%H:%M:%S]", time.localtime()), info, end=end)
def DEBUG(info, end="\n"):
    print("[DEBUG]", time.strftime("[%H:%M:%S]", time.localtime()), info, end=end)
def ERROR(info, end="\n"):
    print("[ERROR]", time.strftime("[%H:%M:%S]", time.localtime()), info, end=end)
def INTERACT(info):
    return input("[INTERACT] " + str(time.strftime("[%H:%M:%S]", time.localtime())) + " " + info)

def INIT():
    global path, _path, probName, threadnumber, caseQueue
    
    path = os.path.dirname(os.path.abspath(__file__))
    _path = path + "/"
    probName = os.path.split(path)[-1] # 默认题目名为文件夹名
    # probName =                    # 如果有需求请自己覆盖掉
    
    ComplieCommander(probName, "-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456").perform()
    ComplieCommander("gen", "-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456").perform()
    # if os.path.exists(_path + "invsol.cpp"):
    #     ComplieCommander("invsol", "-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456").perform()
    
    threadnumber = int(mulpsc.cpu_count() / 2)
    caseQueue = []
    x = INTERACT("Specify threads number here(default is half of CPU threads[" + str(threadnumber) + "]): ")
    if x != "":
        threadnumber = int(x)
def caseHash(case):
    return " -seed=" + str((case * 191 + 1145) % int(1e8 + 7))

#region
# """ 
# # 弃用的方法
# def genData(case, args):
#     
    # INFO("Generated #" + str(case) + " data: " + args)
#     
    # cmd = "gen " + args + " > " + probName + str(case) + ".in"
    # runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
    # response = runResult.communicate()[0].decode("GBK")
#     
    # if response != "":
        # WARNING("#" + str(TestCase) + "'s generator has found an unexpected response: " + response)
# def genAnswer(case):
#     
    # INFO("Generated #" + str(case) + " answer: ")
#     
    # cmd = "contest < " + probName + str(case) + ".in" + " > " + probName + str(case) + ".ans"
    # runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
    # response = runResult.communicate()[0].decode("GBK")
#     
    # if response != "":
        # WARNING("#" + str(TestCase) + "'s answer program has found an unexpected response: " + response)
# def genTestcase(case, args):
    # genData(case, args)
    # genAnswer(case)
    # INFO("Testcase #" + str(case) + " Created.")
# """ 
#endregion

def getTask():
    global currentPoint, queueLen, caseQueue
    while currentPoint < queueLen - 1:
        currentPoint += 1
        caseQueue[currentPoint].genCase()
def startRunningSequencial():
    global caseQueue
    for i in caseQueue:
        i.genCase()     
    caseQueue = []  
def startRunningThreads():
    global queueLen, currentPoint, threads, caseQueue
    
    queueLen = len(caseQueue)
    currentPoint = -1
    threads = []
    
    for i in range(threadnumber):
        threads.append( Thread(target=getTask) )
    
    for i in range(threadnumber):
        threads[i].start()
    
    for i in range(threadnumber):
        threads[i].join()
    
    caseQueue = []
def startHack(case, args):
    seed = case
    while True:
        validity = TestPoint(case, args+caseHash(seed)).checkValidity()
        if validity == False:
            break
        seed += random.randint(1, 100)
    INFO("invalid sol can be hacked by args: " + args+caseHash(seed))
def startHackThreads():
    pass
def submitGroupData(rng, args):
    global caseQueue
    L, R = 0, 0
    if isinstance(rng, int):
        L = R = rng
    elif (isinstance(rng, list) or isinstance(rng, tuple)) and len(rng) == 2:
        L, R = rng
    else:
        ERROR("TestCase range shoule be a int or list/tuple like [L, R]/(L, R).")
    for TestCase in range(L, R + 1):
        caseQueue.append( TestPoint(TestCase, args + caseHash(TestCase)) )


if __name__ == '__main__':
    INIT()
    
    # 启动提示
    INFO("Program start running on directory: " + path)
    INFO("Subprocesses will run on directory: " + subpcs.Popen("chdir", stdout=subpcs.PIPE, shell=True).communicate()[0].decode("GBK")[0:-1])
    
    # Gen Your Data Here ↓
    
    # submitGroupData([1, 2], "-n=3 -V=10")
    # submitGroupData([3, 6], "-n=10 -V=100")
    # submitGroupData([7, 10], "-n=20 -V=1000")
    
    # submitGroupData([11, 12], "-n=50 -V=1000000000")
    # submitGroupData([13, 14], "-n=80 -V=1000000000")
    # submitGroupData([15, 20], "-n=100 -V=1000000000")
    
    # submitGroupData([21, 24], "-n=1000 -V=1000000000")
    # submitGroupData([25, 30], "-n=2000 -V=1000000000")
    
    # submitGroupData([31, 34], "-n=50000 -V=1000000000")
    # submitGroupData([35, 39], "-n=100000 -V=1000000000")
    # submitGroupData([40, 40], "-n=200000 -V=1000000000")
    
    submitGroupData(1, "-n=20 -V=10")
    submitGroupData(2, "-n=100 -V=1000000000")
    submitGroupData(3, "-n=2000 -V=1000000000")
    submitGroupData(4, "-n=200000 -V=1000000000")
    
    # 启动生成队列
    # startRunningSequencial() # 顺序生成队列内数据点
    startRunningThreads()    # 多线程生成队列内数据点
    
    # Hack Functions    
    
    # 结束提示
    INFO("Program Exited. Thanks for using. [QwQ]")
