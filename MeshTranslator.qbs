import qbs

CppApplication {
    consoleApplication: true
    Group {
        name: "include"
        prefix: "include/"
        files: [
            "*.h",
        ]
    }
    Group {
        name: "source"
        prefix: "source/"
        files: "*.cpp"
        cpp.includePaths: ["include"]
    }

    Group {
        fileTagsFilter: product.type
        qbs.install: true
    }

    cpp.cxxLanguageVersion: "c++14"
}
