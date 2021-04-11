# cpp_library_template
A modern implementation of a cpp library that uses cmake and conan. This library template is based on the sg20 build system videos Effective CMake by Daniel Pfeifer and Modern Cmake by Mathieu Ropert. The conan integration and recipe development was inspired by Mateusz Psuz's Git, Conan and Cmake video from CppCon 2018.

# build commands w/ tests enabled
## conan install
```conan install -if build -o hello_world:enable_testing=True .```

## conan build
```conan build -if build -bf build .```

## conan create
```conan create -tbf build -o hello_world:enable_testing=True .```

# References
- [SG20 Education and Recommended Videos for Teaching C++ by Christopher Di Bella](https://www.cjdb.com.au/sg20-and-videos) 
- [Effective CMake by Daniel Pfeifer](https://youtu.be/bsXLMQ6WgIk)
- [Modern CMake for modular design by Mathieu Ropert](https://youtu.be/ztrnb-bVVPo)
- [Git, CMake, Conan - How to ship and reuse our C++ projects by Mateusz Psuz](https://youtu.be/S4QSKLXdTtA)