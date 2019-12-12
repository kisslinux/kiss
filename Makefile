PREFIX=/usr
MANPREFIX=${PREFIX}/share/man

install:
	@install -Dm755 kiss ${DESTDIR}${PREFIX}/bin/kiss
	@install -Dm644 kiss.1 ${DESTDIR}${MANPREFIX}/man1/kiss.1

install-utils:
	@install -Dm755 contrib/kiss-manifest ${DESTDIR}${PREFIX}/bin/kiss-manifest
	@install -Dm755 contrib/kiss-chroot ${DESTDIR}${PREFIX}/bin/kiss-chroot
	@install -Dm755 contrib/kiss-reset ${DESTDIR}${PREFIX}/bin/kiss-reset
	@install -Dm755 contrib/kiss-repodepends ${DESTDIR}${PREFIX}/bin/kiss-repodepends
	@install -Dm755 contrib/kiss-depends-finder ${DESTDIR}${PREFIX}/bin/kiss-depends-finder
	@install -Dm755 contrib/kiss-export ${DESTDIR}${PREFIX}/bin/kiss-export
	@install -Dm755 contrib/kiss-manifest-tree ${DESTDIR}${PREFIX}/bin/kiss-manifest-tree
	@install -Dm755 contrib/kiss-maintainer ${DESTDIR}${PREFIX}/bin/kiss-maintainer
	@install -Dm755 contrib/kiss-orphans ${DESTDIR}${PREFIX}/bin/kiss-orphans
	@install -Dm755 contrib/kiss-revdepends ${DESTDIR}${PREFIX}/bin/kiss-revdepends
	@install -Dm755 contrib/kiss-owns ${DESTDIR}${PREFIX}/bin/kiss-owns
	@install -Dm755 contrib/kiss-size ${DESTDIR}${PREFIX}/bin/kiss-size
	@install -Dm755 contrib/kiss-depends ${DESTDIR}${PREFIX}/bin/kiss-depends

uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss
	@rm -f ${DESTDIR}${MANPREFIX}/man1/kiss.1

uninstall-utils:
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-chroot
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-depends
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-depends-finder
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-export
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-maintainer
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-manifest
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-manifest-tree
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-orphans
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-owns
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-repodepends
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-reset
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-revdepends
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss-size

.PHONY: install install-utils uninstall uninstall-utils
