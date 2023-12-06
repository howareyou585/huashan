using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CShapeDll
{
    public class ShowCase
    {
        /// <summary>
        /// Get sum of two numbers;
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int Sum(int a, int b) => a + b;

        /// <summary>
        ///  Get full name;
        /// </summary>
        /// <param name="firstName"></param>
        /// <param name="lastName"></param>
        /// <returns></returns>
        public string GetFullName(string firstName, string lastName) => $"{firstName} {lastName}";

    }
}
