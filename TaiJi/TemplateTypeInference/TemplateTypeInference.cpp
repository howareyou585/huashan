// TemplateTypeInference.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;
using namespace std;
template<typename T>
void funcPassVal(T paramVal)
{
    std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id_with_cvr <decltype(paramVal)>().pretty_name() << std::endl;
}

template<typename T>
void funcPassConstVal(const T paramVal)
{
    std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id_with_cvr <decltype(paramVal)>().pretty_name() << std::endl;
}

template<typename T>
void funcPassRef(T& paramval)
{
   
    std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id_with_cvr <decltype(paramval)>().pretty_name() << std::endl;
}
template<typename T>
void funcPassConstRef(const T& paramval)
{
   
    std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id_with_cvr <decltype(paramval)>().pretty_name() << std::endl;
}
//万能引用
template<typename T>
void funcPassUniversalRef(T&& paramval)
{
	std::cout << "T=" << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "paramval type = " << type_id_with_cvr <decltype(paramval)>().pretty_name()<<std::endl;
	std::cout << endl;
}
//右值引用
template <typename T>
void funcPassByLightRef(vector<T>&& vecData)
{
	
}

void funcPassByIntLightRef(int&& intRightRef)
{

}

template<typename T>
void funcPassPointer(T* paramval)
{
	std::cout << "T=" << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "paramval type = " << type_id_with_cvr <decltype(paramval)>().pretty_name() << std::endl;
	std::cout << endl;
}
int main()
{
    //std::cout << "Hello World!\n";
    int a = 10;
    int& refA = a;
    const int& refConstA = a;
    const int cd = 10;

	/*cout << "invoke funcPassPointer" << endl;
	funcPassPointer(&a);
	const int*pa = &a;
	funcPassPointer(pa);*/

 //   cout << "invoke funcPassVal：non pointor" << endl; //值传递非指针
 //   //值传递 ：引用 const 全被忽略
	//funcPassVal(a);  //T int <====> paramVal int
	//funcPassVal(refA);  //T int <====> paramVal int   引用会被忽略 
	//funcPassVal(refConstA);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
	//funcPassVal(cd);  //T int <====> paramVal int   const 会被忽略
 //  
	//cout<< "invoke funcPassVal： pointor" << endl; //值传递指针
	//char mystr[] = "I love china";
	//
	//const char * ptrstr = mystr;
	//funcPassRef(mystr);
	//funcPassRef(ptrstr);
	
	funcPassRef(a);// 
	funcPassRef(refA); //引用被忽略掉
	funcPassRef(refConstA); //引用被忽略掉， 添加const 
	funcPassRef(cd);//添加const

    //
    //
    ////引用
    //cout << "invoke funcPassConstVal" << endl;
    //funcPassConstVal(a);  //T int <====> paramVal int
    //funcPassConstVal(b);  //T int <====> paramVal int   引用会被忽略 
    //funcPassConstVal(c);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
    //funcPassConstVal(d);  //T int <====> paramVal int   const 会被忽略

    //cout << endl;
    //cout << "invoke funcPassRef" << endl;

    //funcPassRef(a);  //T int <====> paramVal int
    //funcPassRef(refA);  //T int <====> paramVal int   引用会被忽略 
    //funcPassRef(refConstA);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
    //funcPassRef(cd);  //T int <====> paramVal int   const 会被忽略

	//cout << "invoke funcPassConstRef" << endl;
	//funcPassConstRef(a);
	//funcPassConstRef(refA); //引用被忽略掉
	//funcPassConstRef(refConstA);// 引用被忽略掉,const属性被忽略掉
	//funcPassConstRef(cd);//const属性被忽略掉
	

    /*std::cout << "invoke func" << std::endl;
    func(a);
    func(b);
    func(c);
    func(d);
    std::cout << "invoke funcConst" << std::endl;
    funcConst(10);
    funcConst(a);
    funcConst(b);*/

	////万能引用
	//cout << "invoke funcPassUniversalRef" << endl;
	//funcPassUniversalRef(a);
	//funcPassUniversalRef(refA);
	//funcPassUniversalRef(refConstA);
	//funcPassUniversalRef(cd);
	//funcPassUniversalRef(100);
	//int && refRightValue = 100;
	//funcPassUniversalRef(refRightValue);  //传递的是一个右值引用变量是一个左值。
	//
	////右值引用
	//cout << "invoke funcPassByLightRef" << endl;
	//vector<int>vecData{1,2};

	//funcPassByLightRef(std::move(vecData));

	//int&& right_ref_a = 5;
	//right_ref_a = a;
	//funcPassByIntLightRef(right_ref_a); //必须是右值，右值引用是左值
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
