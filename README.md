# kiss

Tiny and straightforward package manager for KISS written in POSIX `sh`.

- Only 500~ lines of POSIX `sh` (*excluding blank lines and comments*).
- Runtime dependency detection.
- Incremental package installation.
- Fast dependency solver.
- File conflict detection.
- Package alternatives system.
- Binary stripping.
- `shellcheck` compliant.

## Usage

```sh
➜ kiss
-> kiss [a|b|c|i|l|r|s|u|v] [pkg] [pkg] [pkg]
-> alternatives: List and swap to alternatives
-> build:        Build a package
-> checksum:     Generate checksums
-> install:      Install a package
-> list:         List installed packages
-> remove:       Remove a package
-> search:       Search for a package
-> update:       Check for updates
-> version:      Package manager version
```

## Index

<!-- vim-markdown-toc GFM -->

* [Package format](#package-format)
* [Customization](#customization)
* [Alternatives system](#alternatives-system)
* [Extending the package manager](#extending-the-package-manager)

<!-- vim-markdown-toc -->


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

# Hook into kiss through a script.
#
# This can be used set custom CFLAGS per package, modify builds,
# etc. This environment variable must point to a shellscript.
#
# The script will have the following environment variables set.
#
# $PKG:  Name of the current package .
# $TYPE: The type of hook (valid: pre-build, post-build).
# $DEST: The full path to where 'make install' will put the package.
#
# Simple example script:
#
# case $TYPE in
#     pre-build)
#         case $PKG in
#            zlib) export CFLAGS="-Os -static" ;;
#            curl) export CFLAGS="-O3" ;;
#         esac
#     ;;
#
#     post-build)
#         # post-build code here.
#     ;;
# esac
#
export KISS_HOOK=/path/to/script

# Root directory.
#
# Where installed packages will go. You won't ever need
# to touch this during normal usage.
#
# This can be used to have the package manager run in a "fake root".
export KISS_ROOT=/

# Keep build logs around for successful builds and not just failing
# ones. Helpful when debugging.
#
# Set it to '1' to enable.
export KISS_DEBUG=0

# Force the usage of a different 'sudo' tool.
#
# Values: 'su', 'sudo', 'doas'
export KISS_SU=

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
# Good value: MAKEFLAGS='-j4' (number of cores).
export MAKEFLAGS=

# Ninja (Samurai) flags.
# Good value: SAMUFLAGS='-j4' (number of cores).
export SAMUFLAGS=

# Cmake Generator.
# Good value (Ninja):     export CMAKE_GENERATOR='Ninja'
# Good value (Makefiles): export CMAKE_GENERATOR='Unix Makefiles'
export CMAKE_GENERATOR=
```

## Alternatives system

When a package with conflicts is installed with `KISS_CHOICE=1`, the conflicting files will be added as "choices" to the alternatives system.

Afterwards, running `kiss a`/`kiss alternatives` will list all of the choices you are able to make. Each line of output with this command is also usable directly as input.

**NOTE** If a package has fewer than 10 conflicting files, the conflicting files will automatically be added to the alternatives system.

Example usage:

```sh
# List alternatives.
-> kiss a
-> Alternatives:
ncurses /usr/bin/clear
ncurses /usr/bin/reset

# Swap to ncurses 'clear'.
-> kiss a ncurses /usr/bin/clear
-> Swapping '/usr/bin/clear' from 'busybox' to 'ncurses'
Password:

# New listing (busybox clear was swapped out).
-> kiss a
-> Alternatives:
busybox /usr/bin/clear
ncurses /usr/bin/reset
```

Example usage (complex):

```sh
-> kiss i sbase
# More lines...
/var/db/kiss/installed/util-linux/manifest:/usr/bin/renice
/var/db/kiss/installed/util-linux/manifest:/usr/bin/logger
/var/db/kiss/installed/util-linux/manifest:/usr/bin/flock
/var/db/kiss/installed/util-linux/manifest:/usr/bin/cal
!> Package 'sbase' conflicts with another package
!> Run 'KISS_CHOICE=1 kiss i sbase' to add conflicts
!> as alternatives.

# There were more than 10 conflicts so the alternatives system
# must be manually enabled for this package.
-> KISS_CHOICE=1 kiss i sbase
# More lines...
-> sbase Found conflict (/usr/bin/renice), adding choice
-> sbase Found conflict (/usr/bin/logger), adding choice
-> sbase Found conflict (/usr/bin/flock), adding choice
-> sbase Found conflict (/usr/bin/cal), adding choice
-> sbase Installing package incrementally
-> sbase Installed successfully

# List alternatives.
-> kiss a
-> Alternatives:
# More lines...
sbase /usr/bin/uuencode
sbase /usr/bin/wc
sbase /usr/bin/which
sbase /usr/bin/whoami
sbase /usr/bin/xargs
sbase /usr/bin/yes

# Swapping in bulk (all of sbase).
# The 'kiss a' command with '-' as an argument will read
# from stdin and use each line as arguments to 'kiss a'.
kiss a | grep ^sbase | kiss a -

# New listing, sbase has replaced busybox utilities.
-> kiss a
-> Alternatives:
# More lines...
busybox /usr/bin/uuencode
busybox /usr/bin/wc
busybox /usr/bin/which
busybox /usr/bin/whoami
busybox /usr/bin/xargs
busybox /usr/bin/yes
```

## Extending the package manager

The `contrib` directory contains a set of simple scripts to extend the package manager. These scripts can be installed through the `kiss-utils` package.

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
