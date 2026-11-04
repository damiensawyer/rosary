# rosary

A terse, recursive C program that prints the full Catholic Rosary.

## Build and run

Plain standard C: no libraries or extra flags needed.

### Linux

Install a compiler if you don't have one:

```sh
sudo apt install gcc        # Debian / Ubuntu
sudo dnf install gcc        # Fedora
sudo pacman -S gcc          # Arch
```

Build and run:

```sh
gcc rosary.c -o rosary
./rosary
```

Or use the included script: `./run.sh`

### macOS

Install Apple's command-line tools (this provides `cc`/`clang`, which is also
reachable as `gcc`):

```sh
xcode-select --install
```

Build and run:

```sh
cc rosary.c -o rosary
./rosary
```

`./run.sh` also works.

### Windows

**Option A: MinGW-w64 (gcc).** Install it with
[MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-ucrt-x86_64-gcc`) or
`winget install BrechtSanders.WinLibs.POSIX.UCRT`. Then, in a terminal:

```bat
gcc rosary.c -o rosary.exe
rosary.exe
```

**Option B: Visual Studio (MSVC).** Install "Build Tools for Visual Studio" with
the *Desktop development with C++* workload. Open the **Developer Command
Prompt** and run:

```bat
cl rosary.c
rosary.exe
```

**Option C: WSL.** Inside WSL, follow the Linux steps above.

## Options

Pass one argument to choose the mysteries:

```sh
./rosary        # today's mysteries
./rosary 0      # Joyful
./rosary 1      # Luminous
./rosary 2      # Sorrowful
./rosary 3      # Glorious
./rosary 4      # all four sets (20 decades)
```

(On Windows, use `rosary.exe 2` and so on.)

It's long, so page through it or save it:

```sh
./rosary | less            # Linux / macOS
./rosary > rosary.txt
```

```bat
rosary.exe | more          :: Windows
rosary.exe > rosary.txt
```

### Default mysteries by day

| Day               | Mysteries |
|-------------------|-----------|
| Monday, Saturday  | Joyful    |
| Tuesday, Friday   | Sorrowful |
| Wednesday, Sunday | Glorious  |
| Thursday          | Luminous  |

## What it prints

1. Sign of the Cross
2. Apostles' Creed
3. Our Father
4. 3 Hail Marys
5. Glory Be
6. 5 decades, each: the mystery, Our Father, 10 Hail Marys, Glory Be, Fatima Prayer
7. Hail, Holy Queen
8. Closing prayer
9. Sign of the Cross

## How it works

All the repetition goes through one recursive function. There are no loops:

```c
void r(int n,void(*f)(int)){if(n)r(n-1,f),f(n);}
```

`r(n,f)` calls `f(1)` through `f(n)` in order. It's used for the 3 opening
Hail Marys (`r(3,h)`), the 10 Hail Marys in each decade (`r(10,h)`), the
5 decades (`r(5,d)`), and all four sets of mysteries (`r(4,g)`).
