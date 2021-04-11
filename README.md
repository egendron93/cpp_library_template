# cpp_library_template
A modern implementation of a cpp library that uses cmake and conan. This library template is based on the sg20 build system videos Effective CMake by Daniel Pfeifer and Modern Cmake by Mathieu Ropert. The conan integration and recipe development was inspired by Mateusz Psuz's Git, Conan and Cmake video from CppCon 2018.

# build commands w/ tests
## conan install
```conan install -if build -o hello_world:enable_testing=True .```

## conan build
```conan build -if build -bf build .```

## conan create
```conan create -tbf build -o hello_world:enable_testing=True .```