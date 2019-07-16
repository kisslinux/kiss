# kiss

Tiny package manager for KISS Linux.


## Package format

See: <https://kissx.github.io/pages/package-system/>


## Getting started

Add these to your `shellrc`.

```sh
# The location to install packages (Optional).
# Default: /
export KISS_ROOT=~/.kiss

# Repositories to use (Required).
# Colon separated like '$PATH'.
# Repositories will be search in order.
# Default: ''
export KISS_PATH=/packages/core:/packages/extra:/packages/xorg:/packages/public
```

## Usage

```sh
➜ kiss
=> kiss [b|c|d|i|l|r|s|u] [pkg] [pkg] [pkg]
=> build:     Build a package.
=> checksum:  Generate checksums.
=> depends:   List package dependencies.
=> install:   Install a package (Runs build if needed).
=> list:      List packages.
=> remove:    Remove a package.
=> search:    Search for a package.
=> update:    Check for updates.
```
