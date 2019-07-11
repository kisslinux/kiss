# kiss

Tiny package manager for KISS Linux.


## Table of Contents

<!-- vim-markdown-toc GFM -->

* [Package format](#package-format)
* [Dependencies](#dependencies)
* [Getting started](#getting-started)
* [Usage](#usage)
* [How does each operator work?](#how-does-each-operator-work)
    * [`kiss build pkg`](#kiss-build-pkg)
    * [`kiss checksum pkg`](#kiss-checksum-pkg)
    * [`kiss install pkg`](#kiss-install-pkg)
    * [`kiss remove pkg`](#kiss-remove-pkg)
    * [`kiss list` or `kiss list pkg`](#kiss-list-or-kiss-list-pkg)
    * [`kiss update`](#kiss-update)

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

## How does each operator work?

### `kiss build pkg`

Kiss's `build` operator handles a package from its source code to the installable `.tar.gz` file. Sources are downloaded, checksums are verified, dependencies are checked and the package is compiled then packaged.

### `kiss checksum pkg`

Kiss's `checksum` operator generates the initial checksums for a package from every source in the `sources` file.

### `kiss install pkg`

Kiss's `install` operator takes the built `.tar.gz` file and installs it in the system. This is as simple as removing the old version of the package (*if it exists*) and unpacking the archive at `/`.

### `kiss remove pkg`

Kiss's `remove` operator uninstalls a package from your system. Files and directories in `/etc` are untouched. Support for exclusions will come as they are needed.

### `kiss list` or `kiss list pkg`

Kiss's `list` operator lists the installed packages and their versions. Giving `list` an argument will check if a singular package is installed.

### `kiss update`

Kiss's `update` operator compares the repository versions of packages to the installed database versions of packages. Any mismatch in versions is considered a new upgrade from the repository.
