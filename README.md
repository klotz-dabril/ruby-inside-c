# ruby-inside-c

Personal notes on embedding ruby into c.


### Compiling ruby source with shared libraries
```bash
autoconf
./configure --enable-shared
make
```

### Compiling application
```bash
gcc -Wall \
    main.c \
    -I./ruby/include \
    -I./ruby/.ext/include/x86_64-linux \
    -L./ruby \
    -lruby \
    -o main
```

### Running
```bash
export LD_LIBRARY_PATH=$(pwd)/ruby
./main
```

### Resources
- [Ruby C API Reference](https://docs.ruby-lang.org/en/3.0.0/doc/extension_rdoc.html) (official documentation)
- [The Definitive Guide to Ruby's C API](https://silverhammermba.github.io/emberb/c/) (silverhammermba)
- [The Pragmatic Programmer's Guide](http://ruby-doc.com/docs/ProgrammingRuby/html/ext_ruby.html)
- [Writing Ruby Extensions in C - Part 1](http://clalance.blogspot.com/2011/01/writing-ruby-extensions-in-c-part-1.html) (Chris Lalancette)
- [cheatsheet](https://croisant.net/ruby-c-extension-cheat-sheet/)

#### c++
- [Embedding Ruby 2.1 into a C++ application](http://hugopl.github.io/2014/04/09/Embedding-Ruby-2.1-into-a-Cpp-application.html)
- [jefftrull/main.cpp](https://gist.github.com/jefftrull/1305431)
- [ruby embedded into c++](http://metaeditor.sourceforge.net/embed/)
