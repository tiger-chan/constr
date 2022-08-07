# constr
Small C++ lib for constexpr string

# Table of Contents
* [Usage](#usage)
  * [Conan](#conan)
  * [CMake](#cmake)
* [Missing Types](#missing-types)
* [API](#api)
* [Contributing](#contributing)
* [License](#license)

## Usage

### Conan

constr can be installed using [Conan](http://docs.conan.io/en/latest/)

#### Add To Your Local Conan Cache

```console
foo@bar:~$ git clone https://github.com/tiger-chan/constr.git
foo@bar:~$ cd constr
foo@bar:~/constr$ mkdir build
foo@bar:~/constr$ cd build && conan create .. constr/[~= 0.1]@tiger-chan/stable
```

#### Conan Install the package

```console
foo@bar:~/your-proj$ conan install constr/[~= 0.1]@tiger-chan/stable
```

### Conan Project Setup

If you handle multiple dependencies in your project is better to add a *conanfile.txt*
```txt
[requires]
constr/[~= 0.1]@tiger-chan/stable

[generators]
txt
```

Complete the installation of requirements for your project running:
```console
foo@bar:~/your-proj$ mkdir build && cd build && conan install ..
```

> _**NOTE:**_ It is recommended not to run the install/build commands in the project directory.  This is because conan generates many files which are tied to specific build configurations.

### CMake

To use `constr` from a [CMake](https://cmake.org/) project, just link an existing target to the
`constr::constr` alias.

The library offers everything you need for locating (as in `find_package`),
embedding (as in `add_subdirectory`), or fetching (as in `FetchContent`).

## API

The API can be accessed through the inclusion of a single header (`constr.hpp`).
```cpp
#include <constr/constr.hpp>

// Or individually as needed
#include <constr/string.hpp>
#include <constr/string_fixed.hpp>
#include <constr/string_view.hpp>
```

## Contributing

Requests for features, PRs, suggestions and feedback are very welcome.

see [CONTRIBUTING](docs/CONTRIBUTING.md) for more information.

## License

Code and documentation Copyright (c) 2022 Anthony Young.
Code released under [MIT](LICENSE)