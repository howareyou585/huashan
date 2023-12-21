using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SwigCSharp
{
    public class CSharpCallback:SimpleCallback
    {
        public CSharpCallback() { }
        public override void run()
        {
            Console.WriteLine("call CSharpCallback callback");
            //base.run();
        }
    }
}
