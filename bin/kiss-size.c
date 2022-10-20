/* kiss-size.c
 * Print the size of each file owned by a package and the total size used
 * by the package in B, KB, or MB.
 *
 * Written by phoebos, 2022.
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#define _POSIX_C_SOURCE
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define PKGDB "/var/db/kiss/installed/"

int
main(int argc, char **argv) {
    FILE *f;
    char *pkg = argv[1];
    char pkg_mani[PATH_MAX] = {'\0'};
    char tmp[PATH_MAX] = {'\0'};
    char prefix[2] = {'\0'};
    char *kiss_root, *buf = NULL;
    size_t buflen = 0;
    ssize_t n, total = 0;

    if (argc == 1) {
        /* get package name from PWD */
        char *s;
        if (getcwd(tmp, PATH_MAX) == NULL) {
            perror("getcwd");
            return 1;
        }
        s = strrchr(tmp, '/');
        if (s == NULL)
            s = tmp - 1;
        pkg = s + 1;
    }

    kiss_root = getenv("KISS_ROOT");
    if (kiss_root)
        strcpy(pkg_mani, kiss_root);

    strcat(pkg_mani, PKGDB);
    strcat(pkg_mani, pkg);
    strcat(pkg_mani, "/manifest");
    f = fopen(pkg_mani, "r");
    if (f == NULL) {
        fprintf(stderr, "ERROR: '%s' not found\n", pkg);
        return 1;
    }

    if (tmp[0])
        tmp[0] = '\0';
    while ((n = getline(&buf, &buflen, f)) != -1) {
        struct stat sb;
        off_t size;

        /* remove directories, which end with a '/' */
        if (buf[n-2] == '/')
            continue;

        if (buf[n-1] == '\n')
            buf[n-1] = '\0';

        if (kiss_root != NULL) {
            strcpy(tmp, kiss_root);
            strcat(tmp, buf);
        }

        if (lstat(kiss_root ? tmp : buf, &sb) == -1) {
            perror(kiss_root ? tmp : buf);
            continue;
        }

        prefix[0] = '\0';
        size = sb.st_size;
        if (size > 1023) {
            size >>= 10;
            prefix[0] = 'K';
            if (size > 1023) {
                size >>= 10;
                prefix[0] = 'M';
            }
        }

        printf("%zu%sB\t%s\n", size, prefix[0] ? prefix : "", kiss_root ? tmp : buf);
        total += sb.st_size;
    }

    prefix[0] = '\0';
    if (total > 1023) {
        total >>= 10;
        prefix[0] = 'K';
        if (total > 1023) {
            total >>= 10;
            prefix[0] = 'M';
        }
    }
    fprintf(stderr, "%zu%sB\ttotal\n", total, prefix[0] ? prefix : "");
    free(buf);
    fclose(f);

    return 0;
}
