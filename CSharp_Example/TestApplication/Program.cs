#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: TestApplication
// Filename: Program.cs
// Date - created:2017.04.15 - 10:35
// Date - current: 2017.04.15 - 10:39

#endregion

#region Usings

using System;
using Printer;
using Printer.Buildin_Examples;

#endregion

namespace TestApplication
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine(
                "Menu:\n[0] ... Generate example file\n[1] ... Load example file\n----------------------\n");

            if (Console.ReadKey(true).Key.Equals(ConsoleKey.D0))
                OutputableFactory.Factorise<GenericPrinter<Example1>>().Save("example.xml");
            else
                OutputableFactory.Load("example.xml").Print("This is text!");

            Console.WriteLine("=======================================");
            Console.WriteLine("===           Custome Test          ===");
            Console.WriteLine("=======================================");


            Console.WriteLine("=== Press a key to exit the program! ===");

            Console.ReadKey(true);
        }
    }
}