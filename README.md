# cpp_library_template
A modern implementation of a cpp library that uses cmake and conan. This library template is based on the sg20 build system videos Effective CMake by Daniel Pfeifer and Modern Cmake by Mathieu Ropert. The conan integration and recipe development was inspired by Mateusz Psuz's Git, Conan and Cmake video from CppCon 2018.

## devcontainer
- This project uses a dockerfile as a template for its development environment. The dockerfile is located
in the .devcontainer folder and is intended to be used with the [vscode devcontainer
feature](https://code.visualstudio.com/docs/remote/create-dev-container).

## commands w/ tests enabled

- The following commands are provided as vscode tasks. For more information on vscode tasks 
visit the [vscode task documentation](https://code.visualstudio.com/docs/editor/tasks).
- You can run a task through Quick Open (Ctrl+P) by typing 'task', Space and the command name.

### conan install
```conan install -if build -o hello_world:enable_testing=True .```

### conan build
```conan build -if build -bf build .```

### conan create
```conan create -tbf build -o hello_world:enable_testing=True .```

### run unit tests
```./build/tests/unit/hello_world_unit```


## bazel build with conan bazel generators
- The bazel build is still experimental and has a few issues that need to be addressed.
- There is no option to pass the conan install and build folder information to the bazel build tool.
- The boost package has an issue with excaping quotes when its targets definitions are 
created. This is fixed by manually adding escape characters in the boost BUILD file.
- The gtest package cc_library target does not tranistively provide the linker with
the precompiled library locations. A solution to this could be to add the cc_imports as
dependencies to the gtest cc_library target.
    - ``` deps = [":gmock_main_precompiled", "gmock_precompiled", "gtest_main_precompiled", ":gtest_precompiled"] ```
    - Another solution could be to make the cc_import targets publicly visible. That would let the user 
    decide wich libraries to link to.
### conan install
```conan install . -o hello_world:enable_testing=True```

### conan build
```conan build .```

## References
- [SG20 Education and Recommended Videos for Teaching C++ by Christopher Di Bella](https://www.cjdb.com.au/sg20-and-videos) 
- [Effective CMake by Daniel Pfeifer](https://youtu.be/bsXLMQ6WgIk)
- [Modern CMake for modular design by Mathieu Ropert](https://youtu.be/ztrnb-bVVPo)
- [Git, CMake, Conan - How to ship and reuse our C++ projects by Mateusz Psuz](https://youtu.be/S4QSKLXdTtA)