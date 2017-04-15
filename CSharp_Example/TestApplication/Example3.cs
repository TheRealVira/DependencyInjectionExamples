#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: TestApplication
// Filename: Example3.cs
// Date - created:2017.04.15 - 10:41
// Date - current: 2017.04.15 - 11:12

#endregion

#region Usings

using System;
using Printer;

#endregion

namespace TestApplication
{
    public class Example3 : IConsoleOutputable
    {
        public void Print(string text)
        {
            Console.WriteLine($"-={text}=-");
        }
    }
}