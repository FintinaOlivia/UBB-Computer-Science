using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;


namespace recommenders
{
    internal class LoggingDummy
    {	

        static void Main(string[] args)
        {
			Console.WriteLine("Display to console? (y/n)");
            string userChoice = Console.ReadLine();

            if (userChoice == "y")
            {
				Logger logger = new Logger(true);
				logger.Log("INFO", "This is an info message");
				logger.Log("WARNING", "This is a warning message");
				logger.Log("INFO", "This is an info message");
				Console.WriteLine("Sleeping for 5 seconds");
				Thread.Sleep(5000);
				logger.Log("ERROR", "This is an error message");
				logger.Log("CRITICAL", "This is a critical message");
				Console.WriteLine("Sleeping for 5 seconds");
				Thread.Sleep(5000);
				logger.Log("INFO", "This is the final countdown.");
			}
			else
			{
				Logger logger = new Logger();
				logger.Log("INFO", "This is an info message");
				logger.Log("WARNING", "This is a warning message");
				logger.Log("INFO", "This is an info message");
				Thread.Sleep(5000);
				logger.Log("ERROR", "This is an error message");
				logger.Log("CRITICAL", "This is a critical message");
				Thread.Sleep(5000);
			}
			Console.WriteLine("Press any key to exit...");
			Console.ReadLine();
		}
    }
}