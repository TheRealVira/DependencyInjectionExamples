using System;
using Printer;

namespace TestApplication
{
    class Example3:IConsoleOutputable
    {
        public void Print(string text)
        {
            Console.WriteLine($"-={text}=-");
        }
    }
}
