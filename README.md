# kiss

Tiny package manager for KISS Linux.


## Table of Contents

<!-- vim-markdown-toc GFM -->

* [Package format](#package-format)
* [Dependencies](#dependencies)
* [Getting started](#getting-started)
* [Usage](#usage)

<!-- vim-markdown-toc -->


## Package format

See: <https://github.com/kissx/packages>


## Dependencies

POSIX `coreutils`:

- `cmp`
- `command`
- `cp`
- `find`
- `mkdir`
- `rm`
- `rmdir`
- `sed`
- `sh`

Other utilities:

- `file`
- `git`
- `rsync`
- `sha256sum` (Included in default `busybox`)
- `strip`
- `tar` (Included in default `busybox`)
- `wget`(Included in default `busybox`)

## Getting started

Add these to your `shellrc`.

```sh
# The location to install packages (Optional).
# Default: /
export KISS_ROOT=~/.kiss

# Repositories to use (Required).
# Colon separated like '$PATH'.
# Repositories will be search in order.
# Default:
export KISS_PATH=~/projects/kiss-new/repo
```

## Usage

```sh
➜ kiss
=> kiss [b|c|i|l|r|u] [pkg]
=> build:     Build a package.
=> checksum:  Generate checksums.
=> install:   Install a package (Runs build if needed).
=> list:      List packages.
=> remove:    Remove a package.
=> update:    Check for updates.
```
