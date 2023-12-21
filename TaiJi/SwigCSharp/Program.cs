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
            Caller caller = new Caller();
            SimpleCallback callback = new CSharpCallback();
            caller.setCallback(callback);
            caller.call();
            Console.ReadKey();
        }

    }
}
