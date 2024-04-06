#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef cJSON__h
#include "dependencies/cJSON.h"
#undef cJSON__h
#endif
#include "io/io.h"
#include "json_types/json_types.h"
#include "cxpathjson/declaration.h"
#include "extra/extra.h"
#include "namespace/declaration.h"