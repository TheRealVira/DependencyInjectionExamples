#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: Printer
// Filename: Example2.cs
// Date - created:2017.04.15 - 10:03
// Date - current: 2017.04.15 - 11:12

#endregion

#region Usings

using System;
using System.Linq;

#endregion

namespace Printer.Buildin_Examples
{
    /// <summary>
    ///     Represents an example implementation of IConsoleOutputable
    /// </summary>
    public class Example2 : IConsoleOutputable
    {
        /// <summary>
        ///     Prints the text in reverse.
        /// </summary>
        /// <param name="text">The text that is needed to get printed out.</param>
        public void Print(string text)
        {
            Console.WriteLine(new string(text.Reverse().ToArray()));
        }
    }
}