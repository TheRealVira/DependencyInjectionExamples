#region License

// Copyright (c) 2017, Vira
// All rights reserved.
// Solution: CSharp_Example
// Project: Printer
// Filename: OutputableFactory.cs
// Date - created:2017.04.15 - 09:52
// Date - current: 2017.04.15 - 11:12

#endregion

#region Usings

using System.IO;
using System.Xaml;
using System.Xml;

#endregion

namespace Printer
{
    /// <summary>
    ///     Represents a factory, which is also able to load and save IConsoleOutputable.
    /// </summary>
    public static class OutputableFactory
    {
        /// <summary>
        ///     Generates a new instance of the type T.
        /// </summary>
        /// <typeparam name="T">T has to implament IConsoleOutputable.</typeparam>
        /// <returns>Returns a new instance of the wanted type.</returns>
        public static IConsoleOutputable Factorise<T>() where T : IConsoleOutputable, new() => new T();

        /// <summary>
        ///     Loads the IConsoleOutputable from a xaml file.
        /// </summary>
        /// <param name="file">The xaml file, which contains the inforamtion for a IConsoleOutputable.</param>
        /// <returns>Returns the loaded IConsoleOutputable.</returns>
        public static IConsoleOutputable Load(string file)
        {
            using (TextReader reader = File.OpenText(file))
            {
                return (IConsoleOutputable) XamlServices.Load(XmlReader.Create(reader, new XmlReaderSettings
                {
                    DtdProcessing = DtdProcessing.Parse,
                    MaxCharactersFromEntities = 1024,
                    
                }));
            }
        }

        /// <summary>
        ///     Serialises the IConsoleOutputable into xaml file.
        /// </summary>
        /// <param name="toSave">The IConsoleOutputable, which has to get saveed.</param>
        /// <param name="file">The file, which is going to contain the serialised code.</param>
        public static void Save(this IConsoleOutputable toSave, string file)
        {
            using (TextWriter writer = File.CreateText(file))
            {
                XamlServices.Save(writer, toSave);
            }
        }
    }
}