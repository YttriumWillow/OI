import math

def sky_garden(n, m):
    result = 0.0
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            theta = j * math.pi / m
            alpha = (j - 1) * math.pi / m
            
            # 计算圆与直线之间的交点的坐标
            x = i * math.cos(theta)
            y = i * math.sin(theta)
            
            # 计算相邻两个交点之间的距离
            if i > 1:
                result += i * (theta - alpha) + i * math.sin(theta - alpha)
    
    # 处理重复的贡献，将结果除以2
    result /= 2
    
    return result

# 读取输入
n, m = map(int, input().split())

# 调用函数计算答案
answer = sky_garden(n, m)

# 输出结果
print('{:.10f}'.format(answer))
