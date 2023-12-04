using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SwigCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //1.简单类型的接口测试。
            //CPlusPlusClass fromCPlusPlus = new CPlusPlusClass();
            //Console.WriteLine("1+2=" + fromCPlusPlus.Add(1, 2));
            ////2.测试 C++ 端的全局函数 全局变量 宏定义
            //Console.WriteLine("PI=" + SwigCplusplus.PI);
            //SwigCplusplus.funcA();

            point3d pd_1 = new point3d(2, 3, 4);
            point3d pd_2 = new point3d(3, 4, 5);
            point3d pd_3 = new point3d(6, 7, 2);
            gmeParseObj obj = new gmeParseObj();
            string fname = "obj_1";
            obj.setObjName(fname);
            vec3ds points = new vec3ds();
            points.Add(pd_1);
            points.Add(pd_2);
            points.Add(pd_3);
            obj.fillPoints(points);
            int pntsNum = obj.getPointsNum();
            Console.WriteLine(fname + "内有" + pntsNum.ToString() + "个点数据");
            
            Console.ReadKey();
        }
    }
}
