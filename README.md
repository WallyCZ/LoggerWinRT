# LoggerWinRT

Simple logging library that allows to log from C# and/or from C++/CXX


Currently can only log to debug output or to file.


Initialization example from C#:

```
#if DEBUG
      Wally.Utils.DebugOutputTarget debugOutTarget = new Wally.Utils.DebugOutputTarget();

      Wally.Utils.LogTargetManager.AddLogTarget(debugOutTarget);
#endif

      Wally.Utils.FileOutput fileOutTarget = new Wally.Utils.FileOutput("log.txt", true);

      Wally.Utils.LogTargetManager.AddLogTarget(fileOutTarget);
```


Then in C# class:

```
Wally.Utils.Logger logger = Wally.Utils.Logger.GetLogger(typeof(MyClass).FullName);
logger.Info("Test ");
```
