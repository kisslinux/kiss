PREFIX=/usr
MANPREFIX=${PREFIX}/share/man

UTILS = kiss-chroot kiss-depends kiss-depends-finder kiss-export kiss-maintainer \
	kiss-manifest kiss-manifest-tree kiss-orphans kiss-owns kiss-repodepends \
	kiss-reset kiss-revdepends kiss-size

install:
	@install -Dm755 kiss ${DESTDIR}${PREFIX}/bin/kiss
	@install -Dm644 kiss.1 ${DESTDIR}${MANPREFIX}/man1/kiss.1

install-utils:
	@for util in ${UTILS} ; do \
		install -Dm755 "contrib/$$util" "${DESTDIR}${PREFIX}/bin/$$util" ; done

uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/kiss
	@rm -f ${DESTDIR}${MANPREFIX}/man1/kiss.1

uninstall-utils:
	@for util in ${UTILS} ; do \
		rm -f ${DESTDIR}${PREFIX}/bin/$$util ; done

.PHONY: install install-utils uninstall uninstall-utils
