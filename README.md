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


## Extending the package manager.

See: https://github.com/kisslinux/kiss-utils


