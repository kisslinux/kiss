# kiss

Tiny and straightforward package manager for KISS written in POSIX `sh`.

- Less than 1000 lines of POSIX `sh` (excluding blank lines and comments).
- Highly portable (will run in any POSIX compliant environment).
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

| dependency      | why                          | mandatory?        |
| --------------- | ---------------------------- | ----------------- |
| POSIX utilities | Used throughout              | Yes               |
| `git`           | Repositories and git sources | Yes               |
| `gnupg1` or `gnupg2` | Repository signing      | No (optional)     |
| `curl`          | Source downloads             | Yes               |
| `sha256sum`, `shasum`, `sha256` or `openssl` | Checksum verification | Yes |
| `tar`           | Tarball creation/extraction  | Yes               |
| `bzip2`         | Compression method.          | Yes (widely used) |
| `xz`            | Compression method.          | Yes (widely used) |
| `gzip`          | Compression method.          | Yes (widely used) |
| `zstd`          | Compression method.          | No  (rarely used) |
| `lzma`          | Compression method.          | No  (rarely used) |
| `lzip`          | Compression method.          | No  (rarely used) |
| `unzip`         | Source type.                 | No  (rarely used) |
| `su`, `sudo` or `doas` | Privilege escalation. | No  (optional)    |
| `ldd`           | Automatic dependency fixer.  | No  (optional)    |
| `readelf` and `strip` | Binary stripping       | No  (optional)    |


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
