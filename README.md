# kiss

Tiny and straightforward package manager for KISS written in POSIX `sh`.

- Only 500~ lines of POSIX `sh` (*excluding blank lines and comments*).
- Runtime dependency detection.
- Incremental package installation.
- Fast dependency solver.
- File conflict detection.
- Binary stripping.
- `shellcheck` compliant.

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

## Package format

See: <https://getkiss.org/pages/package-system/>


## Customization

```sh
# The package manager is controlled through environment variables.
#
# These can be set in your '.profile' or '/etc/profile.d' to have
# the options apply all the time.
#
# These can also be set in the current shell to have them apply
# only for the current session.
#
# NOTE: The values shown below are the defaults.

# Managing repositories.
#
# This works exactly like '$PATH' (Colon separated).
#
# A list of repositories the package manager will use. You can
# add your own repositories or remove the default ones.
export KISS_PATH=/var/db/kiss/repo/core:/var/db/kiss/repo/extra:/var/db/kiss/repo/xorg

# Delete junk from packages.
#
# This works exactly like '$PATH' (Colon separated).
#
# A list of paths and files to remove from built packages.
#
# Set this to a blank value to keep all of the below files
# and directories around. This can be customized to keep or
# remove whatever you like.
export KISS_RM=usr/share/doc:usr/share/gtk-doc:usr/share/info:usr/share/polkit-1:usr/share/gettext:usr/share/locale:etc/bash_completion.d:usr/share/zsh

# Force package installation or removal.
#
# This can be used to bypass the dependency checks on installation
# and removal of packages.
#
# Set it to '1' to force.
export KISS_FORCE=0

# Root directory.
#
# Where installed packages will go. You won't ever need
# to touch this during normal usage.
#
# This can be used to have the package manager run in a "fake root".
export KISS_ROOT=/

# Keep build, package and extraction cache directories for debugging
# purposes.
#
# Set it to '1' to enable.
export KISS_DEBUG=0

# Use a reproducible cache naming scheme.
#
# The package manager builds packages inside 'build-$PID/' with '$PID'
# being the package manager's process ID. This allows for multiple
# builds to happen at once.
#
# You can override this and _know_ the location beforehand with the
# below environment variable. 'KISS_PID=test' will build the package
# in 'build-test'.
#
# Unset by default.
export KISS_PID=


#
# non-package-manager related options.
# These are listed for clarity.
#


# Cache directory location.
export XDG_CACHE_HOME=$HOME/.cache/

# Compiler.
export CC=gcc
export CXX=g++

# AR.
export AR=ar

# NM.
export NM=nm

# RANLIB.
export RANLIB=ranlib

# Compiler flags.
# Good value: CFLAGS/CXXFLAGS='-march=native -pipe -O2'
export CFLAGS=
export CXXFLAGS=

# Linker flags.
export LDFLAGS=

# Make flags.
# Good value: MAKEFLAGS='-j 4' (number of cores).
export MAKEFLAGS=
```

## Extending the package manager

The `contrib` directory contains a set of simple scripts to extend the package manager.

- `kiss-chroot`: Enter a KISS `chroot`.
- `kiss-depends-finder`: Find missing dependencies by parsing 'ldd'.
- `kiss-depends`: Display a package's dependencies.
- `kiss-export`: Turn an installed package into a KISS tarball.
- `kiss-manifest-tree`: Display all files as tree owned by a package.
- `kiss-manifest`: Display all files owned by a package.
- `kiss-maintainer`: Display the package maintainers.
- `kiss-orphans`: List orphaned packages.
- `kiss-owns`: Check which package owns a file.
- `kiss-revdepends`: Display packages which depend on package.
- `kiss-size`: Show the size on disk for an installed package.
