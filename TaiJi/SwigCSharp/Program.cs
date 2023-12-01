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
            CPlusPlusClass fromCPlusPlus = new CPlusPlusClass();
            Console.WriteLine("1+2=" + fromCPlusPlus.Add(1, 2));
            Console.ReadKey();
        }
    }
}
