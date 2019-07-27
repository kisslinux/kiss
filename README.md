# kiss

Tiny package manager for KISS Linux.


## Package format

See: <https://getkiss.org/pages/package-system/>


## Getting started

Add these to your `shellrc`.

```sh
# The location to install packages (Optional).
# Default: /
export KISS_ROOT=~/.kiss
```

## Usage

```sh
➜ kiss
=> kiss [b|c|d|i|l|m|o|r|s|u] [pkg] [pkg] [pkg]
=> build:     Build a package.
=> checksum:  Generate checksums.
=> depends:   List package dependencies.
=> install:   Install a package (Runs build if needed).
=> list:      List installed packages.
=> manifest:  List package files owned by package.
=> owns:      Check which package owns a file.
=> remove:    Remove a package.
=> search:    Search for a package.
=> update:    Check for updates.
```
