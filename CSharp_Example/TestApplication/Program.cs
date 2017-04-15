#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: TestApplication
// Filename: Program.cs
// Date - created:2017.04.15 - 10:35
// Date - current: 2017.04.15 - 11:12

#endregion

#region Usings

using System;
using System.Net;
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
                "Menu:\n[0] ... Generate example file\n[1] ... Load example file local\n[2] ... Load example file online\n----------------------\n");

            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.D0:
                    OutputableFactory.Factorise<GenericPrinter<Example3>>().Save("example.xml");
                    break;
                case ConsoleKey.D1:
                    LOAD:
                    OutputableFactory.Load("example.xml").Print("This is text!");
                    break;
                case ConsoleKey.D2:
                    using (var client = new WebClient())
                    {
                        client.DownloadFile(
                            "https://raw.githubusercontent.com/TheRealVira/DependencyInjectionExamples/master/Example_XML_Files/CSharp_example.xml",
                            @"example.xml");
                    }
                    goto LOAD;
                default:
                    Console.WriteLine("This key was not an option...");
                    break;
            }

            Console.WriteLine("=======================================");
            Console.WriteLine("===           Custome Test          ===");
            Console.WriteLine("=======================================");

            OutputableFactory.Factorise<Example3>().Print("This is some other text");

            Console.WriteLine("=== Press a key to exit the program! ===");

            Console.ReadKey(true);
        }
    }
}