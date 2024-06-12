# Data Generator 
# Designed for OI problem data Generating

# 使用参考：
#   1. 将你编写的通过 testlib 实现的 Generator 放入本目录下的 gen.cpp (testlib 已经提供)
# 

import os
import sys
import time
import threading as thr
import subprocess as subpcs
import multiprocessing as mulpsc

from math import *

globalCompileOptions = ["-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456"]

def WARNING(info):
    print("[WARNING]", time.strftime("[%H:%M:%S]", time.localtime()), info)
def INFO(info):
    print("[INFO]", time.strftime("[%H:%M:%S]", time.localtime()), info)
def DEBUG(info):
    print("[DEBUG]", time.strftime("[%H:%M:%S]", time.localtime()), info)
    
class Commander:
    mainProcess = ""
    parameter = []
    def __init__(self, _mainProcess, *para):
        self.mainProcess = _mainProcess
        self.parameter = para
    def getCmd(self):
        return self.mainProcess + " " + " ".join(self.parameter)
    def perform(self):
        cmd = self.getCmd()
        INFO("Performed a Command: " + cmd)
        runResult = subpcs.Popen(cmd, stdout=subpcs.PIPE, shell=True)
        return runResult.communicate()[0].decode("GBK")

class ComplieCommander(Commander):
    fileName = ""
    def __init__(self, _fileName, *para):
        self.mainProcess = "g++"
        self.fileName = _fileName
        basicLine = [_path + _fileName + ".cpp", "-o", _path + _fileName]
        basicLine.extend(para)
        self.parameter = basicLine

class GeneratorCpp:
    fileName = ""
    complieCmd = ""
    def __init__(self, _fileName):
        self.fileName = _fileName
        self.complieCmd
    def genToFile(self, *runpara):
        compileCommander = ComplieCommander(self.fileName, globalCompileOptions)
        # subpcs.Popen(runpara, stdout=subpcs.PIPE, shell=True)
        pass

class TestPoint:
    pointNumber = 0
    fileName = ""
    def __init__(self, _pointNumber, _fileName):
        self.pointNumber = _pointNumber
        self.fileName = _fileName
    def generatorData(generator):    # 调用数据生成器，生成一组样例 {fileName}_{pointNumber}.in
        try:
            generator.genToFile()
            return True
        except:
            print("")
            return False
    def checkValidity():    # 比较 std.cpp 已经生成的答案和 best.cpp 运行代码生成答案并校验是否相同
        return True
    def runTime():          # 运行 std.cpp 来生成一组答案并返回时间
        pass

if __name__ == '__main__':
    path = current_dir = os.path.dirname(os.path.abspath(__file__))
    _path = path + "\\"
    INFO("Program start running on directory: " + path)
    INFO("Subprocesses will run on directory: " + subpcs.Popen("chdir", stdout=subpcs.PIPE, shell=True).communicate()[0].decode("GBK")[0:-1])
    probname = path.split('\\')[-1]
    
    # complieCommand = ComplieCommander(probname, "-std=c++14", "-O2", "-Wall", "-Wextra", "-Wl,--stack=268435456")
    # checkPath = Commander("chdir")
    # INFO(checkPath.perform())
    

    
    INFO("Program Exited. Thanks for using. [QwQ]")
   