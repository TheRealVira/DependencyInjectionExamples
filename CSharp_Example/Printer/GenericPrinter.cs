#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: Printer
// Filename: GenericPrinter.cs
// Date - created:2017.04.15 - 09:49
// Date - current: 2017.04.15 - 10:39

#endregion

namespace Printer
{
    /// <summary>
    /// Represents a generic type of printer, which allows any type of IConsoleOutputable. This is useful for dependency injections.
    /// </summary>
    /// <typeparam name="T">The inner type of this class.</typeparam>
    public class GenericPrinter<T> : IConsoleOutputable where T : IConsoleOutputable, new()
    {
        /// <summary>
        /// Inner type.
        /// </summary>
        private readonly IConsoleOutputable _myMethod;

        public GenericPrinter()
        {
            _myMethod = OutputableFactory.Factorise<T>();
        }

        /// <summary>
        /// Prints the text in the way used by the inner type.
        /// </summary>
        /// <param name="text">The text that is needed to get printed out.</param>
        public void Print(string text)
        {
            _myMethod.Print(text);
        }
    }
}