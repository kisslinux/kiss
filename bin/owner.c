/* owner.c
 * Print the username of the owner of the path supplied as the first argument.
 * Follows symbolic links (using stat(3)).
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

#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>

int
main(int argc, char **argv) {
    struct stat sb;
    struct passwd *pw;
    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return 1;
    }
    if (stat(argv[1], &sb) != 0) {
        perror(argv[1]);
        return 1;
    }
    pw = getpwuid(sb.st_uid);
    if (pw == NULL) {
        fprintf(stderr, "%s: %s: owner name not found\n", argv[0], argv[1]);
        return 1;
    }
    printf("%s\n", pw->pw_name);
    return 0;
}
