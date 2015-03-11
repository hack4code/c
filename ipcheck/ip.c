#include <stdlib.h>
#include <assert.h>

int check_ip(const char *ip) {
        const char *s, *e = ip;
        int n = 0;

        for (;;) {
                int w;

                s = e;
                for ( ; *e && *e != '.'; e++)
                        if (*e < '0' || *e > '9')
                                return 0;
                w = e - s;
                if ((w > 1) && *s == '0')
                        return 0;
                if (w > 3 || w == 0)
                        return 0;
                if (w == 3) {
                        if (*s > '2')
                                return 0;
                        if (*s == '2') {
                                if (*(s+1) > '5')
                                        return 0;
                                if ((*(s+1) == '5') && (*(s+2) > '5'))
                                        return 0;
                        }
                }
                if (++n > 4)
                        return 0;
                if (*e == '\0')
                        break;
                e++;
        }

        if (n != 4)
                return 0;

        return 1;
}


int main(int argc, char *argv[]) {
        assert(check_ip("1.1.1.1") == 1);
        assert(check_ip("1.1.1") == 0);
        assert(check_ip("192.168.1.1") == 1);
        assert(check_ip("192.256.1.1") == 0);
        assert(check_ip("192.256.01.1") == 0);
}
