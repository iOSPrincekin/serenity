#!/usr/bin/env -S bash ../.port_include.sh
port=php
useconfigure="true"
version="8.0.10"
files="https://www.php.net/distributions/php-${version}.tar.xz php-${version}.tar.xz 66dc4d1bc86d9c1bc255b51b79d337ed1a7a035cf71230daabbf9a4ca35795eb"
auth_type=sha256
depends="libiconv libxml2 openssl readline sqlite zlib"
configopts="
    --disable-cgi
    --disable-opcache
    --enable-fpm
    --prefix=${SERENITY_INSTALL_ROOT}/usr/local
    --with-iconv=${SERENITY_INSTALL_ROOT}/usr/local
    --with-openssl
    --with-readline=${SERENITY_INSTALL_ROOT}/usr/local
    --with-zlib
    --without-pcre-jit
"
launcher_name="PHP"
launcher_category="Development"
launcher_command="/usr/local/bin/php -a"
launcher_run_in_terminal="true"
icon_file="win32/build/php.ico"

export CFLAGS="-I${SERENITY_INSTALL_ROOT}/usr/local/include/libxml2"
export LIBS="-ldl"
export LIBXML_CFLAGS="y"
export LIBXML_LIBS="-lxml2"
export OPENSSL_CFLAGS="y"
export OPENSSL_LIBS="-lssl -lcrypto"
export SQLITE_CFLAGS="y"
export SQLITE_LIBS="-lsqlite3 -lpthread"
export ZLIB_CFLAGS="y"
export ZLIB_LIBS="-lz"
