#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: Printer
// Filename: IConsoleOutputable.cs
// Date - created:2017.04.15 - 09:48
// Date - current: 2017.04.15 - 10:39

#endregion

namespace Printer
{
    /// <summary>
    /// Represents an interface, which holds a print method (used for printing text on the console).
    /// </summary>
    public interface IConsoleOutputable
    {
        /// <summary>
        /// Prints the text.
        /// </summary>
        /// <param name="text">The text that is needed to get printed out.</param>
        void Print(string text);
    }
}