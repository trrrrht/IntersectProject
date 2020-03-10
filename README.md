# IntersectProject

## 主要文件

注：为了性能，将所有代码集成到了main中，但功能块保持不变，仅为了将结构体的设置转变为数组设置。

### Main.cpp

main文件中主要包含了输入所需函数，调用所要求解的函数，并且输出

### Line.cpp

建立直线的结构体，便于存储（不过之后将其换为了数组存储，因为会比结构体快一些）

### Cycle.cpp

建立圆的结构体，便于存储（不过之后将其换为了数组存储，因为会比结构体快一些）

### CalIntersect.cpp

包含三个计算函数：

- LineIntersectLine
  - 采用一般式直线交点公式计算

- LineIntersectCycle
  - 采用向量法计算，具体步骤在[博客](https://blog.csdn.net/qq_40998706/article/details/87521165)中体现

- CycleIntersectCycle
  - 采用matlab直接得出交点公式

### IntersectPoint.cpp

建立交点的结构体，便于存储。

### Hash.cpp

最初的思路是通过set去重直接得到结果，但是后来发现可以使用vector的sort和unique进行去重。所以Hash.cpp暂且搁置

## 使用方法

仅支持intersect.exe -i input.txt -o output.txt在命令行中使用