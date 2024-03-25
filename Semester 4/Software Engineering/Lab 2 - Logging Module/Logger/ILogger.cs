using System;

namespace recommenders
{
    public interface ILogger
{
    void Log(string logLevel, string message);
}
}