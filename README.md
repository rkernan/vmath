# vmath
[![Build Status](https://travis-ci.org/kernan/vmath.svg?branch=master)](https://travis-ci.org/kernan/vmath)

## Build and run tests

### Linux

Requirements:
* Clang >= 3.4
* CMake >= 3.0.2
* Boost >= 1.34

```bash
make
cd build
make check
```

### Windows (using Visual Studio 2017)

Requirements:
- Visual Studio 2017 with CMake support
- Boost >= 1.34

Open the project folder in Visual Studio 2017 and CMake should build the
solution automatically. By default vmath uses Boost in header-only mode on
Windows so you only need to download the Boost sources.

You will likely need to adjust the CMake settings. The following works for me
(remember to change BOOST_ROOT to your Boost install!):

You will likely need to add `BOOST_ROOT` to *CMakeSettings.json*. The following
configuration works for me:

```json
{
    "configurations": [
      {
        "name": "x64",
        "generator": "Visual Studio 15 2017 Win64",
        "configurationType": "Release",
        "buildRoot": "${env.LOCALAPPDATA}\\CMakeBuild\\${workspaceHash}\\build\\${name}",
        "cmakeCommandArgs": "",
        "buildCommandArgs": "-m -v:minimal",
        "variables": [
          {
            "name": "BOOST_ROOT",
            "value": "C:\\Program Files\\boost\\boost_1_64_0"
          }
        ]
      }
    ]
}
```

## License

MIT License. Copyright (c) 2013-2017 Robert Kernan.
