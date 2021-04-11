# ruby-inside-c

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
