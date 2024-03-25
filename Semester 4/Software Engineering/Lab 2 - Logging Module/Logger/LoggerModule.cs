using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using recommenders;

public enum LogLevel 
{
    INFO,
    WARNING,
    ERROR,
    CRITICAL
}


public class LoggerHelper
{
    public static String GetFilePathForCurrentDate()
    {
        /*
         * Input: None
         * Return: String
         * Description: Computes the current date in the format "yyyy-MM-dd" and 
         *              returns the path to the corresponding log file
         */

        String CurrentDate = DateTime.Today.ToString("yyyy-MM-dd");
        string ProjectDirectoryPath = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;     
        return Path.Combine(ProjectDirectoryPath, "Logger", CurrentDate);
    }
}

public class Logger : ILogger
{
    // Properties

    //Flag to determine if the log messages should be displayed to the console
    public bool DisplayToConsoleFlag { get; set; }

    private static string LogFilePath = LoggerHelper.GetFilePathForCurrentDate();
    private static readonly object LockObject = new object();
    private static readonly List<string> InfoBuffer = new List<string>();

    // Timer to flush the info buffer to the log file every 5 seconds
    private static readonly Timer FlushTimer = new Timer(FlushInfoBuffer, null, TimeSpan.FromSeconds(5), TimeSpan.FromSeconds(5));


    // Constructor
    public Logger(bool displayToConsoleFlag)
    {
        DisplayToConsoleFlag = displayToConsoleFlag;
    }

    public Logger()
    {
        DisplayToConsoleFlag = false;
    }

    // Methods
    public void Log(string level, string message)
    {
        /*
         * Input: String, String
         * Return: None
         * Description: Logs the messages according to the level provided and checked
         *              against the LogLevel enum. The INFO messages are buffered and 
         *              flushed to the log file every 5 seconds. The other messages 
         *              are written to the log file immediately. If the 
         *              DisplayToConsoleFlag is set to true, the messages are also
         *              displayed to the console.                             
         */
        string logEntry = $"{DateTime.Now:yyyy-MM-dd HH:mm:ss} [ {level} ] {message}";
        LogLevel logLevel;

        if(!Enum.TryParse<LogLevel>(level, true, out logLevel))
        {
            return;
        }

        lock (LockObject)
        {
            if (level.ToUpper() == "INFO")
            {
                InfoBuffer.Add(logEntry);
                if (DisplayToConsoleFlag)
                {
                    Console.WriteLine(message);
                }
            }
            else
            {
                if (DisplayToConsoleFlag)
                {
                    Console.WriteLine($"[ {level} ] {message}");
                }
                WriteToLogFile("----------------------------------------------------------------------------------------");
                WriteToLogFile(logEntry);
                WriteToLogFile("----------------------------------------------------------------------------------------");


            }
        }


    }
    private static void WriteToLogFile(string logEntry)
    {
        /*
         * Input: String
         * Return: None
         * Description: Writes the logEntry to the log file. If the file does not exist, 
         *              it is created. If the file exists, the logEntry is appended to the file.
         */
        try
        {
            using (StreamWriter writer = new StreamWriter(LogFilePath, true))
            {
                 writer.WriteLine(logEntry);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error writing to log file: {ex.Message}");
        }

    }

    private static void FlushInfoBuffer(object state)
    {
        /*
         * Input: Object
         * Return: None
         * Description: Writes the contents of the InfoBuffer to the log file and 
         *              clears the buffer.
         */

        lock (LockObject)
        {
           foreach (var entry in InfoBuffer)
            {
                WriteToLogFile(entry);
            }
            InfoBuffer.Clear();
        }
    }
}