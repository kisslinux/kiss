# kiss

Tiny and straightforward package manager for KISS written in POSIX `sh`.

- Only 600~ lines of POSIX `sh` (See [cloc](#cloc)).
- Runtime dependency detection.
- Incremental package installation.
- Fast dependency solver.
- File conflict detection.
- Package alternatives system.
- Binary stripping.
- `shellcheck` compliant.


## `kiss` Guidestones

Read: https://k1ss.org/guidestones.txt

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

## Index

<!-- vim-markdown-toc GFM -->

* [Package format](#package-format)
* [Extending the package manager](#extending-the-package-manager)
* [cloc](#cloc)

<!-- vim-markdown-toc -->


## Package format

See: <https://k1ss.org/package-system>


## Extending the package manager

The `contrib` directory contains a set of simple scripts to extend the package manager. These are just simple and stupid automations which parse the package format.

- `kiss-cargo-urlgen`: Generate sources for rust packages.
- `kiss-chbuild`: Spawn a throwaway chroot.
- `kiss-chroot`: Enter a KISS `chroot`.
- `kiss-depends-finder`: Find missing dependencies by parsing 'ldd'.
- `kiss-depends`: Display a package's dependencies.
- `kiss-export`: Turn an installed package into a KISS tarball.
- `kiss-fork`: Copy a package's repository files into the current directory.
- `kiss-link`: Link a repository file to another repository.
- `kiss-manifest-tree`: Display all files as tree owned by a package.
- `kiss-manifest`: Display all files owned by a package.
- `kiss-maintainer`: Display the package maintainers.
- `kiss-new`: Create a boilerplate package.
- `kiss-orphans`: List orphaned packages.
- `kiss-outdated`: List outdated packages based on Repology versions.
- `kiss-owns`: Check which package owns a file.
- `kiss-repodepends`: Display a package's original dependencies.
- `kiss-reset`: Reset the system to the base.
- `kiss-revdepends`: Display packages which depend on package.
- `kiss-size`: Show the size on disk for an installed package.


## cloc

```
+---------------------------------------+
| Language  files  blank  comment  code |
|---------------------------------------|
| Shell     1      287    408       693 |
+---------------------------------------+
```
