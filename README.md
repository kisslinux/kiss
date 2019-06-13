# kiss

Tiny package manager for KISS Linux.

**NOTE:** I am in the process of adding multi-repository support and the package manager is currently in a non-working state. Once this feature is added things will work as normal.


## Package format

See: <https://github.com/kissx/packages>


## Getting started with `kiss`

Kiss has 6 different "operators".

- `build`: Build a package.
- `checksum`: Generate checksums for a package.
- `install`: Install a built package.
- `remove`: Remove an installed package.
- `list`: List installed packages.
- `update`: List packages with available updates.

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

The `update` mechanism doesn't do a `git pull` of the repository. This must be done manually beforehand and is intentional. It allows the user to `git pull` selectively. You can slow down the distribution's package updates by limiting pulling to a week behind master for example.


