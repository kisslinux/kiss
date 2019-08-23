# kiss

Tiny package manager for KISS written in POSIX `sh`.


## Package format

See: <https://getkiss.org/pages/package-system/>


## Usage

```sh
➜ kiss
=> kiss [b|c|i|l|r|s|u] [pkg] [pkg] [pkg]
=> build:     Build a package.
=> checksum:  Generate checksums.
=> install:   Install a package.
=> list:      List installed packages.
=> remove:    Remove a package.
=> search:    Search for a package.
=> update:    Check for updates.
```

## Extending the package manager.

See: https://github.com/kisslinux/kiss-utils
