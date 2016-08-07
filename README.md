# LoggerWinRT

Simple logging library that allows to log from C# and/or from C++/CXX


Currently can only log to debug output or to file.


Initialization example:

```
#if DEBUG
      Wally.Utils.DebugOutputTarget debugOutTarget = new Wally.Utils.DebugOutputTarget();

      Wally.Utils.LogTargetManager.AddLogTarget(debugOutTarget);
#endif

      Wally.Utils.FileOutput fileOutTarget = new Wally.Utils.FileOutput("log.txt", true);

      Wally.Utils.LogTargetManager.AddLogTarget(fileOutTarget);
```
