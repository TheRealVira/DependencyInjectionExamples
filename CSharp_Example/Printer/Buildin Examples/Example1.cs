#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: Printer
// Filename: Example1.cs
// Date - created:2017.04.15 - 10:02
// Date - current: 2017.04.15 - 10:39

#endregion

#region Usings

using System;

#endregion

namespace Printer.Buildin_Examples
{
    /// <summary>
    /// Represents an example implementation of IConsoleOutputable
    /// </summary>
    public class Example1 : IConsoleOutputable
    {
        /// <summary>
        /// Prints the text.
        /// </summary>
        /// <param name="text">The text that is needed to get printed out.</param>
        public void Print(string text)
        {
            Console.WriteLine(text);
        }
    }
}