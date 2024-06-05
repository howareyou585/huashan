// SegmentationFault.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class VertexSet
{
public:
    VertexSet()
    {
        cout << "VertexSet 构造函数" << endl;
    }
private:
    int m_val;
};
class MyB
{
public:
    MyB()
    {
        cout << "MyB 构造函数" << endl;
    }
private:
    char m_val;
};
struct vertexBlock
{
    VertexSet* ptrVertexSet;
    MyB* ptrB;
    int vertexOffset;
    int normalOffset;
    int uvOffset;
    int vertexLength;
    int normalLength;
    int uvLength;

};
void setVertexBlock(vertexBlock* ptrVB)
{
    cout << "vertexOffset:" << ptrVB->vertexOffset << endl;
    cout << "normalOffset:" << ptrVB->normalOffset << endl;
    cout << "uvOffset:" << ptrVB->uvOffset << endl;
    cout << "vertexLength:" << ptrVB->vertexLength << endl;
    cout << "normalLength:" << ptrVB->normalLength << endl;
    cout << "uvLength:" << ptrVB->uvLength << endl;
}
int main()
{
    vertexBlock vb;
    vb.vertexOffset = 100;
    vb.vertexLength = 1000;
    vb.normalOffset = 200;
    vb.normalLength = 2000;
    vb.uvOffset = 300;
    vb.uvLength = 3000;
    setVertexBlock(&vb);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
