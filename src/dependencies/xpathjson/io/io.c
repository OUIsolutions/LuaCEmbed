



char *private_cxpathjson_read_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);


    char *buffer = (char *)malloc(file_size + 1);


    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);
    return buffer;
}

int  private_cxpathjson_write_file(const char *filename, const char *value) {

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        return CXPATHJSON_IO_PROBLEM_CODE;
    }
    fputs(value, file);

    fclose(file);
    return CXPATHJSON_OK_CODE;
}

