#!/bin/sh

# Note: OS X regex library does not support \+ or \?
TEST_DECL_PATTERN="^[ \t]*\(int\)[ \t]*\(test[a-zA-Z0-9_]*\)[ \t]*[(][ \t]*\(void\)*[ \t]*[)][ \t]*.*"

MAIN_C="main.c"

while test -n "$1"; do
  if test "x$1" = "x-o"; then
    shift 1
    MAIN_C="$1"
  elif test -f "$1"; then
    FILES="${FILES} $1"
  else
    echo "$0: no such file or directory: $1" >&2
  fi
  shift 1
done

if test -z "${FILES}"; then
  FILES="$(find . -name "*.c" -not -name "${MAIN_C}")"
fi

exec >"${MAIN_C}"

echo "#include <stdio.h>"
echo "#include \"midi/midi.h\""
echo "#define NL ((char)0x0a)"
sed "s/${TEST_DECL_PATTERN}/extern \1 \2( void );/p;d" ${FILES}
echo "int main( int argc, char *argv[] ) {"
echo "  int i, failures = 0;"
echo "  struct {"
echo "    char * name;"
echo "    int (*func)(void);"
echo "  } tests[] = {"
sed "s/${TEST_DECL_PATTERN}/    { \"\2\", \&\2 },/p;d" ${FILES}
echo "  };"
echo "  for( i=0; i<(sizeof(tests)/sizeof(tests[0])); i++ ) {"
echo "    printf( \"> Running %s%c\", tests[i].name, NL );"
echo "    if( (tests[i].func)() ) {"
echo "      failures++;"
echo "      printf( \"> Test %s failed.%c\", tests[i].name, NL );"
echo "    } else {"
echo "      printf( \"> Test %s passed.%c\", tests[i].name, NL );"
echo "    }"
echo "  }"
echo "  return failures;"
echo "}"

exec >&-
