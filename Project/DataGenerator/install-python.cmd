@echo off

echo 下载 python
echo.

curl -o InstallPython.exe "https://mirrors.huaweicloud.com/python/3.11.6/python-3.11.6-amd64.exe"

echo.
echo 下载完毕
echo.

echo.
echo 开始安装 python
echo.

InstallPython /quiet PrependPath=1 /passive

echo.
echo 安装完毕
echo.

del InstallPython.exe

pause