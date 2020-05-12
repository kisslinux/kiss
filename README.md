# kiss

Tiny and straightforward package manager for KISS written in POSIX `sh`.

- Less than 1000 lines of POSIX `sh` (excluding blank lines and comments).
- Runtime dependency detection.
- Incremental package installation.
- Fast dependency solver.
- File conflict detection.
- Package alternatives system.
- 3-way handshake for /etc/ configuration files.
- Binary stripping.
- `shellcheck` compliant.


## Usage

```sh
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

## Dependencies / Portability

```sh
# - Anything with a specification should follow it (POSIX, BSD, etc).
# - Anything without a specification which has ONLY a single (widely used)
#   implementation will be considered portable (git, curl, etc).
#
#   POSIX utilities
#   - sh        (POSIX)
#   - find      (POSIX) -type f, -type d, -exec {} [+;], -o, -print, !
#   - ls        (POSIX) -l, -d
#   - sed       (POSIX) -n, s/<search>/<replace>/g, /<delete>/d
#   - grep      (POSIX) -l, -F, -x, -f, -q, -v
#   - sort      (POSIX) -r, -u, -k
#   - tee       (POSIX) -a
#   - date      (POSIX)
#   - mkdir     (POSIX) -p
#   - rm        (POSIX) -f, -r
#   - rmdir     (POSIX)
#   - cp        (POSIX) -f, -P, -p, -L, -R
#   - mv        (POSIX) -f
#   - chown     (POSIX) -h
#   - diff      (POSIX) -U
#
#   Misc
#   - su*       (sudo, doas, su) (in order, optional)
#   - git       (downloads from git) (must link to curl)
#   - curl      (downloads over http) (also needed by git)
#   - sha256    (multiple fallbacks: sha256sum, shasum, sha256, openssl, etc)
#
#   Compiler/libc utilities (depends cc & libc)
#   - readelf   (optional) (Part of compiler toolchain) (GNU, LLVM or elfutils)
#   - strip     (optional) (Part of compiler toolchain) (GNU, LLVM or elfutils)
#   - ldd       (optional) (Part of libc)
#
#   Tarball compression
#   - tar       (as portable as can be) (merely: cf, tf, xf)
#   - bzip2     (widely used) -d, -z
#   - xz        (widely used) -d, -z, -c, -T
#   - gzip      (widely used) -d, -6
#   - zstd      (optional)    -d, -z, -c
#   - unzip     (optional)
#   - lzma      (optional)
#   - lzip      (optional)
```

## Package format

See: <https://k1ss.org/package-system>


## Extending the package manager

The `contrib` directory contains a set of simple scripts to extend the package manager. These are just simple and stupid automations which parse the package format.

- `kiss-chbuild`: Spawn a throwaway chroot.
- `kiss-chroot`: Enter a KISS `chroot`.
- `kiss-depends`: Display a package's dependencies.
- `kiss-export`: Turn an installed package into a KISS tarball.
- `kiss-fork`: Copy a package's repository files into the current directory.
- `kiss-link`: Link a repository file to another repository.
- `kiss-manifest`: Display all files owned by a package.
- `kiss-maintainer`: Display the package maintainers.
- `kiss-new`: Create a boilerplate package.
- `kiss-orphans`: List orphaned packages.
- `kiss-outdated`: List outdated packages based on Repology versions.
- `kiss-owns`: Check which package owns a file.
- `kiss-reset`: Reset the system to the base.
- `kiss-revdepends`: Display packages which depend on package.
- `kiss-size`: Show the size on disk for an installed package.
