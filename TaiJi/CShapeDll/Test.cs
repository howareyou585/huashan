using System.IO;

namespace CShapeDll
{
    public class Test
    {
        public static int EntryPoint(string arg)
        {
            File.AppendAllText("C:/xx.txt", "qweqwe");
            return 0;
        }
        public static int Add(string str)
        {
            var strs = str.Split(',');
            int a = int.Parse(strs[0]);
            int b = int.Parse(strs[1]);
            return a + b;
        }
    }
}
